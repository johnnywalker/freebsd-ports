# New ports collection makefile for:   vmips
# Date created:        13 July 2004
# Whom:                brg
#
# $FreeBSD$
#

PORTNAME=	vmips
PORTVERSION=	1.3.2
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	SF \
		http://www.dgate.org/vmips/releases/vmips-${PORTVERSION}/


MAINTAINER=	brg@dgate.org
COMMENT=	MIPS R3000 simulator

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		texi2dvi:${PORTSDIR}/print/texinfo

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		vmips.1 vmipstool.1
INFO=		vmips

.include <bsd.port.mk>
