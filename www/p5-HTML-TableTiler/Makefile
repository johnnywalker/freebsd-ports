# New ports collection makefile for:	www/p5-HTML-TableTiler
# Date created:				October 18th 2003
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-TableTiler
PORTVERSION=	1.21
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Module generate a HTML table from bidimensional array data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/PullParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/IO/Util.pm:${PORTSDIR}/devel/p5-IO-Util
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::TableTiler.3

.include <bsd.port.mk>
