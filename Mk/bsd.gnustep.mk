#
# $FreeBSD: ports/Mk/bsd.gnustep.mk,v 1.36 2006/11/20 03:47:08 dinoex Exp $
#
# This file contains some variable definitions that are supposed to
# make your life easier when dealing with ports related to the GNUstep.
#
#
# Options for user to customize in /etc/make.conf:
# ================================================
#
# WITH_GNUSTEP_XLIB=yes
#	use xlib as backend (default)
#
# WITH_GNUSTEP_XDPS=yes
#	use xdps as backend while build instead of xlib.
#
# WITH_GNUSTEP_LIBART=yes
#	use libart as backend while build instead of xlib.
#
# WITH_GNUSTEP_CAIRO=yes
#	use cairo as backend while build instead of xlib.
#
# GNUSTEP_WITH_BASE_GCC=yes
#	use system compiler (does not work on all architectures).
#
# GNUSTEP_WITH_GCC32=yes
#	use gcc 3.2.x with objective C shared libraries.
#
# GNUSTEP_WITH_GCC33=yes
#	use gcc 3.3.x with objective C shared libraries.
#
# GNUSTEP_WITH_GCC34=yes
#	use gcc 3.4.x with objective C shared libraries (default).
#
# GNUSTEP_WITH_GCC40=yes
#	use gcc 4.0.x with objective C shared libraries.
#
# GNUSTEP_WITH_GCC41=yes
#	use gcc 4.1.x with objective C shared libraries.
#
# GNUSTEP_WITH_GCC42=yes
#	use gcc 4.2.x with objective C shared libraries.
#
#
# Options for a port before include this file:
# ============================================
#
# USE_GNUSTEP_BASE=yes
#	your port depends on the gnustep-base port.
#
# USE_GNUSTEP_GUI=yes
#	your port depends on the gnustep-gui port.
#
# USE_GNUSTEP_BACK=yes
#	your port depends on the gnustep-back port.
#
# USE_GNUSTEP_CONFIGURE=yes
#	call configure script with GNUstep.sh sourced in the current shell
#
# USE_GNUSTEP_BUILD=yes
#	call build target with GNUstep.sh sourced in the current shell
#
# USE_GNUSTEP_INSTALL=yes
#	call install target with GNUstep.sh sourced in the current shell
#
# USE_GNUSTEP_MAKE_DIRS=	App Tools
#	call build and install target in each of the given dirs.
#
# USE_GNUSTEP_MAKE=yes
#	require GNUstep.sh for build and install
#
# USE_GNUSTEP_SYSTEM_LIBS+=	Renaissance:x11-toolkits/renaissance
#	depends on a shared lib in System directrory
#
# USE_GNUSTEP_SYSTEM_BUNDLES+=	EtoileMenus:x11-themes/etoile-etoilemenus
#	depends on Bundles installed in System directrory at build and runtime
#
# USE_GNUSTEP_SYSTEM_THEMES+=	Camaelon:x11-themes/etoile-camaelon
#	depends on Themes installed in System directrory at build and runtime
#
# USE_GNUSTEP_LOCAL_LIBS+=	pantomime:mail/pantomime
#	depends on a shared lib in Local directrory
#
# USE_GNUSTEP_LOCAL_BUNDLES+=	Cddb:audio/cddb-bundle
#	depends on Bundles installed in Local directrory at build and runtime
#
# USE_GNUSTEP_LOCAL_THEMES+=	WildMenus:x11-themes/etoile-wildmenus
#	depends on Themes installed in Local directrory at build and runtime
#
# USE_GNUSTEP_SYSTEM_APPS+=	ProjectCenter:devel/projectcenter.app
#	depends on Application installed in System directrory at runtime
#
# USE_GNUSTEP_LOCAL_APPS+=	Ink:misc/gnustep-examples
#	depends on Application installed in Local directrory at runtime
#
# USE_GNUSTEP_LOCAL_TOOLS+=	zillion:net/zillion
#	depends on Tool installed in Local directrory at runtime
#
# ---------------------------------------------------------------------------
.if !defined(_POSTMKINCLUDED)

