# New ports collection makefile for:	Mail-Freshmeat
# Date created:				Wed Jan  3 14:42:56 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Freshmeat
PORTVERSION=	1.20
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to parse daily newsletters from freshmeat.net

BROKEN=	does not fetch

PERL_CONFIGURE=	yes
BUILD_DEPENDS=	${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Freshmeat.3

.include <bsd.port.mk>
