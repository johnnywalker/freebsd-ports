# New ports collection makefile for:	ocaml-calendar
# Date created:				Feb 26, 2007
# Whom:					Jaap Boender <jaapb@kerguelen.org>
#
# $FreeBSD$
#

PORTNAME=	pgocaml
PORTVERSION=	1.4
CATEGORIES=	databases
MASTER_SITES=	BERLIOS
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tgz

MAINTAINER=	tcrimi@gmail.com
COMMENT=	An OCaml interface to PostgreSQL

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/extlib:${PORTSDIR}/devel/ocaml-extlib \
		${LOCALBASE}/${OCAML_SITELIBDIR}/pcre:${PORTSDIR}/devel/ocaml-pcre \
		${LOCALBASE}/${OCAML_SITELIBDIR}/calendar:${PORTSDIR}/devel/ocaml-calendar \
		${LOCALBASE}/${OCAML_SITELIBDIR}/csv:${PORTSDIR}/textproc/ocaml-csv

BROKEN=		does not build

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
OCAML_PKGDIRS=	pgocaml

INSTALL_TARGET=	findlib_install

pre-build:
	cd ${WRKSRC}; ${GMAKE} depend

post-install:
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}

.include <bsd.port.mk>