GNUstep_Include_MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS+=	${LOCALBASE}/lib/libcallback.a:${PORTSDIR}/devel/ffcall
.if !defined(GNUSTEP_WITHOUT_LIBOBJC)
.if !defined(GNUSTEP_WITH_BASE_GCC)
BUILD_DEPENDS+=	${TARGLIB}/libobjc.so:${PORTSDIR}/${GNUSTEP_GCC_PORT}
RUN_DEPENDS+=	${TARGLIB}/libobjc.so:${PORTSDIR}/${GNUSTEP_GCC_PORT}
.else
BUILD_DEPENDS+=	${COMBOLIBDIR}/libobjc.so:${PORTSDIR}/${GNUSTEP_OBJC_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libobjc.so:${PORTSDIR}/${GNUSTEP_OBJC_PORT}
.endif
.endif

.if defined(USE_GNUSTEP_BUILD) || defined(USE_GNUSTEP_MAKE)
BUILD_DEPENDS+=	${SYSMAKEDIR}/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT}
.endif
.if defined(USE_GNUSTEP_INSTALL) || defined(USE_GNUSTEP_MAKE)
RUN_DEPENDS+=	${SYSMAKEDIR}/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT}
.endif

GNUSTEP_MAKE_PORT?=	devel/gnustep-make
GNUSTEP_OBJC_PORT?=	lang/gnustep-objc
GNUSTEP_BASE_PORT?=	lang/gnustep-base
GNUSTEP_GUI_PORT?=	x11-toolkits/gnustep-gui
GNUSTEP_BACK_PORT?=	x11-toolkits/gnustep-back
GNUSTEP_XDPS_PORT?=	x11-toolkits/gnustep-xdps
GNUSTEP_ART_PORT?=	x11-toolkits/gnustep-art
GNUSTEP_CAIRO_PORT?=	x11-toolkits/gnustep-cairo

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

.if !defined(USE_MAKEFILE)
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
.endif

.if defined(ADDITIONAL_OBJCFLAGS)
MAKE_ENV+=	ADDITIONAL_OBJCFLAGS="${ADDITIONAL_OBJCFLAGS}"
.endif
.if defined(ADDITIONAL_LDFLAGS)
MAKE_ENV+=	ADDITIONAL_LDFLAGS="${ADDITIONAL_LDFLAGS}"
.endif

GNUSTEP_PREFIX?=	${LOCALBASE}/GNUstep
DEFAULT_LIBVERSION?=	0.0.1

.if defined(USE_GNUSTEP_PREFIX)
PREFIX=		${GNUSTEP_PREFIX}
NO_MTREE=	yes
.endif

SYSTEMDIR=	${GNUSTEP_PREFIX}/System
SYSMAKEDIR=	${SYSTEMDIR}/Library/Makefiles
SYSBUNDLEDIR=	${SYSTEMDIR}/Library/Bundles
SYSLIBDIR=	${SYSTEMDIR}/Library/Libraries
COMBOLIBDIR=	${SYSTEMDIR}/Library/Libraries
LOCALLIBDIR=	${GNUSTEP_PREFIX}/Local/Library/Libraries
LOCALBUNDLEDIR=	${GNUSTEP_PREFIX}/Local/Library/Bundles

.if defined(WITH_GNUSTEP_DEVEL)
PKGNAMESUFFIX?=	-devel${PKGNAMESUFFIX2}
PLIST_SUB+=	GNUSTEP_DEVEL=""
PLIST_SUB+=	GNUSTEP_STABLE="@comment "
.else
PLIST_SUB+=	GNUSTEP_DEVEL="@comment "
PLIST_SUB+=	GNUSTEP_STABLE=""
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} VERSION=${PORTVERSION}
PLIST_SUB+=	MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}
PLIST_SUB+=	LIBVERSION=${DEFAULT_LIBVERSION}
PLIST_SUB+=	MAJORLIBVERSION=${DEFAULT_LIBVERSION:C/([0-9]).*/\1/1}

.if !defined(GNUSTEP_WITH_BASE_GCC)
.if !defined(GNUSTEP_WITH_GCC32) && !defined(GNUSTEP_WITH_GCC33) && !defined(GNUSTEP_WITH_GCC34)
.if !defined(GNUSTEP_WITH_GCC40) && !defined(GNUSTEP_WITH_GCC41) && !defined(GNUSTEP_WITH_GCC42)
GNUSTEP_WITH_GCC41=	yes
.endif
.endif

.if defined(GNUSTEP_WITH_GCC32)
GCCSUFFIX=32
GNUSTEP_GCC_PORT?=	lang/gcc-objc
.endif
.if defined(GNUSTEP_WITH_GCC33)
GCCSUFFIX=33
.endif
.if defined(GNUSTEP_WITH_GCC34)
GCCSUFFIX=34
.endif
.if defined(GNUSTEP_WITH_GCC40)
GCCSUFFIX=40
.endif
.if defined(GNUSTEP_WITH_GCC41)
GCCSUFFIX=41
.endif
.if defined(GNUSTEP_WITH_GCC42)
GCCSUFFIX=42
.endif
CC=		gcc${GCCSUFFIX}
CXX=		g++${GCCSUFFIX}
GNUSTEP_GCC_PORT?=	lang/gcc${GCCSUFFIX}

