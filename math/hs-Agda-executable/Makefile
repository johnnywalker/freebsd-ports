# New ports collection makefile for: hs-Agda-executable
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Agda-executable
PORTVERSION=	2.2.10
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line program for type-checking and compiling Agda programs

CABAL_SETUP=	Setup.hs
USE_CABAL=	Agda>=2.2.10 Agda<2.2.11

USE_ICONV=	yes

EXECUTABLE=	agda
STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
