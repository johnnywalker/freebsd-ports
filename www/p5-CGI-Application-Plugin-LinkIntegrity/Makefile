# New ports collection makefile for:	www/p5-CGI-Application-Plugin-LinkIntegrity
# Date created:				15 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-LinkIntegrity
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Make tamper-resisistent links in CGI::Application

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Digest/HMAC.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/CGI/Application/Plugin/AutoRunmode.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-AutoRunmode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	CGI::Application::Plugin::LinkIntegrity.3

.include <bsd.port.mk>