.endif

# ---------------------------------------------------------------------------
# using base
#
.if defined(USE_GNUSTEP_BASE)
BUILD_DEPENDS+=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT}
.endif

# ---------------------------------------------------------------------------
# using gui
#
.if defined(USE_GNUSTEP_GUI)
BUILD_DEPENDS+=	${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT}
.endif

# ---------------------------------------------------------------------------
# using any backend
#
.if defined(USE_GNUSTEP_BACK)
BACKSUFFIX?=	-011
.if defined(WITH_GNUSTEP_XDPS)
GNUSTEP_WITH_XDPS=yes
.elif defined(WITH_GNUSTEP_LIBART)
USE_GNUSTEP_LIBART=yes
.elif defined(WITH_GNUSTEP_CAIRO)
USE_GNUSTEP_CAIRO=yes
.elif defined(WITH_GNUSTEP_XLIB)
USE_GNUSTEP_XLIB=yes
.else
# default:
USE_GNUSTEP_XLIB=yes
.endif
.endif

# ---------------------------------------------------------------------------
# Backend using xlib
#
.if defined(USE_GNUSTEP_XLIB)
BUILD_DEPENDS+=	${SYSBUNDLEDIR}/${BACKXLIB}.bundle/${BACKXLIB}:${PORTSDIR}/${GNUSTEP_BACK_PORT}
RUN_DEPENDS+=	${SYSBUNDLEDIR}/${BACKXLIB}.bundle/${BACKXLIB}:${PORTSDIR}/${GNUSTEP_BACK_PORT}

BACKXLIB=	libgnustep-back${BACKSUFFIX}
MAKE_FLAGS+=	GUI_BACKEND_LIB=back
.endif

# ---------------------------------------------------------------------------
# Backend using xdps
#
.if defined(USE_GNUSTEP_XDPS)
BUILD_DEPENDS+=	${SYSBUNDLEDIR}/${BACKXDPS}.bundle/${BACKXDPS}:${PORTSDIR}/${GNUSTEP_XDPS_PORT}
RUN_DEPENDS+=	${SYSBUNDLEDIR}/${BACKXDPS}.bundle/${BACKXDPS}:${PORTSDIR}/${GNUSTEP_XDPS_PORT}

BACKXDPS=	libgnustep-xdps${BACKSUFFIX}
MAKE_FLAGS+=	GUI_BACKEND_LIB=xdps
.endif

# ---------------------------------------------------------------------------
# Backend using libart
#
.if defined(USE_GNUSTEP_LIBART)
BUILD_DEPENDS+=	${SYSBUNDLEDIR}/${BACKART}.bundle/${BACKART}:${PORTSDIR}/${GNUSTEP_ART_PORT}
RUN_DEPENDS+=	${SYSBUNDLEDIR}/${BACKART}.bundle/${BACKART}:${PORTSDIR}/${GNUSTEP_ART_PORT}

BACKART=	libgnustep-art${BACKSUFFIX}
MAKE_FLAGS+=	GUI_BACKEND_LIB=art
.endif

# ---------------------------------------------------------------------------
# Backend using cairo
#
.if defined(USE_GNUSTEP_CAIRO)
BUILD_DEPENDS+=	${SYSBUNDLEDIR}/${BACKCAIRO}.bundle/${BACKCAIRO}:${PORTSDIR}/${GNUSTEP_CAIRO_PORT}
RUN_DEPENDS+=	${SYSBUNDLEDIR}/${BACKCAIRO}.bundle/${BACKCAIRO}:${PORTSDIR}/${GNUSTEP_CAIRO_PORT}

BACKCAIRO=	libgnustep-cairo${BACKSUFFIX}
MAKE_FLAGS+=	GUI_BACKEND_LIB=cairo
.endif

