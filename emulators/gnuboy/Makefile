# ex:ts=8
# New ports collection makefile for:	gnuboy
# Date created:			Mar 11, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnuboy
PORTVERSION=	1.0.3
PORTREVISION=	8
CATEGORIES=	emulators games
MASTER_SITES=	http://www.sourcefiles.org/Emulators/Videogames/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo GameBoy emulator

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

USE_SDL=	sdl
USE_XORG=	x11
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--with-sdl
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/sdlgnuboy bin/sgnuboy bin/xgnuboy

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
.for file in sdlgnuboy sgnuboy xgnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
