# New ports collection makefile for:	p5-FreeProxy
# Date created:				10 Oct 2008
# Whom:					Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-FreeProxy
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Fetch proxies from free proxy lists

BUILD_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		WWW::FreeProxy.3 WWW::FreeProxy::Proxy4Free.3 WWW::FreeProxy::Samair.3 WWW::FreeProxy::Look.3 WWW::FreeProxy::PublicProxyServers.3

.include <bsd.port.mk>
