# New ports collection makefile for:   el
# Date created:        25 January 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	el
PORTVERSION=	192
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL:S,$,acm/${PORTNAME}/,}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Eternal Lands is a free 3D MMORPG

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		cal3d.12:${PORTSDIR}/graphics/cal3d
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/el.ini:${PORTSDIR}/games/el-data

PROJECTHOST=	bsdistfiles
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENAL=	al alut
USE_GNOME=	libxml2
USE_SDL=	sdl net image
USE_GL=		yes

ALL_TARGET=	el.bin
MAKEFILE=	Makefile.bsd
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/el
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/el
	@${ECHO} "exec ${DATADIR}/el.bin" >> ${WRKDIR}/el

	@${ECHO} "bin/el" > ${PLIST}
	@${ECHO} "%%DATADIR%%/el.bin" >> ${PLIST}
	@${ECHO} "@dirrmtry %%DATADIR%%" >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/el ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/el.bin ${DATADIR}

.include <bsd.port.post.mk>
