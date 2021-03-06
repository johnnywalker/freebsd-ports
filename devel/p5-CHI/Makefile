# New ports collection makefile for:	CHI
# Date created:		02 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CHI
PORTVERSION=	0.490
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JSWARTZ
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.49

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for unified cache interface

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Carp-Assert>=0.20:${PORTSDIR}/devel/p5-Carp-Assert \
	p5-Data-UUID>0:${PORTSDIR}/devel/p5-Data-UUID \
	p5-Digest-JHash>0:${PORTSDIR}/security/p5-Digest-JHash \
	p5-Hash-MoreUtils>0:${PORTSDIR}/devel/p5-Hash-MoreUtils \
	p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
	p5-List-MoreUtils>=0.13:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Log-Any>=0.08:${PORTSDIR}/devel/p5-Log-Any \
	p5-Moose>=0.66:${PORTSDIR}/devel/p5-Moose \
	p5-Task-Weaken>0:${PORTSDIR}/devel/p5-Task-Weaken \
	p5-Time-Duration>=1.06:${PORTSDIR}/devel/p5-Time-Duration \
	p5-Time-Duration-Parse>=0.03:${PORTSDIR}/devel/p5-Time-Duration-Parse \
	p5-Try-Tiny>=0.05:${PORTSDIR}/lang/p5-Try-Tiny

PERL_CONFIGURE=	yes

MAN3=	CHI.3 \
	CHI::Benchmarks.3 \
	CHI::CacheObject.3 \
	CHI::Constants.3 \
	CHI::Driver.3 \
	CHI::Driver::Base::CacheContainer.3 \
	CHI::Driver::CacheCache.3 \
	CHI::Driver::Development.3 \
	CHI::Driver::FastMmap.3 \
	CHI::Driver::File.3 \
	CHI::Driver::Memory.3 \
	CHI::Driver::Metacache.3 \
	CHI::Driver::Null.3 \
	CHI::Driver::RawMemory.3 \
	CHI::Driver::Role::Universal.3 \
	CHI::Stats.3

.include <bsd.port.mk>
