# New ports collection makefile for:	p5-Apache-Filter
# Date created:				March 30th 2001
# Whom:	      				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-Filter
PORTVERSION=	1.024
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to alter the output of previous handlers

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS=	${RUN_DEPENDS}

DEPRECATED=	depends on mod_perl
EXPIRATION_DATE=	2012-01-01

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		Apache::Filter.3 Apache::PerlRunFilter.3 \
		Apache::RegistryFilter.3

.include <bsd.port.mk>
