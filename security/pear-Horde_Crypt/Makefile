# Ports collection makefile for:  pear-Horde_Crypt
# Date created:			  7 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Horde_Crypt
PORTVERSION=	1.0.6
CATEGORIES=	security www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Cryptography API

OPTIONS=	BCMATH "Depend on bcmath PHP extension" Off

USE_HORDE_RUN=	Horde_Exception Horde_Mime Horde_Stream_Filter \
		Horde_Translation Horde_Util
USE_PHP=	hash openssl

.include <bsd.port.pre.mk>

.if defined(WITH_BCMATH)
USE_PHP+=	bcmath
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
