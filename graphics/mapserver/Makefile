# New ports collection Makefile for:	mapserver
# Date created:				2004-05-20
# Whom:					Douglas K. Rand <rand@meridian-enviro.com>
#
# $FreeBSD$
#

PORTNAME=		mapserver
PORTVERSION=		6.0.1
PORTREVISION=		1
CATEGORIES=		graphics www geography
MASTER_SITES=		http://download.osgeo.org/mapserver/

MAINTAINER=		wen@FreeBSD.org
COMMENT=		System for developing web-based GIS applications

LIB_DEPENDS=		gd.4:${PORTSDIR}/graphics/gd \
			proj.6:${PORTSDIR}/graphics/proj \
			png.6:${PORTSDIR}/graphics/png \
			jpeg.11:${PORTSDIR}/graphics/jpeg \
			gif.5:${PORTSDIR}/graphics/giflib

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-runpath \
			--with-gd=${LOCALBASE} \
			--with-png=${LOCALBASE} \
			--with-jpeg=${LOCALBASE} \
			--with-gif=${LOCALBASE} \
			--with-proj=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes

OPTIONS=		AGG "Support for AGG image rendering (req: FreeType)" off \
			TIFF "Support for TIFF (but not GeoTIFF) files" off \
			PDF "Support for PDF output via pdflib" off \
			GDAL "Support for a number of input raster formats" on \
			GEOS "Use GEOS engine where possible" on \
			MING "Support for Macromedia Flash output" off \
			MYGIS "Support for MyGIS" off \
			POSTGIS "Support for PostGIS" off \
			PHP "Support for MapScript/PHP" off \
			PERL "Support for MapScript/PERL" off \
			PYTHON "Support for MapScript/PYTHON" off \
			WMS "Support for web map service server and client" off \
			WFS "Support for web feature service (req: GDAL)" off \
			MAPSERV "Install mapserv cgi interface" on \
			FASTCGI "Support FASTCGI" off \
			DEBUG "Enable debugging output" off

.include <bsd.port.pre.mk>

.if defined(WITH_AGG)
LIB_DEPENDS+=		agg.2:${PORTSDIR}/graphics/agg
CONFIGURE_ARGS+=	--with-agg=${LOCALBASE} --with-freetype=${LOCALBASE}
.endif

.if defined(WITH_TIFF)
.if !defined(WITH_GDAL)
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff=${LOCALBASE}
.endif
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if defined(WITH_MING)
LIB_DEPENDS+=		ming.5:${PORTSDIR}/graphics/ming
CONFIGURE_ARGS+=	--with-ming=${LOCALBASE}
.endif

.if defined(WITH_PDF)
LIB_DEPENDS+=		pdf.8:${PORTSDIR}/print/pdflib \
			tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE} --with-tiff=${LOCALBASE} --with-png=${LOCALBASE}
.endif

.if defined(WITH_WMS)
WITH_CURL=		YES
CONFIGURE_ARGS+=	--with-wms --with-wmsclient
.endif

.if defined(WITH_WFS)
WITH_CURL=		YES
WITH_GDAL=		YES
CONFIGURE_ARGS+=	--with-wfs --with-wfsclient
.endif

.if !defined(WITHOUT_GDAL)
LIB_DEPENDS+=		gdal.16:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--with-gdal=${LOCALBASE}/bin/gdal-config \
			--with-ogr=${LOCALBASE}/bin/gdal-config
.endif

.if !defined(WITHOUT_GEOS)
LIB_DEPENDS+=		geos.0:${PORTSDIR}/graphics/geos
CONFIGURE_ARGS+=	--with-geos=${LOCALBASE}/bin/geos-config
.endif

.if defined(WITH_MYGIS)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mygis=${LOCALBASE}/bin/mysql_config
.endif

.if defined(WITH_POSTGIS)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpgport.a:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
USE_PGSQL=		YES
DEFAULT_PGSQL_VER=	83
CONFIGURE_ARGS+=	--with-postgis=${LOCALBASE}/bin/pg_config
.endif

.if defined(WITH_PHP)
BUILD_DEPENDS+=		${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php5
RUN_BUILDS=		${BUILD_DEPENDS}
CONFIGURE_ARGS+=	--with-php=${LOCALBASE}/include/php/
PHP_EXTENSION_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e 's,/usr/local/,,'
PLIST_SUB+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
PLIST_SUB+=		WITH_PHP=""
.else
PLIST_SUB+=		WITH_PHP="@comment "
.endif

.if defined(WITH_PERL)
USE_PERL5=yes
PLIST_SUB+=		WITH_PERL=""
.else
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
BUILD_DEPENDS+=		${LOCALBASE}/bin/python:${PORTSDIR}/lang/python26
PLIST_SUB+=		WITH_PYTHON=""
.include <../../Mk/bsd.python.mk>
MAP_EGG=		MapScript-${PORTVERSION}-${PYTHON_VERSION:S/thon//}
PLIST_SUB+=		MAP_EGG=${MAP_EGG}
.else
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=		curl.6:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE}
.endif

.if defined(WITH_MAPSERV)
USE_APACHE=		13+
.include "${PORTSDIR}/Mk/bsd.apache.mk"
PLIST_SUB+=		WITH_MAPSERV=""
.if ${APACHE_VERSION} > 13
PLIST_DIRSTRY=		www/cgi-bin
.endif
.else
PLIST_SUB+=		WITH_MAPSERV="@comment "
.endif

.if defined(WITH_FASTCGI)
BUILD_DEPENDS+=		${LOCALBASE}/bin/cgi-fcgi:${PORTSDIR}/www/fcgi
CONFIGURE_ARGS+=	--with-fastcgi=${LOCALBASE}
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

PROG_FILES=		legend scalebar shp2img shptree shptreetst shptreevis sortshp

post-patch:
.if defined(WITH_MING)
	${REINPLACE_CMD} -e 's#with_ming/include#with_ming/include/ming#g' \
		${WRKSRC}/configure
.endif

post-build:
.if defined(WITH_PERL)
	(cd ${WRKSRC}/mapscript/perl && ${PERL5} Makefile.PL && make)
.endif

do-install:
.for f in ${PROG_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/shp2mysql.pl ${PREFIX}/bin/shp2mysql
.if defined(WITH_MAPSERV)
	${MKDIR} ${LOCALBASE}/www/cgi-bin/
	${INSTALL_PROGRAM} ${WRKSRC}/mapserv ${LOCALBASE}/www/cgi-bin/mapserv
.endif

.if defined(WITH_PHP)
	@${MKDIR} ${LOCALBASE}/${PHP_EXTENSION_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/mapscript/php/php_mapscript.so ${LOCALBASE}/${PHP_EXTENSION_DIR}/
.endif

.if defined(WITH_PERL)
	(cd ${WRKSRC}/mapscript/perl && make install)
.endif

.if defined(WITH_PYTHON)
	(cd ${WRKSRC}/mapscript/python && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install)
.endif

post-install:
.if defined(WITH_PHP)
	@${ECHO_MSG} "Please add the line extension=php_mapscript.so to ${LOCALBASE}/etc/php/extensions.ini"
.endif

.include <bsd.port.post.mk>
