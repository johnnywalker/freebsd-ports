# New ports collection makefile for:	nsd
# Date created:				08 August 2002
# Whom:					alexis
#
# $FreeBSD$
#

PORTNAME=	nsd
PORTVERSION=	3.2.8
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/	\
		ftp://ftp.rhnet.is/pub/nsd/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	An authoritative only non-recursive name server

CONFLICTS=	nsd-[0-2]*

USE_RC_SUBR=	nsd

NSDUSER?=	bind
NSDGROUP?=	bind
NSDLSDIR=	/var
NSDDBDIR=	/var/db/nsd
NSDRUNDIR=	/var/run/nsd
NSDMAX_IPS?=	512

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${NSDUSER} \
		--with-configdir=${PREFIX}/etc/nsd \
		--localstatedir=${NSDLSDIR} \
		--with-dbfile=${NSDDBDIR}/nsd.db \
		--with-pidfile=${NSDRUNDIR}/nsd.pid

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	NSDUSER=${NSDUSER} \
		NSDGROUP=${NSDGROUP} \
		NSDDBDIR=${NSDDBDIR} \
		NSDRUNDIR=${NSDRUNDIR}

USE_OPENSSL=	yes

MAN5=	nsd.conf.5
MAN8=	nsd.8 nsdc.8 zonec.8 nsd-checkconf.8 nsd-notify.8 nsd-patch.8 \
	nsd-xfer.8

PORTDOCS=	CREDITS ChangeLog LICENSE NSD-DATABASE NSD-DIFFFILE \
		NSD-FOR-BIND-USERS README README.icc RELNOTES \
		REQUIREMENTS TESTPLAN TODO UPGRADING coding-style \
		differences.tex

OPTIONS=	ROOT_SERVER	"Configure NSD as a root server" Off \
		LARGEFILE	"Enable support for large files" On \
		IPV6		"Enable IPv6 support" On \
		BIND8_STATS	"Enable BIND8 like NSTATS & XSTATS" Off \
		CHECKING	"Enable internal runtime checks" Off \
		NSEC3		"Enable NSEC3 support" On \
		MMAP		"Use mmap instead of malloc(experimental)" Off \
		MAXIPS		"Raise max-ips from 8 to ${NSDMAX_IPS}" Off

.include <bsd.port.pre.mk>

.if defined(WITH_ROOT_SERVER)
CONFIGURE_ARGS+=	--enable-root-server
.endif

.if defined(WITHOUT_LARGEFILE)
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_DNSSEC)
CONFIGURE_ARGS+=	--disable-dnssec
.endif

.if defined(WITH_BIND8_STATS)
CONFIGURE_ARGS+=	--enable-bind8-stats
.endif

.if defined(WITH_CHECKING)
CONFIGURE_ARGS+=	--enable-checking
.endif

.if defined(WITHOUT_TSIG)
CONFIGURE_ARGS+=	--disable-tsig
.endif

.if defined(WITHOUT_NSEC3)
CONFIGURE_ARGS+=	--disable-nsec3
.endif

.if defined(WITHOUT_NSID)
CONFIGURE_ARGS+=	--disable-nsid
.endif

.if defined(WITH_MMAP)
CONFIGURE_ARGS+=	--enable-mmap
.endif

.if defined(WITH_MAXIPS)
CONFIGURE_ARGS+=	--with-max-ips=${NSDMAX_IPS}
.endif

pre-patch:
.if defined(NSD_OPTIONS)
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG} "***** ALERT *****"
	@${ECHO_MSG} "NSD_OPTIONS is no longer supported,"
	@${ECHO_MSG} "${PORTNAME} uses OPTIONS, consider running"
	@${ECHO_MSG} "# make config"
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG}
	@sleep 10
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsd.conf.sample \
		${PREFIX}/etc/nsd/nsd.conf.sample

.if exists(${PREFIX}/etc/nsd/nsd.conf)
	@${ECHO_MSG} "Upgrading to new ixfr.db format if needed"
	${PREFIX}/sbin/nsdc patch
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/${f}
.endfor
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
