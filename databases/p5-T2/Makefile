# New ports collection makefile for:	p5-T2
# Date created:	   			19 January 2004
# Whom:		   			Scott McWhirter <scott@surreytech.co.uk>
#
# $FreeBSD$
#

PORTNAME=	T2
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Tangram/SAMV
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object Relational mapping system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Set/Object.pm:${PORTSDIR}/devel/p5-Set-Object \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Tangram.pm:${PORTSDIR}/databases/p5-Tangram \
		${SITE_PERL}/Class/Tangram.pm:${PORTSDIR}/devel/p5-Class-Tangram
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		T2.3 T2::Association.3 T2::Attribute.3 T2::Class.3 \
		T2::DBSetup.3 T2::Method.3 T2::Schema.3 T2::Storage.3

.include <bsd.port.mk>
