# New ports collection makefile for:	p5-Chart-PNGgraph
# Date Created:		15 December 1999
# Whom:			Garrett Wollman <wollman@lcs.mit.edu>
#
# $FreeBSD$
#

PORTNAME=	Chart-PNGgraph
PORTVERSION=	1.21
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl module for generating presentation graphics (i.e., charts)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Chart::PNGgraph.3

.include <bsd.port.mk>
