# New ports collection makefile for:	p5-Array-Diff
# Date created:				March 09, 2008
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Array-Diff
PORTVERSION=	0.07
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Diff two arrays

RUN_DEPENDS=	p5-Algorithm-Diff>=1.19:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Array::Diff.3

.include <bsd.port.mk>
