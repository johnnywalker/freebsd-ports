# New ports collection makefile for:	sssnips
# Date created:		Fri Sep 10 16:37:35 EEST 2010
# Whom:			Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sssnips
PORTVERSION=	0.04
CATEGORIES=	misc
MASTER_SITES=	http://devel.ringlet.net/misc/sssnips/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Shell script snippets written by Peter Pentchev

LICENSE=	BSD

PROGRAMS=	bigfile declean getkey hostsearch mkv noagent qidiff qpr \
		signfiles stun switch-link syspower vcr vcrtty ws
PLIST_FILES=	${PROGRAMS:S@^@bin/@}
MAN1=		${PROGRAMS:S/$/.1/}
MANCOMPRESSED=	yes

USE_GMAKE=	1

MAKE_ENV+=	BINGRP=wheel MANDIR=${PREFIX}/man/man

.include <bsd.port.mk>
