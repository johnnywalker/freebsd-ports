# New ports collection makefile for:	Iterator-DBI
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Iterator-DBI
PORTVERSION=	0.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An iterator for returning DBI query results

BUILD_DEPENDS=	${SITE_PERL}/Iterator.pm:${PORTSDIR}/devel/p5-Iterator
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	Iterator::DBI.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
