# New ports collection Makefile for:	soprano
# Date created:				2008-01-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	soprano
PORTVERSION=	2.7.3
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/Soprano/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 RDF framework

LIB_DEPENDS=	raptor2.0:${PORTSDIR}/textproc/raptor2 \
		rdf.0:${PORTSDIR}/textproc/redland \
		iodbc.3:${PORTSDIR}/databases/libiodbc

OPTIONS=	SESAME2 "Use Sesame2 as storage backend (requires Java)" off

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus qtestlib network \
		qmake_build moc_build uic_build rcc_build
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DSOPRANO_DISABLE_CLUCENE_INDEX=yes

.include <bsd.port.options.mk>

.if defined(WITH_SESAME2)
CATEGORIES+=	java
CMAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
PLIST_SUB+=	SESAME2=""
.else
CMAKE_ARGS+=	-DSOPRANO_DISABLE_SESAME2_BACKEND=yes
PLIST_SUB+=	SESAME2="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,$${LIB_SUFFIX}/pkgconfig,data/pkgconfig," \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e "s,soprano/cmake,cmake/Modules," \
		${WRKSRC}/cmake/modules/CMakeLists.txt

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
