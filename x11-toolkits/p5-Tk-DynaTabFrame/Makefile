# New ports collection makefile for:	p5-Tk-DynaTabFrame
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-DynaTabFrame
PORTVERSION=	0.23
PORTREVISION=	3
CATEGORIES=	x11-toolkits perl5 tk
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	NoteBook widget with orientable, dynamically stacking tabs

BUILD_DEPENDS=	p5-Tk>=804.027:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
