# ex:ts=8
# New ports collection makefile for:	POE::Filter::XML
# Date created:		Aug 19, 2001
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-XML
PORTVERSION=	1.102960
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE Filter for parsing XML

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Declare>=0:${PORTSDIR}/devel/p5-MooseX-Declare \
		p5-MooseX-InsideOut>=0:${PORTSDIR}/devel/p5-MooseX-InsideOut \
		p5-MooseX-NonMoose>=0:${PORTSDIR}/devel/p5-MooseX-NonMoose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-POE>=1.003:${PORTSDIR}/devel/p5-POE \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-XML-LibXML>=1.69:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-SAX>=0.16:${PORTSDIR}/textproc/p5-XML-SAX

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::XML.3 \
		POE::Filter::XML::Handler.3 \
		POE::Filter::XML::NS.3 \
		POE::Filter::XML::Node.3

.include <bsd.port.mk>
