# New ports collection makefile for:	py-distutils-extra
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	distutils-extra
PORTVERSION=	2.29
CATEGORIES=	devel python
MASTER_SITES=	http://launchpadlibrarian.net/77777670/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add support for i18n, documentation and icons to distutils

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_distutils_extra
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
