# New ports collection makefile for:	cksfv
# Date created:				18 October 2000
# Whom:					Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	cksfv
PORTVERSION=	1.3.14
CATEGORIES=	security
MASTER_SITES=	http://zakalwe.fi/~shd/foss/cksfv/files/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create or manipulate Simple File Verification (SFV) checksum files

HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man --prefix=${PREFIX}

LICENSE=	GPLv2

MAN1=		cksfv.1
PLIST_FILES=	bin/cksfv
PORTDOCS=	README ChangeLog

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC\)=|\1?=|' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
