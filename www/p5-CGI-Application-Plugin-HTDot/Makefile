# New ports collection makefile for:	CGI::Application::Plugin::HTDot
# Date created:				05 March 2006
# Whom:					Espen Tagestad <espen@tagestad.no>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-HTDot
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Enable "magic dot" notation in CGI::Application-derived applications

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/HTML/Template/Plugin/Dot.pm:${PORTSDIR}/www/p5-HTML-Template-Pluggable \
		${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::Application::Plugin::HTDot.3

.include <bsd.port.mk>
