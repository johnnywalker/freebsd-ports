# New ports collection makefile for:	ldapsh
# Date created:				Jul 28 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ldapsh
PORTVERSION=	2.00
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LOOSIFER

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Interactive shell used to administer ldap directories

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Parse/Lex.pm:${PORTSDIR}/devel/p5-ParseLex
RUN_DEPENDS=	${BUILD_DEPENDS}

SUB_FILES=	pkg-message

MAN1=		ldapsh.1
MAN3=		Net::LDAP::Shell.3 Net::LDAP::Config.3 \
		Net::LDAP::Shell::Parse.3 Net::LDAP::Shell::Util.3

PERL_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local/bin/perl,${PERL}," ${WRKSRC}/ldapsh

post-install:
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/COMMANDS ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/ldapsh_config ${EXAMPLESDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
