# New ports collection makefile for:	grsync
# Date created:		24 August 2007
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	grsync
PORTVERSION=	1.2.0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.opbyte.it/release/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GTK frontend for rsync

LICENSE=	GPLv2

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		bash:${PORTSDIR}/shells/bash

USE_GNOME=	gtk20 desktopfileutils
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		grsync.1 grsync-batch.1

post-patch:
	@${REINPLACE_CMD} 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/src/grsync-batch
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} 's/^ALL_LINGUAS=.*/ALL_LINGUAS=""/' \
		${WRKSRC}/configure
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
