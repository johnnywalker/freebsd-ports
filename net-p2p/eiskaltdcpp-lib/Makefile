# New ports collection makefile for: net-p2p/eiskaltdc
# Date created:		28 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	eiskaltdcpp-lib
PORTVERSION=	2.1.1
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	A Direct Connect client shared library

LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs

PROJECTHOST=	eiskaltdc

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	LUA	"Lua scripting support"	off \
		PCRE	"PCRE support in ADL Search" off

.include <bsd.port.options.mk>

CMAKE_ARGS+=	-DINSTALL_HEADERS:BOOL=ON
CMAKE_ARGS+=	-DUSE_QT:BOOL=OFF
CMAKE_ARGS+=	-DUSE_GTK:BOOL=OFF
CMAKE_ARGS+=	-DUSE_ASPELL:BOOL=OFF
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=OFF

.if defined(WITH_LUA) && !defined(WITHOUT_LUA)
USE_LUA=	5.1
CMAKE_ARGS+=	-DLUA_SCRIPT:BOOL=ON
IGNORE=	crashes on connect attempt if built with Lua support
.else
CMAKE_ARGS+=	-DLUA_SCRIPT:BOOL=OFF
.endif

.if defined(WITH_PCRE) && !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CMAKE_ARGS+=	-DPERL_REGEX:BOOL=ON
.else
CMAKE_ARGS+=	-DPERL_REGEX:BOOL=OFF
.endif

.if ${OSVERSION} < 700024
USE_OPENSSL_PORT=yes
.endif

.include <bsd.port.mk>