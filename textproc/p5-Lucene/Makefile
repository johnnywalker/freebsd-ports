# New ports collection makefile for:	textproc/p5-Lucene
# Date created:				20 Feb 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lucene
PORTVERSION=	0.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TBUSCH
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	API to the C++ port of the Lucene search engine

LIB_DEPENDS=	clucene:${PORTSDIR}/textproc/clucene

PERL_CONFIGURE=	yes
CC=		${CXX}
CONFIGURE_ARGS+="INC=-I${LOCALBASE}/include -I${LOCALBASE}/lib"

MAN3=	Lucene.3

.include <bsd.port.mk>
