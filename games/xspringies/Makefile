# Ports collection makefile for:	xspringies
# Date created:				12 January 1997
# Whom:					jkh
#
# $FreeBSD$
#

PORTNAME=	xspringies
PORTVERSION=	1.12
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/dmd/xspringies/ \
		http://www.cs.rutgers.edu/~decarlo/software/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mass and spring simulation system

LICENSE=	GPLv1 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	x11 xext
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_SAFE=	yes

MAN1=		xspringies.1

post-patch:
	@cd ${WRKSRC} && ${SED} -e \
		's|/usr/games/|${PREFIX}/| ; \
		 s|lib/xspringies|lib/X11/xspringies| ; \
		 s|CFLAGS = -O|CFLAGS += -I${LOCALBASE}/include| ; \
		 s|LIBS = -lm|LIBS = -L${LOCALBASE}/lib -lm|' \
			< Makefile.std > Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xspringies ${PREFIX}/bin/xspringies
	${INSTALL_MAN} ${WRKSRC}/xspringies.man ${MANPREFIX}/man/man1/xspringies.1
	@${MKDIR} ${PREFIX}/lib/X11/xspringies
	${INSTALL_DATA} ${WRKSRC}/lib/*.xsp ${PREFIX}/lib/X11/xspringies

.include <bsd.port.mk>
