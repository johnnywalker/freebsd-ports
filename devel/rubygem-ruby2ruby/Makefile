# New ports collection makefile for:	rubygem-ruby2ruby
# Date created:		2007-09-28
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	ruby2ruby
PORTVERSION=	1.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A pure ruby code generator easily from ParseTree's Sexps # '

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sexp_processor>=3.0:${PORTSDIR}/devel/rubygem-sexp_processor \
		rubygem-ruby_parser>=2.0:${PORTSDIR}/devel/rubygem-ruby_parser

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/r2r_show

.include <bsd.port.mk>
