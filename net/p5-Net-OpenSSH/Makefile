# New ports collection makefile for:	p5-Net-OpenSSH
# Date created:		2009-01-13
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenSSH
PORTVERSION=	0.52
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	Perl SSH client package implemented on top of OpenSSH

BUILD_DEPENDS=	p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::OpenSSH::Constants.3 \
	Net::OpenSSH.3

.include <bsd.port.mk>
