# New ports collection makefile for:	playd
# Date created:				Apr 29, 2009
# Whom:					Aldis Berjoza <killasmurf86@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	playd
PORTVERSION=	1.22.2
CATEGORIES=	multimedia
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
DISTNAME=	playd.sh-${PORTVERSION}

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Very easy-to-use mplayer sh wrapper script (supports playlists)

LICENSE=	BSD

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

PLIST_FILES=	bin/playd
MAN1=		playd.1

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/graudeejs-playd-${REV}
REV=		52bf8eb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/playd.sh ${PREFIX}/bin/playd
	${INSTALL_MAN} ${WRKSRC}/man/man1/playd.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
