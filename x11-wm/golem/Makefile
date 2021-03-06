# New ports collection makefile for:   golem
# Date created:        11 August 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	golem
PORTVERSION=	0.0.6
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small window manager with themes and plugins

LICENSE=	BSD

OPTIONS=	ESOUND "Build sound plugin (requires EsounD)" off \
		XINERAMA "Enable Xinerama extension support" on

USE_PERL5_BUILD=yes
USE_BZIP2=	yes
USE_XORG=	xpm
WANT_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-i18n
MAKE_ARGS=	DEVEL=1

MANCOMPRESSED=	yes
MAN1=		golem.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif
.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-sound
PLIST_SUB+=	ESOUND=""
.else
PLIST_SUB+=	ESOUND="@comment "
.endif

.if !defined(WITHOUT_XINERAMA)
USE_XORG+=	xinerama
CONFIGURE_ARGS+=--enable-xinerama
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/cl_thread.c/d' ${WRKSRC}/complib/user/Makefile

# avoid using standard MAKE_ENV
do-build:
	@cd ${BUILD_WRKSRC}; \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	@cd ${INSTALL_WRKSRC}; \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.post.mk>