# ---------------------------------------------------------------------------
# source system libs
#
.if defined(USE_GNUSTEP_SYSTEM_LIBS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_LIBS}
BUILD_DEPENDS+=	${COMBOLIBDIR}/lib${_GNUSTEP_DEP:C/:.*//}.so:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${COMBOLIBDIR}/lib${_GNUSTEP_DEP:C/:.*//}.so:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source system bundles
#
.if defined(USE_GNUSTEP_SYSTEM_BUNDLES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_BUNDLES}
BUILD_DEPENDS+=	${SYSBUNDLEDIR}/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${SYSBUNDLEDIR}/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source system themes
#
.if defined(USE_GNUSTEP_SYSTEM_THEMES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_THEMES}
BUILD_DEPENDS+=	${SYSBUNDLEDIR}/${_GNUSTEP_DEP:C/:.*//}.themeEngine/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${SYSBUNDLEDIR}/${_GNUSTEP_DEP:C/:.*//}.themeEngine/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local libs
#
.if defined(USE_GNUSTEP_LOCAL_LIBS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_LIBS}
BUILD_DEPENDS+=	${LOCALLIBDIR}/lib${_GNUSTEP_DEP:C/:.*//}.so:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${LOCALLIBDIR}/lib${_GNUSTEP_DEP:C/:.*//}.so:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local bundles
#
.if defined(USE_GNUSTEP_LOCAL_BUNDLES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_BUNDLES}
BUILD_DEPENDS+=	${LOCALBUNDLEDIR}/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${LOCALBUNDLEDIR}/${_GNUSTEP_DEP:C/:.*//}.bundle/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local themes
#
.if defined(USE_GNUSTEP_LOCAL_THEMES)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_THEMES}
BUILD_DEPENDS+=	${LOCALBUNDLEDIR}/${_GNUSTEP_DEP:C/:.*//}.themeEngine/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
RUN_DEPENDS+=	${LOCALBUNDLEDIR}/${_GNUSTEP_DEP:C/:.*//}.themeEngine/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source system apps
#
.if defined(USE_GNUSTEP_SYSTEM_APPS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_SYSTEM_APPS}
RUN_DEPENDS+=	${SYSTEMDIR}/Applications/${_GNUSTEP_DEP:C/:.*//}.app/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local apps
#
.if defined(USE_GNUSTEP_LOCAL_APPS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_APPS}
RUN_DEPENDS+=	${GNUSTEP_PREFIX}/Local/Applications/${_GNUSTEP_DEP:C/:.*//}.app/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source local tools
#
.if defined(USE_GNUSTEP_LOCAL_TOOLS)
.for _GNUSTEP_DEP in ${USE_GNUSTEP_LOCAL_TOOLS}
RUN_DEPENDS+=	${GNUSTEP_PREFIX}/Local/Tools/${_GNUSTEP_DEP:C/:.*//}:${PORTSDIR}/${_GNUSTEP_DEP:C/.*://}
.endfor
.endif

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
.if defined(USE_GNUSTEP_CONFIGURE)
run-autotools::
	@${DO_NADA}

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; . ${SYSMAKEDIR}/GNUstep.sh; \
	    if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_DATA="${INSTALL} -c" \
		INSTALL_PROGRAM="${INSTALL} -c" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
		    ${ECHO} "===>  Script \"${CONFIGURE_SCRIPT}\" failed: here are the contents of \"${CONFIGURE_LOG}\""; \
		    ${CAT} ${CONFIGURE_LOG}; \
		    ${ECHO} "(end of \"${CONFIGURE_LOG}\")"; \
		    ${FALSE}; \
	    fi)
.endif

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
.if defined(USE_GNUSTEP_BUILD)
do-build:
.if defined(USE_GNUSTEP_MAKE_DIRS)
.for i in ${USE_GNUSTEP_MAKE_DIRS}
	@(cd ${WRKSRC}/${i}; . ${SYSMAKEDIR}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
.endfor
.else
	@(cd ${WRKSRC}; . ${SYSMAKEDIR}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})
.endif

.endif

# ---------------------------------------------------------------------------
# source GNUstep.sh
#
.if defined(USE_GNUSTEP_INSTALL)
do-install:
.if defined(USE_GNUSTEP_MAKE_DIRS)
.for i in ${USE_GNUSTEP_MAKE_DIRS}
	@(cd ${WRKSRC}/${i}; . ${SYSMAKEDIR}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.endfor
.else
	@(cd ${WRKSRC}; . ${SYSMAKEDIR}/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(BATCH) || defined(CLEAN_ROOT)
	rm -rf /root/GNUstep
.endif

.endif

.if !defined(GNUSTEP_WITH_BASE_GCC)
TARGLIB!=	(cd ${PORTSDIR}/${GNUSTEP_GCC_PORT} && make -V TARGLIB)
.endif

.endif

# ---------------------------------------------------------------------------
# run ldconfig for installed shlibs
#
.if defined(USE_GNUSTEP_LDCONFIG)
.for i in ${USE_GNUSTEP_LDCONFIG}
LDCONFIG_DIRS+=	${i}
.endfor
INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes
.endif

# eof
