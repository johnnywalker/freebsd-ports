# New ports collection makefile for:	koffice-i18n-br
# Date created:                         November 18th, 2004
# Whom:                                 Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.5.2
PORTREVISION=	6
CATEGORIES?=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	Attic/koffice-${PORTVERSION}/src/koffice-l10n
PKGNAMEPREFIX=	br-
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Breton messages and documentation for koffice

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	build
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
