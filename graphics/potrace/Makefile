# Ports collection makefile for:	potrace
# Date created:				24 September 2003
# Whom:					Piotr Smyrak <smyru@heron.pl>
#
# $FreeBSD$
#

PORTNAME=	potrace
PORTVERSION=	1.9
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	smyru@heron.pl
COMMENT=	Transforms bitmaps into vector graphics

GNU_CONFIGURE=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		potrace.1 mkbitmap.1
.endif
PLIST_FILES=	bin/potrace bin/mkbitmap

OPTIONS=	METRIC	"Enable use of metric units (centimeters) as default" on \
		A4	"Enable use of A4 as the default papersize"           on

.include <bsd.port.pre.mk>

.if defined(WITH_A4)
CONFIGURE_ARGS+=	--enable-a4
.endif

.if defined(WITH_METRIC)
CONFIGURE_ARGS+=	--enable-metric
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/potrace ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/mkbitmap ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/doc/potrace.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/mkbitmap.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
