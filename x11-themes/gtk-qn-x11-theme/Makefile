# New ports collection makefile for:	gtk-qn-x11-theme
# Date Created:				16 March 2001
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtk-qn-x11-theme
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	qnx11__
DISTNAME=	qnx11__-1.2.x

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	The QN-X11 GTK theme engine

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2011-12-03

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
