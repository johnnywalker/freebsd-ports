# New ports collection makefile for:	mod_sequester
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_sequester
PORTVERSION=	1.8
CATEGORIES=	www
MASTER_SITES=	http://MeepZor.Com/packages/${PORTNAME}/
DISTNAME=	${PORTNAME}-1.7.0

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that controls access to the website using secure info

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

WRKSRC=		${WRKDIR}/mod_sequester

.include <bsd.port.mk>
