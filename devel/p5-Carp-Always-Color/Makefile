# New ports collection makefile for:	p5-Carp-Always-Color
# Date created:		2011-09-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Carp-Always-Color
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Carp::Always, but with color

BUILD_DEPENDS=	p5-Carp-Always>=0.10:${PORTSDIR}/devel/p5-Carp-Always
RUN_DEPENDS=	p5-Carp-Always>=0.10:${PORTSDIR}/devel/p5-Carp-Always

PERL_CONFIGURE=	yes

MAN3=		Carp::Always::Color.3 \
		Carp::Always::Color::HTML.3 \
		Carp::Always::Color::Term.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.30:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
