# New ports collection makefile for:	p5-Apache-DBI-mp1
# Date created:			                28 Aug 2008
# Whom:					                Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBI
PKGNAMESUFFIX=	-mp1

COMMENT=	DBI persistent connection, authentication and authorization (mp1)

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=	yes

MASTERDIR=	${.CURDIR}/../p5-Apache-DBI

.if defined(WITH_MODPERL2) || defined(WITHOUT_MODPERL)
IGNORE=		this port is only for use with www/mod_perl
.endif

WITH_MODPERL=	yes
USE_APACHE=	13

.include "${MASTERDIR}/Makefile"
