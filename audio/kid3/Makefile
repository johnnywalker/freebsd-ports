# New ports collection makefile for:   kid3
# Date created:                2006-08-02
# Whom:                        Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kid3
PORTVERSION=	1.6
CATEGORIES=	audio kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MP3/Ogg/FLAC tag editor for KDE

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		FLAC.10:${PORTSDIR}/audio/flac \
		ogg.7:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		tunepimp.5:${PORTSDIR}/audio/libtunepimp \
		mp4v2.10:${PORTSDIR}/multimedia/mp4v2

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

post-configure:
	${CHMOD} 755 ${WRKSRC}/admin/install-sh

.include <bsd.port.mk>
