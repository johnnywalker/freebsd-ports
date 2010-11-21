# New ports collection makefile for:	dconf
# Date created:				28 May 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/dconf/Makefile,v 1.9 2010/11/04 16:41:01 kwm Exp $
#

PORTNAME=	dconf
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	gee.2:${PORTSDIR}/devel/libgee

USE_BZIP2=	yes
USE_GMAKE=	yes
#USE_GETTEXT=	yes
USE_GNOME=	gnomehack gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gio/modules

.include <bsd.port.mk>