# New ports collection makefile for:	cdircmp
# Date created:				21 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	cdircmp
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Compare directories and select files to copy

MAKE_JOBS_SAFE=	yes

LDFLAGS+=	-lncurses -lform

LICENSE=	GPLv2

PLIST_FILES=	bin/cdircmp

do-build:
	${CC} ${CFLAGS} -c ${WRKSRC}/main.c -o ${WRKSRC}/main.o
	${CC} ${LDFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/main.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
