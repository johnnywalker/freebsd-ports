# New ports collection makefile for:	Apache-Test
# Date created:	   05 July 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-Test
PORTVERSION=	1.36
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PHRED
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test.pm wrapper with helpers for testing Apache

MAKE_JOBS_SAFE=	yes
PERL_CONFIGURE=	yes

# Changed to apache13 exclusive, else apache13 ports
# are broken if apache22 is set as default
USE_APACHE=	13
.include <bsd.port.pre.mk>

## XXX: www/mod_perl2 currently @2.0.5 contains A-T 1.36,
.if defined(WITH_MODPERL2) || ${APACHE_VERSION} > 13
IGNORE=		is already included in mod_perl2
.endif

MAN3=		Apache::Test.3 \
		Apache::TestConfig.3 \
		Apache::TestMB.3 \
		Apache::TestMM.3 \
		Apache::TestReport.3 \
		Apache::TestRequest.3 \
		Apache::TestRun.3 \
		Apache::TestRunPHP.3 \
		Apache::TestRunPerl.3 \
		Apache::TestServer.3 \
		Apache::TestSmoke.3 \
		Apache::TestTrace.3 \
		Apache::TestUtil.3 \
		Bundle::ApacheTest.3

.include <bsd.port.post.mk>
