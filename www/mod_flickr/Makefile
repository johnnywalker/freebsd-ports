# New ports collection makefile for:	mod_flickr
# Date created:				2009-08-24
# Whom:						vshankar
#
# $FreeBSD$
#

PORTNAME=	mod_flickr
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.vshank.com/modcode/

MAINTAINER=	venkyshankar@yahoo.com
COMMENT=	Apache module for Flickr API access

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

MAKE_JOBS_SAFE=	yes

XTRA_FLAGS=	-lcurl

AP_INC=		${LOCALBASE}/include
AP_LIB=		${LOCALBASE}/lib

.if defined(WITH_DEBUG)
XTRA_FLAGS+=	-DDEBUG
.endif

AP_EXTRAS=	${XTRA_FLAGS}
USE_LDCONFIG=	yes

USE_APACHE=	20+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.mk>
