# New ports collection makefile for:   p5-Image-Delivery
# Date created:                                08 September 2007
# Whom:                                        TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Delivery
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	www graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Efficient transformation and delivery of web images

BUILD_DEPENDS=	p5-Test-ClassAPI>=1.04:${PORTSDIR}/devel/p5-Test-ClassAPI \
		p5-Digest-TransformPath>=0.01:${PORTSDIR}/devel/p5-Digest-TransformPath \
		p5-File-Remove>=0.34:${PORTSDIR}/devel/p5-File-Remove \
		p5-File-Slurp>=9999.04:${PORTSDIR}/devel/p5-File-Slurp \
		p5-HTML-Location>=1.00:${PORTSDIR}/www/p5-HTML-Location \
		p5-Params-Coerce>=0.13:${PORTSDIR}/devel/p5-Params-Coerce
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Image::Delivery.3 Image::Delivery::Provider.3

.include <bsd.port.mk>
