# New ports collection makefile for:	Test::TCP
# Date created:		20 Feb 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-TCP
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for testing TCP program

RUN_DEPENDS=	\
	p5-Test-SharedFork>=0.14:${PORTSDIR}/devel/p5-Test-SharedFork
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::TCP.3

.include <bsd.port.mk>
