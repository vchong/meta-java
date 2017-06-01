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

CORBA_CHANGESET = "fdaba58ace3f"
SRC_URI[corba.md5sum] = "f035b292c0dfd8aa2aff70eb06f00437"
SRC_URI[corba.sha256sum] = "911873340c5ce3df4d533df67b91ac0b34dc523d169bbed2a2378a02ceaaf688"

HOTSPOT_CHANGESET = "7fd7df1d4202"
SRC_URI[hotspot.md5sum] = "f67c958b7727d12b29070ac4c69de7e9"
SRC_URI[hotspot.sha256sum] = "35243f6df9cfc671bec58c134b4d67ba6a7a01d4330c64b04b3c0de0f02e4343"

JAXP_CHANGESET = "03a066cfb70b"
SRC_URI[jaxp.md5sum] = "57753f6f7d1d666442b50ee35ef7fea2"
SRC_URI[jaxp.sha256sum] = "ed8108ca09e0fe07b4f2941df76f46ed3bc775d9ed2e9a20be9d2a7f3c97e02b"

JAXWS_CHANGESET = "c3135756134d"
SRC_URI[jaxws.md5sum] = "9f20295957c934c564f39f9e39eb52c9"
SRC_URI[jaxws.sha256sum] = "d6c5d78c39344a33cf7e2570a6fcb30ce40737f444f4eab0d2925f2ecb88ae5e"

JDK_CHANGESET = "d28a61f098ed"
SRC_URI[jdk.md5sum] = "556dfa403093b5d4d869d32fa89a8f6e"
SRC_URI[jdk.sha256sum] = "5188f8142c246cc4c9d689adc6205476ae45d16c39c59574380630afe41e5058"

LANGTOOLS_CHANGESET = "672cf1af8e7b"
SRC_URI[langtools.md5sum] = "fbf56a091ff5f75e0f5a1e86a6f354ff"
SRC_URI[langtools.sha256sum] = "71df9a8e76fd0ca4573c7e5ac8e3183464505cf2536dcc77568d57a618701891"

NASHORN_CHANGESET = "9de3e275e668"
SRC_URI[nashorn.md5sum] = "b9c10a69e544b0238b97b7abc0aa79b2"
SRC_URI[nashorn.sha256sum] = "8bfb2cac3cd09acd2a0a0e119d18ceb21afdc319a662467badaa924b5abfa9d5"

OPENJDK_CHANGESET = "27391bec6a47"
SRC_URI[openjdk.md5sum] = "3f4382967a06688ccc958a51a53b219c"
SRC_URI[openjdk.sha256sum] = "edd78eeecc5f95cf83118293ed530cb8fac2ce33658f54844bae255559418575"

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
