# New ports collection makefile for:	mdds
# Date created:		2011-07-22
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdds
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Multi-dimensional data index algorithm

LICENSE=	MIT

PROJECTHOST=	multidimalgorithm

USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/mdds
	@${MKDIR} ${PREFIX}/mdds/hash_container
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/*.hpp ${PREFIX}/mdds
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/*.inl ${PREFIX}/mdds
	@${INSTALL_DATA} ${WRKSRC}/include/mdds/hash_container/*.hpp ${PREFIX}/mdds/hash_container

.include <bsd.port.mk>
