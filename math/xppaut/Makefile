# New ports collection makefile for:	xppaut
# Date created:		3 September 2004
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	xppaut
PORTVERSION=	5.99
CATEGORIES=	math graphics
MASTER_SITES=	http://www.math.pitt.edu/~bard/bardware/
DISTNAME=	${PORTNAME}_latest

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Graphical tool for solving differential equations, etc

MAN1=		xppaut.1
USE_XORG=	xbitmaps x11 xproto
CFLAGS+=	-w -Wno-return-type
WRKSRC=		${WRKDIR}

post-build:
	${CHMOD} a+r ${WRKSRC}/xppaut.1

pre-configure:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|# PORTDOCS||" ${WRKSRC}/Makefile
.endif

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -e "s|gcc|${CC}|" -e "s|CFLAGS=|CFLAGS= ${CFLAGS}|" Makefile libI77/Makefile cvodesrc/Makefile mkavi/Makefile)

.include <bsd.port.mk>
