# New ports collection makefile for:	mar
# Date created:				20 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	mar
DISTVERSION=	0.5
CATEGORIES=	archivers
MASTER_SITES=	CRITICAL
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A simple binary file format for storing arbitrary meta and user data

MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

LICENSE=	MIT
MAN1=		mar.1

post-patch:
	@${REINPLACE_CMD} -E "s#^(CFLAGS\ |CXXFLAGS\ |CC\ |CXX\ )#\1?#" \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/mar.1 ${MAN1PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
