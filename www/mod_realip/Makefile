# New ports collection makefile for:	mod_realip
# Date created:				11 July 2005
# Whom:					glebius
#
# $FreeBSD$
#

PORTNAME=	mod_realip
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://sysoev.ru/mod_realip/

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Apache module to fix IP addresses in proxied requests

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.mk>
