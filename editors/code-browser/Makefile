# ex:ts=8
# Ports collection makefile for:	code-browser
# Date created:			Jan 25, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	code-browser
PORTVERSION=	3.18
CATEGORIES=	editors
MASTER_SITES=	http://tibleiz.net/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Folding Text Editor

PORTSCOUT=	skipv:3.19 # Windows-only patch

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk20
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}-3

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=		i386 amd64 sparc64
ONLY_FOR_ARCHS_REASON=	does not build on ${ARCH}; signal 11 errors during build

.if ${ARCH} != "i386"
MAKE_ARGS+=	MODE=64
.endif

post-patch:
.for file in Makefile zinc/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g ; \
		 s|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s| make| $$(MAKE)|g ; \
		 s|@$$(|$$(|g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} \* ${DOCSDIR}/samples)
.endif

.include <bsd.port.post.mk>
