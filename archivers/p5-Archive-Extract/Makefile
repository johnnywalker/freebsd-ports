# New ports collection makefile for:	p5-Archive-Extract
# Date created:				28 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Archive-Extract
PORTVERSION=	0.58
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A generic archive extracting mechanism

MAKE_JOBS_SAFE=	yes
PERL_CONFIGURE=	yes

MAN3=		Archive::Extract.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Module-Load-Conditional>=0.04:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Params-Check>=0.07:${PORTSDIR}/devel/p5-Params-Check
RUN_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Module-Load-Conditional>=0.04:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Params-Check>=0.07:${PORTSDIR}/devel/p5-Params-Check
.endif

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-IPC-Cmd>=0.64:${PORTSDIR}/devel/p5-IPC-Cmd
RUN_DEPENDS+=	p5-IPC-Cmd>=0.64:${PORTSDIR}/devel/p5-IPC-Cmd
.endif

.include <bsd.port.post.mk>
