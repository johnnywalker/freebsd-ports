# Ports collection makefile for:  pear-Net_URL
# Date created:			  2003-04-04
# Whom:				  Roman Neuhauser (<neuhauser@bellavista.cz>)
#
# $FreeBSD$
#

PORTNAME=	Net_URL
PORTVERSION=	1.0.15
CATEGORIES=	net www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Easy parsing of URLs

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		URL.php
EXAMPLES=	example.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
