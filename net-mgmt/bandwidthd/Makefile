# New ports collection makefile for:	bandwidthd
# Date created:				Sun Nov  2
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	bandwidthd
PORTVERSION=	2.0.1
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tracks bandwidth usage by IP address

LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd

.if ${CC} == "clang"
USE_CSTD=	c89
.endif

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_ICONV=	YES

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/bandwidthd.sh \
				${PREFIX}/etc/rc.d/bandwidthd.sh.sample

.include <bsd.port.mk>
