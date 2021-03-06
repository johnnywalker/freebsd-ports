# ex:ts=8
# New ports collection makefile for:	blat
# Date created:		08 Dec 2005
# Whom:	      		Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	blat
PORTVERSION=	34
CATEGORIES=	biology
MASTER_SITES=	http://www.soe.ucsc.edu/~kent/src/
DISTNAME=	${PORTNAME}Src${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A fast tool for local sequence similarity searches

USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}Src
MAKE_ENV+=	HOME="${WRKSRC}/${BINDIR}" MACHTYPE="${ARCH}"

SUB_FILES=	pkg-message

EXECUTABLES=	blat faToNib faToTwoBit gfClient gfServer nibFrag \
		pslPretty pslReps pslSort twoBitInfo twoBitToFa

post-patch:
	@${MKDIR} ${WRKSRC}/bin/${ARCH}
	@${MKDIR} ${WRKSRC}/lib/${ARCH}
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS)=,\1 ?=,g;s,-Werror,,g' \
		${WRKSRC}/inc/common.mk

do-install:
.for exe in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${ARCH}/${exe} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}/webBlat
	${INSTALL_PROGRAM} ${WRKSRC}/webBlat/webBlat ${DATADIR}/webBlat
	${INSTALL_DATA} ${WRKSRC}/webBlat/install.txt ${DATADIR}/webBlat
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
