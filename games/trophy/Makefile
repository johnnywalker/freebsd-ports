# New ports collection makefile for:	trophy
# Date created:			22 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $Carpetsmoker: ports/games/trophy/Makefile,v 1.3 2007/08/04 03:36:57 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	trophy
PORTVERSION=	1.1.7
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A single player racing game

LICENSE=	GPLv2

LIB_DEPENDS=	clanCore-0.8:${PORTSDIR}/devel/clanlib

HAS_CONFIGURE=	yes
PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--prefix="${PREFIX}" --exec-prefix="${PREFIX}"

DESKTOP_ENTRIES="Trophy" "${COMMENT}" "" "trophy" "Application;Game;" false

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
