# New ports collection makefile for:	glurp
# Date created:		Jun 9 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	glurp
PORTVERSION=	0.12.3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Nice and clean GTK+-2.x based graphical client for musicpd

LIB_DEPENDS=	mpd.3:${PORTSDIR}/audio/libmpd

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 libglade2
MAKE_ARGS+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -export-dynamic" \

.include <bsd.port.mk>
