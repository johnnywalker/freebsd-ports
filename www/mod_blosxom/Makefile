# New ports collection makefile for:	mod_blosxom
# Date created:				6 April 2003
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mod_blosxom
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/mod-blosxom/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Apache module to build the extremely lightweight Weblog environment

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTEXAMPLES=	sample

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${COPYTREE_SHARE} ${WRKSRC}/sample ${EXAMPLESDIR}/sample
.endif

.include <bsd.port.mk>
