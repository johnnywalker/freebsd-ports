# New ports collection makefile for:	kon2 with 16dot font
# Date created:         11 Apr 1997
# Whom:                 Makoto Matsushita <matusita@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kon2
PORTVERSION=	0.3
PORTREVISION=	4
# '+=' is for slave ports
CATEGORIES+=	japanese
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
PKGNAMESUFFIX=	-${KONFONT}
DISTNAME=	kon2-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		k14.bdf 7x14rk.bdf \
		jiskan16.bdf 8x16rk.bdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# '+=' is for slave ports
MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Kanji On Console -- Display kanji characters on your own console

ONLY_FOR_ARCHS=	i386

MAN1=		kon.1
MANLANG=	ja

PORTDOCS=	README README.FreeBSD
DOCDIR=		${PREFIX}/share/doc/kon2

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.if !defined(KONFONT)
KONFONT=16dot
KON16FONT=Startup
.elif (${KONFONT} == "14dot")
KON14FONT=Startup
.elif (${KONFONT} != "16dot")
.BEGIN:
	@${ECHO} "Error: \$${KONFONT} (\"${KONFONT}\") should be either \"14dot\" or \"16dot\"."
	@${FALSE}
.endif

post-extract:
	@${CP} ${WRKSRC}/doc/kon.1 ${WRKSRC}/src/

pre-build:
	${SED} -e 's,%%PREFIX%%,${PREFIX},' \
	  -e 's,%%DISTDIR%%,${DISTDIR},' \
	  ${FILESDIR}/dotconfig > ${WRKSRC}/.config
	@(cd ${WRKSRC}; ${MAKE} -f Makefile.FreeBSD config)
	@for i in kon.cfg.FreeBSD doc/kon.1; do\
		${MV} -f ${WRKSRC}/$${i} ${WRKSRC}/$${i}.in ;\
		${SED} -e "s;@@PREFIX@@;${PREFIX};g" -e "s;@@KON16FONT@@;${KON16FONT};g" -e "s;@@KON14FONT@@;${KON14FONT};g" ${WRKSRC}/$${i}.in > ${WRKSRC}/$${i} ;\
	done

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/kon.1 ${PREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCDIR}
.endif

.include <bsd.port.post.mk>
