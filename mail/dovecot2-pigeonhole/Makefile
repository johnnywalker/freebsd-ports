# New ports collection makefile for:	dovecot-pigeonhole
# Date created:		2006-12-29
# Whom:			Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot-pigeonhole
PORTVERSION=	0.2.1
CATEGORIES=	mail
MASTER_SITES=	http://www.rename-it.nl/dovecot/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${PORTVERSION}

MAINTAINER=	bra@fsn.hu
COMMENT=	A Sieve plugin for the Dovecot 'deliver' LDA and LMTP

RUN_DEPENDS=	dovecot>=${DOVECOTVERSION}:${PORTSDIR}/mail/dovecot${DOVECOTVER}

DOVECOTVERSION=	2.0
DOVECOTVER:=	${DOVECOTVERSION:C/\.[0-9]//}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docdir=${DOCSDIR} \
		--with-dovecot="${LOCALBASE}/lib/dovecot"
CONFIGURE_ENV=	LDFLAGS='${LDFLAGS}'
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot

MAN1=		sieve-dump.1 sieve-test.1 sievec.1 sieved.1
MAN7=		pigeonhole.7

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-/\//}

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING COPYING.LGPL INSTALL NEWS README TODO spamtest-virustest.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e '\
		s!/doc/$${PACKAGE_TARNAME}!/doc/${PORTNAME:S/-/\//}!g;\
		s!$${docdir}/dovecot/sieve!$${docdir}!g;\
		' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e '\
		/^docfiles = spamtest-virustest.txt$$/D;\
		/^[[:space:]]+test -z "\$$\(sieve_docdir\)" \|\| \$$\(MKDIR_P\) "\$$\(DESTDIR\)\$$\(sieve_docdir\)"$$/D;\
		' ${WRKSRC}/doc/Makefile.in
	@${LN} -f ${WRKSRC}/doc/spamtest-virustest.txt ${WRKSRC}/

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} ${_SHROWNGRP} -m ${BINMODE} -d ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>