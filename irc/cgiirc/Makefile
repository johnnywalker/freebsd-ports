# New ports collection makefile for:	cgiirc
# Date created:		2005-07-17
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	cgiirc
PORTVERSION=	0.5.10
CATEGORIES=	irc www perl5
MASTER_SITES=	http://cgiirc.org/releases/ \
		SF/${PORTNAME}/cgi-irc/${PORTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	IRC web gateway written in Perl

USE_PERL5=	yes
NO_BUILD=	yes
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING
pre-install:
	@${MV} ${WRKSRC}/cgiirc.config ${WRKSRC}/cgiirc.config.sample 2>/dev/null || true

do-install:
	${MKDIR} ${PREFIX}/www/cgiirc
	${CP} -rp ${WRKSRC}/* ${PREFIX}/www/cgiirc
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/cgiirc
	@[ -f ${PREFIX}/www/cgiirc/cgiirc.config ] || \
	${CP} ${WRKSRC}/cgiirc.config.sample ${PREFIX}/www/cgiirc/cgiirc.config

.include <bsd.port.mk>
