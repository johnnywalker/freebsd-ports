# New ports collection makefile for:	p5-MogileFS-Utils
# Date created:		2007-04-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	MogileFS-Utils
PORTVERSION=	2.21
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MogileFS tools

RUN_DEPENDS=	p5-MogileFS-Client>=1.14:${PORTSDIR}/sysutils/p5-MogileFS-Client \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN1=		mogadm.1 \
		mogdelete.1 \
		mogfetch.1 \
		mogfiledebug.1 \
		mogfileinfo.1 \
		moglistfids.1 \
		moglistkeys.1 \
		mogstats.1 \
		mogtool.1 \
		mogupload.1
MAN3=		MogileFS::Utils.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
