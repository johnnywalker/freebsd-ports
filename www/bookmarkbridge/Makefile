# New ports collection makefile for:	bookmarkbridge
# Date Created:				January 2004
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	bookmarkbridge
PORTVERSION=	0.76
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Synchronize bookmarks between multiple browsers

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

USE_PERL5_BUILD=	yes
USE_XORG=	x11 ice xext
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build rcc_build uic_build qt3support
USE_GNOME=	libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal automake autoconf
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
QTCFGLIBS+=	${PTHREAD_LIBS}
.endif

.include <bsd.port.post.mk>
