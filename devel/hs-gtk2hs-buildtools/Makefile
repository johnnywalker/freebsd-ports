# New ports collection makefile for:	hs-gtk2hs-buildtools
# Date created:		March 13, 2011
# Whom:			haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtk2hs-buildtools
PORTVERSION=	0.12.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tools to build the Gtk2Hs suite of User Interface Libraries

LICENSE=	GPLv2
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_ALEX=	yes
USE_HAPPY=	yes

STANDALONE=	yes
EXECUTABLE=	gtk2hsTypeGen gtk2hsHookGenerator gtk2hsC2hs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
