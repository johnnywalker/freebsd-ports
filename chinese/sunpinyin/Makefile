# New ports collection makefile for:	sunpinyin
# Date created:				10 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sunpinyin
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	chinese devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}:1 \
		http://open-gram.googlecode.com/files/:2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1 \
		lm_sc.t3g.arpa.tar.bz2:2 dict.utf8.tar.bz2:2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lichray@gmail.com
COMMENT=	A statistical language model based input method engine

LICENSE=	LGPL21 CDDL
LICENSE_COMB=	dual

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config

LICENSE_FILE_LGPL21=	${WRKSRC}/LGPL.LICENSE
LICENSE_FILE_CDDL=	${WRKSRC}/OPENSOLARIS.LICENSE

USE_SCONS=	yes
SCONS_ARGS+=	--prefix=${PREFIX} --libdatadir=${PREFIX}/share
USE_LDCONFIG=	yes
USE_GMAKE=	yes

post-patch:
	@${CP} ${_DISTDIR}/lm_sc.t3g.arpa.tar.bz2 \
		${_DISTDIR}/dict.utf8.tar.bz2 ${WRKSRC}/raw

.include <bsd.port.mk>
