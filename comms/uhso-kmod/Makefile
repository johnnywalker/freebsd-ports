# New ports collection makefile for:	uhso-kmod
# Date created:				28 December 2009
# Whom:					Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	uhso
PORTVERSION=	20100416
PORTREVISION=	1
CATEGORIES=	comms kld
MASTER_SITES=	http://www.shapeshifter.se/pub/hso/
PKGNAMESUFFIX=	-kmod
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Driver for Option HSDPA modem (USB2 version)

LICENSE=	BSD

CONFLICTS=	hso-kmod-[0-9]*

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS=	UHSOCTL "Build uhsoctl tool" on \
		DEBUG "Build with debug symbols" off

SUB_FILES=	pkg-message
KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

MAN4=		uhso.4

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files
.elif ${OSVERSION} <= 800063
IGNORE=		requires FreeBSD 8.0 or later, please try comms/hso-kmod instead
.elif ${OSVERSION} >= 800501
IGNORE=	the uhso driver is already available in the base system
.endif

.if !defined(WITHOUT_UHSOCTL)
UHSOCTL_VERSION=	20100416
DISTFILES+=	uhsoctl-${UHSOCTL_VERSION}${EXTRACT_SUFX}
WRKSRC_UHSOCTL=	${WRKDIR}/uhsoctl-${UHSOCTL_VERSION}
PLIST_SUB+=	PL_UHSOCTL=""
MAN1=	uhsoctl.1
.else
PLIST_SUB+=	PL_UHSOCTL="@comment "
.endif

.if !defined(WITH_DEBUG)
EXTRA_PATCHES+=	${PATCHDIR}/UHSO-NODEBUG-patch-Makefile
.endif

post-patch:
.if !defined(WITHOUT_UHSOCTL)
.if defined(WITH_DEBUG)
	@${PATCH} -d ${WRKSRC_UHSOCTL} < ${PATCHDIR}/UHSOCTL-DEBUG-patch-Makefile
.endif
.endif

post-build:
.if !defined(WITHOUT_UHSOCTL)
	@cd ${WRKSRC_UHSOCTL} && ${SETENV} NO_MANCOMPRESS= ${MAKE} all
.endif

post-install:
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
.if !defined(WITHOUT_UHSOCTL)
	@cd ${WRKSRC_UHSOCTL} && \
		${SETENV} DESTDIR=${PREFIX}/ BINDIR=bin MANDIR=man/man NO_MANCOMPRESS= \
		${MAKE} install
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
