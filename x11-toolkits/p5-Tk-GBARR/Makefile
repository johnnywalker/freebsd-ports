# New ports collection makefile for:	p5-Tk-GBARR
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Tk-GBARR
PORTVERSION=	2.08
PORTREVISION=	2
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Some collection of Tk Widgets

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Tk::Cloth.3 \
		Tk::FireButton.3 \
		Tk::NumEntry.3 \
		Tk::NumEntryPlain.3 \
		Tk::TFrame.3

.include <bsd.port.mk>
