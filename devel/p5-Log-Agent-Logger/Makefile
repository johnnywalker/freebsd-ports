# New ports collection makefile for:	Log-Agent-Logger
# Date created:		4 Aug 2002
# Whom:			devin@spamcop.net
#
# $FreeBSD$
#

PORTNAME=	Log-Agent-Logger
PORTVERSION=	0.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TBONE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log::Agent::Logger - a logging interface for perl

BUILD_DEPENDS=	${SITE_PERL}/Log/Agent.pm:${PORTSDIR}/devel/p5-Log-Agent \
		${SITE_PERL}/Getargs/Long.pm:${PORTSDIR}/devel/p5-Getargs-Long
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Log::Agent::Logger.3

.include <bsd.port.mk>
