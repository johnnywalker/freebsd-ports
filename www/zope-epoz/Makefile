# New ports collection makefile for:	zope-epoz
# Date created:				11 Feb 2004
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	epoz
PORTVERSION=	2.0.2
CATEGORIES=	www zope
MASTER_SITES=	http://iungo.org/products/Epoz/releases/
PKGNAMEPREFIX=	zope-
DISTNAME=	Epoz-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-browser-wysiwyg-editor for Zope/CMF

DEPRECATED=	Unmaintained upstream, isn't used by anything
EXPIRATION_DATE=2011-12-23

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

WRKSRC=		${WRKDIR}/Epoz

PRODUCTNAME=	Epoz

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
