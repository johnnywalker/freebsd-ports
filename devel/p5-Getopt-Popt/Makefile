# New ports collection makefile for:	Getopt-Popt
# Date created:	   04 November 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Getopt-Popt
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl interface to the popt(3) library

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include' LIBS'-L${LOCALBASE}/lib'

MAN3=		Getopt::Popt.3

post-patch:
	@${MKDIR} ${WRKSRC}/ex
	@${MV} ${WRKSRC}/example.pl ${WRKSRC}/ex

.include <bsd.port.mk>
