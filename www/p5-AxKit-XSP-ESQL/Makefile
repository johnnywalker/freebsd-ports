# Ports collection Makefile for:		p5-AxKit-XSP-ESQL
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-ESQL
PORTVERSION=	1.4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSERGEANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An Extended SQL taglib for AxKit eXtensible Server Pages

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit \
		${SITE_PERL}/AxKit/XSP/Util.pm:${PORTSDIR}/www/p5-AxKit-XSP-Util \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=	depends on p5-AxKit
EXPIRATION_DATE=	2012-01-01

MAN3=		AxKit::XSP::ESQL.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
