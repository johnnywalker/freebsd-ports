# New ports collection makefile for:	p5-Tk-Date
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Tk-Date
PORTVERSION=	0.44
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tk::Date - a date/time widget for perl/Tk

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk/FireButton.pm:${PORTSDIR}/x11-toolkits/p5-Tk-GBARR
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Tk::Date.3

.include <bsd.port.mk>
