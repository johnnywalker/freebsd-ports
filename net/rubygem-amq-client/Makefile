# Ports collection makefile for:	rubygem-amq-client
# Date created:				29 Sep 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amq-client
PORTVERSION=	0.8.6
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A fully-featured, low-level AMQP 0.9.1 client in Ruby

RUN_DEPENDS=	rubygem-eventmachine>=0:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-amq-protocol>=0.8.0:${PORTSDIR}/net/rubygem-amq-protocol

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
