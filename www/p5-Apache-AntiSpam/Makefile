# New ports collection makefile for:	p5-Apache-AntiSpam
# Date created:				11 June 2002
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-AntiSpam
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	AntiSpam filter for web pages

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Email/Find.pm:${PORTSDIR}/mail/p5-Email-Find
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=	depends on mod_perl
EXPIRATION_DATE=	2012-01-01

PERL_CONFIGURE=	yes

MAN3=		Apache::AntiSpam.3 \
		Apache::AntiSpam::HTMLEncode.3 \
		Apache::AntiSpam::NoSpam.3 \
		Apache::AntiSpam::Heuristic.3 \

.include <bsd.port.mk>
