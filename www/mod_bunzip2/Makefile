# New ports collection makefile for:	mod_bunzip2
# Date created:		26 January 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_bunzip2
PORTVERSION=	1
CATEGORIES=	www
MASTER_SITES=	http://oldach.net/
DISTNAME=	${PORTNAME}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for server-side decompression of bzip2 files

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-2

AP_LIB=	-lbz2

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
