# New ports collection makefile for:	p5-IO-Compress-Lzma
# Date created:		2010-07-26
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	IO-Compress-Lzma
PORTVERSION=	2.043
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write lzma files / buffers

BUILD_DEPENDS=	p5-Compress-Raw-Lzma>=2.043:${PORTSDIR}/archivers/p5-Compress-Raw-Lzma \
		p5-IO-Compress>=2.043:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS=	p5-Compress-Raw-Lzma>=2.043:${PORTSDIR}/archivers/p5-Compress-Raw-Lzma \
		p5-IO-Compress>=2.043:${PORTSDIR}/archivers/p5-IO-Compress

PERL_CONFIGURE=	yes

MAN3=		IO::Compress::Lzma.3 IO::Compress::Xz.3 \
		IO::Uncompress::UnLzma.3 IO::Uncompress::UnXz.3

.include <bsd.port.mk>
