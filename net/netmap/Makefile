# ex:ts=8
# Ports collection makefile for:	netmap
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netmap
PORTVERSION=	0.1.2b
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NetMap%200.1.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make a graphical representation of the surounding network

RUN_DEPENDS=	dotty:${PORTSDIR}/graphics/graphviz

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makelist/makelist ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/netmap/netmap ${PREFIX}/bin

.include <bsd.port.mk>
