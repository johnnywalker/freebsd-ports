# New ports collection makefile for: sword
# Date created:   22 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	sword
PORTVERSION=	1.6.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v1.6/ \
		http://crosswire.org/ftpmirror/pub/sword/source/v1.6/ \
		LOCAL
MASTER_SITE_SUBDIR=	tabthorpe

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A project framework for manipulating Bible texts

LICENSE=	GPLv2

BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit

MAKE_JOBS_SAFE=	yes

USE_GNOME=	pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake autoconf
CONFIGURE_ARGS+=	--without-conf --without-clucene --with-zlib --without-icu
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.if defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--without-curl
.else
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl

run-autotools::	run-autotools-aclocal

pre-everything::
	@${ECHO_CMD} "Define WITHOUT_CURL to disable remote fetch (curl) support in the installmanager"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|:=|=|' ${WRKSRC}/Makefile.am \
		${WRKSRC}/Makefile.in ${WRKSRC}/lib/Makefile.am \
		${WRKSRC}/lib/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/share/sword/mods.d
.if !exists(${PREFIX}/etc/sword.conf)
	@(cd ${WRKSRC} && ${GMAKE} install_config)
.else
	@${ECHO_CMD} "Config file not installed since ${PREFIX}/etc/sword.conf already exists."
	@${ECHO_CMD} "Please check that DataPath points to your modules (default ${DATADIR}).";
.endif
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}

register:
	@(cd ${WRKSRC} && ${GMAKE} register)

.include <bsd.port.mk>
