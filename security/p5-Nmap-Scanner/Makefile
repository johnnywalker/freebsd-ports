# New ports collection makefile for:	Nmap-Scanner
# Date created:	   04 July 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Nmap-Scanner
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perform and manipulate nmap scans using perl

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/Class/Generate.pm:${PORTSDIR}/devel/p5-Class-Generate \
		nmap:${PORTSDIR}/security/nmap
RUN_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/Class/Generate.pm:${PORTSDIR}/devel/p5-Class-Generate \
		nmap:${PORTSDIR}/security/nmap

PERL_CONFIGURE=	yes

MAN3=		Nmap::Scanner.3 Nmap::Scanner::Address.3 \
		Nmap::Scanner::Backend::Processor.3 \
		Nmap::Scanner::Backend::Results.3 Nmap::Scanner::ExtraPorts.3 \
		Nmap::Scanner::Host.3 Nmap::Scanner::HostList.3 Nmap::Scanner::Hostname.3 \
		Nmap::Scanner::Hosts.3 Nmap::Scanner::NmapRun.3 \
		Nmap::Scanner::OS.3 Nmap::Scanner::OS::Class.3 \
		Nmap::Scanner::OS::IPIdSequence.3 Nmap::Scanner::OS::Match.3 \
		Nmap::Scanner::OS::PortUsed.3 Nmap::Scanner::OS::TCPSequence.3 \
		Nmap::Scanner::OS::TCPTSSequence.3 Nmap::Scanner::OS::Uptime.3 \
		Nmap::Scanner::Port.3 Nmap::Scanner::PortList.3 Nmap::Scanner::RunStats.3 \
		Nmap::Scanner::RunStats::Finished.3 Nmap::Scanner::ScanInfo.3 \
		Nmap::Scanner::Scanner.3 Nmap::Scanner::Service.3 \
		Nmap::Scanner::OS::Fingerprint.3 Nmap::Scanner::Distance.3 \
		Nmap::Scanner::Task.3 Nmap::Scanner::TaskProgress.3 \
		Nmap::Scanner::Util::BannerScanner.3

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
