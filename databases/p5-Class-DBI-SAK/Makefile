# New ports collection makefile for:	p5-Class-DBI-SAK
# Date created:	   22 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-SAK
PORTVERSION=	1.4
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class::DBI Swiss Army Knife (SAK)

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/mixin.pm:${PORTSDIR}/devel/p5-mixin
RUN_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/Class/DBI/AbstractSearch.pm:${PORTSDIR}/databases/p5-Class-DBI-AbstractSearch \
		${SITE_PERL}/Class/DBI/Pager.pm:${PORTSDIR}/databases/p5-Class-DBI-Pager

PERL_MODBUILD=	yes

MAN3=		Class::DBI::SAK.3

.include <bsd.port.mk>
