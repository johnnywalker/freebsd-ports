# New ports collection makefile for:	xf86-video-radeonhd-devel
# Date Created:				2008-09-07
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xf86-video-radeonhd
PORTVERSION=	1.3.0.20091101
PORTREVISION=	5
CATEGORIES=	x11-drivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork
PKGNAMESUFFIX=	-devel

MAINTAINER=	nork@FreeBSD.org
COMMENT=	X.Org ati RadeonHD display driver development version

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/xorg-macros.m4:${PORTSDIR}/devel/xorg-macros \
		${LOCALBASE}/libdata/pkgconfig/gl.pc:${PORTSDIR}/graphics/libGL
LIB_DEPENDS=	pciaccess.0:${PORTSDIR}/devel/libpciaccess

XORG_CAT=	driver
USE_XORG=	damageproto glproto videoproto xextproto xf86driproto
USE_AUTOTOOLS=	automake:env aclocal:env autoconf libtool

CONFLICTS=	xf86-video-radeonhd-[0-9]*

MAN4=		radeonhd.4x

ACLOCAL_ARGS=	--acdir=${LOCALBASE}/share/aclocal

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} --force -v --install

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/conntest/rhd_conntest ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/conntest/rhd_dump ${PREFIX}/sbin

.include <bsd.port.mk>
