# New ports collection makefile for:	p5-WebService-Validator-HTML-W3C
# Date created:				Oct 10, 2005
# Whom:					toni.viemero@iki.fi
#
# $FreeBSD$
#

PORTNAME=	WebService-Validator-HTML-W3C
PORTVERSION=	0.26
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Access to the W3Cs online HTML validator

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=	WebService::Validator::HTML::W3C::Error.3 \
	WebService::Validator::HTML::W3C.3

.include <bsd.port.mk>
