# New ports collection makefile for:	p5-Net-GeoPlanet
# Date created:				2008-08-05
# Whom:					Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	Net-GeoPlanet
PORTVERSION=	0.2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Access Yahoo's GeoPlanet location service

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-Test-Simple>=0.74:${PORTSDIR}/devel/p5-Test-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::GeoPlanet.3

.include <bsd.port.mk>
