# New ports collection makefile for:	gdal-grass
# Date created:		Feb 2006
# Whom:			Laurent Courty
#
# $FreeBSD$
#

PORTNAME=	gdal-grass
PORTVERSION=	1.4.3
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/gdal/

MAINTAINER=	wenheping@gmail.com
COMMENT=	GDAL drivers for GRASS raster and vector files

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal
BUILD_DEPENDS=	grass>6:${PORTSDIR}/databases/grass
RUN_DEPENDS=	grass>6:${PORTSDIR}/databases/grass

GRASS_INST_DIR=	grass-6.4.1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gdal=${LOCALBASE}/bin/gdal-config \
		--with-grass=${LOCALBASE}/${GRASS_INST_DIR} \
		--with-autoload=${GDAL_AUTOLOAD_DIR}
ALL_TARGET=

.include <bsd.port.pre.mk>

pre-install:
	${MKDIR} ${PREFIX}/share/gdal

.if !defined(GDAL_AUTOLOAD_DIR)
GDAL_AUTOLOAD_DIR=${PREFIX}/lib/gdalplugins
.endif

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	grass
.endif

.include <bsd.port.post.mk>
