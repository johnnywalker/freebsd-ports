# New ports collection makefile for:	mod_cvs
# Date created:				14 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	mod_cvs
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	http://resare.com/noa/mod_cvs/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A module that makes Apache CVS aware

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

CONFLICTS=	apache-contrib-1.*

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
