# New ports collection makefile for:	TinyMUX
# Date created:		1998/05/28
# Whom:			cjohnson
#
# $FreeBSD$
#

PORTNAME=	tinymux
PORTVERSION=	2.6.5.${PATCHLEVEL}
PORTREVISION=	2
CATEGORIES=	games net
MASTER_SITES=	GOOGLE_CODE \
		ftp://ftp.tinymux.org/TinyMUX/tinymux-2.6/${PATCHLEVEL}/
DISTNAME=	mux-${PORTVERSION}.unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Multi-Player FreeForm adventure Program

WRKSRC=		${WRKDIR}/mux2.6/src

USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PATCHLEVEL=	32

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^LIBS/s|= @LIBS@|= @LDFLAGS@ @LIBS@|g ; \
		 /^OPTIM/s|=.*|= @CPPFLAGS@|g' ${WRKSRC}/Makefile.in

do-install:
# Binaries
.for file in netmux slave
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/sbin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/../game/bin/dbconvert ${PREFIX}/bin
# Configuration
	${MKDIR} ${ETCDIR}
.for file in alias.conf compat.conf mux.config netmux.conf
	${INSTALL_DATA} ${WRKSRC}/../game/${file} \
		${ETCDIR}/${file}.sample
.endfor
# Data
	${MKDIR} ${DATADIR}/game/netmux
.for file in Backup Startmux _backupflat.sh
	${INSTALL_SCRIPT} ${WRKSRC}/../game/${file} ${DATADIR}/game/netmux/
.endfor
	${MKDIR} ${DATADIR}/game/netmux/data
.for file in db_check db_load db_unload
	${INSTALL_SCRIPT} ${WRKSRC}/../game/data/${file} \
		${DATADIR}/game/netmux/data
.endfor
	${INSTALL_DATA} ${WRKSRC}/../game/data/netmux.db \
		${DATADIR}/game/netmux/data
	${MKDIR} ${DATADIR}/game/netmux/text
.for file in badsite connect create_reg down full guest help motd \
	news newuser plushelp quit register staffhelp wizhelp wizmotd wiznews
	${INSTALL_DATA} ${WRKSRC}/../game/text/${file}.txt \
		${DATADIR}/game/netmux/text
.endfor
# Docs
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ATTACK CHANGES INSTALL NOTES README SGP
	${INSTALL_DATA} ${WRKSRC}/../${file} ${DOCSDIR}
.endfor
.for file in BACKUPS CONFIGURATION CONVERSION CREDITS DISTRIBUTIONS GUESTS \
	LIMITS MEMORY PATCHES REALMS
	${INSTALL_DATA} ${WRKSRC}/../docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
