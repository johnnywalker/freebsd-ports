# New ports collection makefile for:	multimedia/linux-f10-libv4l
# Date created:				2011-04-14
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libv4l
PORTVERSION=	0.6.2
CATEGORIES=	multimedia linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Collection of video4linux support libraries (Fedora 10)

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
