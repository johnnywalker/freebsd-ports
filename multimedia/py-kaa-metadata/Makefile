# New ports collection makefile for:	py-kaa-metadata
# Date created:		2009 January 10
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	kaa-metadata
PORTVERSION=	0.7.7
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	SF/freevo/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Kaa Media Repository - media file metadata parser

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/kaa/__init__.py:${PORTSDIR}/multimedia/py-kaa-base
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

.include <bsd.port.mk>
