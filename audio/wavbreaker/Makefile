# New ports collection makefile for:	wavbreaker
# Date created:				20 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	wavbreaker
PORTVERSION=	0.10
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tool to split and merge wav files

OPTIONS=	PULSE "Pulseaudio soundserver support" OFF

USE_GNOME=	gnomehack gtk20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PKG_CONFIG="${LOCALBASE}/bin/pkg-config"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-alsa
INSTALLS_ICONS=	yes

MAN1=		wavbreaker.1 wavinfo.1 wavmerge.1

.include <bsd.port.pre.mk>

.if !defined(WITH_PULSE)
CONFIGURE_ARGS+=	--disable-pulse
.else
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
.endif

.include <bsd.port.post.mk>
