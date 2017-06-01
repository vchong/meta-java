PATCHES_URI="\
    file://remove-shell-variables-from-autoheader.patch;striplevel=0 \
    file://filter-aclocal-copy-too.patch;striplevel=0 \
    file://dont-expect-fqpn-for-make.patch;striplevel=0 \
    file://openjdk8-no-genx11-in-headless.patch;apply=no \
    file://openjdk8-no-unused-deps.patch;apply=no \
    file://openjdk8-find-compiler-fix-env-respect.patch;apply=no \
    file://openjdk8-prevent-debuginfo-in-favour-of-openembedded-package-split.patch;apply=no \
"

# Name of the directory containing the compiled output
BUILD_DIR = "openjdk.build"
BUILD_DIR_ECJ = "openjdk.build-ecj"

# readdir_r was deprecated in glibc-2.24. Ignore the error for now
# NOTE: When updating the recipe, please check if this is still needed
CFLAGS_append = " -Wno-error=deprecated-declarations"

PACKAGECONFIG_append_aarch64 = " server"

CORBA_CHANGESET = "7ab076b30e78"
SRC_URI[corba.md5sum] = "87bc37faed4943d2d6fa9a60917c89b1"
SRC_URI[corba.sha256sum] = "b9ee752a25834117fa6b630ee192dfeca51dae620a7a9a7d9f3d166dbb78aa8d"

HOTSPOT_CHANGESET = "f4086f3a0d69"
SRC_URI[hotspot.md5sum] = "daa76d9efef7a2a53074ab85fab526aa"
SRC_URI[hotspot.sha256sum] = "14cee0a8886f26f9a3510ce864f517f42730f0f7f6b25ed700e4205e1038e013"

JAXP_CHANGESET = "87da19c7cc5f"
SRC_URI[jaxp.md5sum] = "ff5e5153f4a4d22c8474f75270ef5469"
SRC_URI[jaxp.sha256sum] = "5f0254c4617bd07baafc81d39f5353812beddaf0d4a691c1e28172c8d2207150"

JAXWS_CHANGESET = "2b6e5bb5844a"
SRC_URI[jaxws.md5sum] = "1dd46edd0a7b5c42b84c0975351ccf52"
SRC_URI[jaxws.sha256sum] = "32f2b586be0aa400bf008afe648439f78d8a85f3ef714b428814f56d605e47d7"

JDK_CHANGESET = "9ae547861e9f"
SRC_URI[jdk.md5sum] = "c49fe34ad70fe2982a6a29165776cdf2"
SRC_URI[jdk.sha256sum] = "4afc86685166b8e157830e86cc7391c1414ab50e0757ff351483032440a9f076"

LANGTOOLS_CHANGESET = "919a3c6bc315"
SRC_URI[langtools.md5sum] = "c1d400dc39d0dbbe9198c3e9e5ba3d6b"
SRC_URI[langtools.sha256sum] = "90259d5b0eb73baf0866b28e8e9c85b02e6e31ce05ced9869581c6eeab30b932"

NASHORN_CHANGESET = "9c1264a75e80"
SRC_URI[nashorn.md5sum] = "84574ca5aecfe4ab4e3e1113e839c827"
SRC_URI[nashorn.sha256sum] = "aff0169262901c3f706037df48d0a6281c20c89e59b442022bc05ee8290719b3"

OPENJDK_CHANGESET = "8e5c7286cd85"
SRC_URI[openjdk.md5sum] = "5f918d443650304de37a486c1bc31c5d"
SRC_URI[openjdk.sha256sum] = "352157ee8fd97e6f7890004531ee212963e4b72241dac695bf887d67dc56211d"

OPENJDK_HG_U = "jdk8u"
OPENJDK_HG_URL = "http://hg.openjdk.java.net/aarch64-port/${OPENJDK_HG_U}"

OPENJDK_FILE = "${OPENJDK_CHANGESET}.tar.bz2"
OPENJDK_URI = "${OPENJDK_HG_URL}/archive/${OPENJDK_FILE};name=openjdk"

HOTSPOT_FILE = "${HOTSPOT_CHANGESET}.tar.bz2"
HOTSPOT_URI = "${OPENJDK_HG_URL}/hotspot/archive/${HOTSPOT_FILE};name=hotspot;unpack=false"

CORBA_FILE = "${CORBA_CHANGESET}.tar.bz2"
CORBA_URI = "${OPENJDK_HG_URL}/corba/archive/${CORBA_FILE};name=corba;unpack=false"

JAXP_FILE = "${JAXP_CHANGESET}.tar.bz2"
JAXP_URI = "${OPENJDK_HG_URL}/jaxp/archive/${JAXP_FILE};name=jaxp;unpack=false"

JAXWS_FILE = "${JAXWS_CHANGESET}.tar.bz2"
JAXWS_URI = "${OPENJDK_HG_URL}/jaxws/archive/${JAXWS_FILE};name=jaxws;unpack=false"

JDK_FILE = "${JDK_CHANGESET}.tar.bz2"
JDK_URI = "${OPENJDK_HG_URL}/jdk/archive/${JDK_FILE};name=jdk;unpack=false"

LANGTOOLS_FILE = "${LANGTOOLS_CHANGESET}.tar.bz2"
LANGTOOLS_URI = "${OPENJDK_HG_URL}/langtools/archive/${LANGTOOLS_FILE};name=langtools;unpack=false"

NASHORN_FILE = "${NASHORN_CHANGESET}.tar.bz2"
NASHORN_URI = "${OPENJDK_HG_URL}/nashorn/archive/${NASHORN_FILE};name=nashorn;unpack=false"
