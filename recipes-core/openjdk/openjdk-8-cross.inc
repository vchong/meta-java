JDK_HOME = "${libdir_jvm}/openjdk-8"
JRE_HOME = "${libdir_jvm}/openjre-8"

DEPENDS = "\
    openjdk-8-native zip-native ant-native libxslt \
    jpeg libpng krb5 libffi fontconfig freetype \
"

PRIVATE_LIBS = "\
    libattach.so libawt_headless.so libawt.so libawt_xawt.so libdt_socket.so \
    libfontmanager.so libhprof.so libinstrument.so libj2gss.so libj2pcsc.so \
    libj2pkcs11.so libjaas_unix.so libjava_crw_demo.so libjava.so libjawt.so \
    libjdwp.so libjli.so libjpeg.so libjsdt.so libjsig.so libjvm.so liblcms.so \
    libmanagement.so libmlib_image.so libnet.so libnio.so libnpt.so libsaproc.so \
    libsctp.so libsplashscreen.so libsunec.so libunpack.so libverify.so libzip.so \
"

PACKAGECONFIG ??= "repack"
PACKAGECONFIG[x11] = "--with-x,,libx11 xproto libxt libxext libxrender"
PACKAGECONFIG[cups] = "--with-cups,,cups"
PACKAGECONFIG[alsa] = "--with-alsa,,alsa-lib-native"

PACKAGECONFIG[jce] = "--enable-unlimited-crypto,,"

PACKAGECONFIG[zip] = "--with-zlib=system,--with-zlib=bundled,zlib,"
PACKAGECONFIG[gif] = "--with-giflib=system,--with-giflib=bundled,giflib,"

export WANT_LLVM_RELEASE = "3.5.2"
PACKAGECONFIG[zero] = "--with-jvm-variants=zero,,,"
PACKAGECONFIG[shark] = "--with-jvm-variants=zeroshark,,llvm3.5,"
PACKAGECONFIG[client] = "--with-jvm-variants=client,,,"
PACKAGECONFIG[server] = "--with-jvm-variants=server,,,"

PACKAGECONFIG[repack] = ",,,"

require openjdk-8-common.inc

JAVA_HOME[unexport] = "1"

SRC_URI_append = "\
    file://jvm.cfg \
"

EXTRA_OECONF_append = "\
    --with-jobs=${@java_get_parallel_make(d)} \
    \
    --with-sys-root=${STAGING_DIR} \
    --with-tools-dir=${STAGING_DIR_NATIVE} \
    --with-boot-jdk=${STAGING_LIBDIR_NATIVE}/jvm/openjdk-8-native \
    --with-cacerts-file=${STAGING_LIBDIR_NATIVE}/jvm/openjdk-8-native/jre/lib/security/cacerts \
    \
    --disable-precompiled-headers \
    --disable-zip-debug-info \
    \
    --with-extra-cflags='${CFLAGS}' \
    --with-extra-cxxflags='${CXXFLAGS}' \
    --with-extra-ldflags='${LDFLAGS}' \
    \
    ${@jdk_configure_options(d)} \
"

do_configure_append() {
    sed -i -e 's,POST_STRIP_CMD:=.*,POST_STRIP_CMD:=,g' ${B}/spec.gmk
}

do_install_append() {
    if ${@bb.utils.contains('PACKAGECONFIG', 'repack', 'true', 'false', d)} ; then
      if [ -d ${D}${JDK_HOME} ] ; then
        find ${D}${JDK_HOME} -name "*.jar" -print0 | \
          xargs -0 -n1 -P ${@java_get_parallel_make(d)} sh -c ' \
              echo "Repacking" "$0" ; \
              pack200 --repack --effort=9 --segment-limit=-1 --modification-time=latest --strip-debug "$0"'
      fi
      if [ -d ${D}${JRE_HOME} ] ; then
        find ${D}${JRE_HOME} -name "*.jar" -print0 | \
          xargs -0 -n1 -P ${@java_get_parallel_make(d)} sh -c ' \
              echo "Repacking" "$0" ; \
              pack200 --repack --effort=9 --segment-limit=-1 --modification-time=latest --strip-debug "$0"'
      fi
    fi
}

export MAKE_VERBOSE = "y"
export MFLAGS="${@jdk_make_options(d)} MAKE_VERBOSE=y QUIETLY= VERBOSE=-s LOG_LEVEL=trace STRIP_POLICY=no_strip"

BUILD_LD="${BUILD_CCLD}"

EXTRA_OEMAKE_append = '\
    ${@jdk_make_options(d)} \
    ALT_SDT_H="${STAGING_INCDIR}" \
    ALT_CUPS_HEADERS_PATH="${STAGING_INCDIR}" \
    ALT_FREETYPE_HEADERS_PATH="${STAGING_INCDIR}/freetype2" \
    ALT_FREETYPE_LIB_PATH="${STAGING_LIBDIR}" \
    STRIP_POLICY=no_strip \
    MAKE_VERBOSE=y VERBOSE=-s LOG_LEVEL=trace \
    QUIETLY= \
    images \
'

# There is a symlink to a .so but this one is valid.
INSANE_SKIP_${PN} = "dev-so"
