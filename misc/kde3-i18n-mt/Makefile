# New ports collection makefile for:    kde3-i18n-mt
# Date created:                         05 April 2002
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
# PORTVERSION=	${KDE_VERSION}
PORTVERSION=	3.1.5
PORTREVISION=	5
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	Attic/${PORTVERSION:S/.0//}/src/kde-i18n
PKGNAMEPREFIX=	mt-
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maltese messages and documentation for KDE3

BROKEN=	does not fetch

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	build
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
