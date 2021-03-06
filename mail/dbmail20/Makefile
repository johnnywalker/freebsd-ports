# New ports collection makefile for:	dbmail
# Date created:				07/26/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dbmail
PORTVERSION=	2.0.11
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/2.0/
PKGNAMESUFFIX=	-${DATABASE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mark_sf@kikg.ifmo.ru
COMMENT=	An SQL database-based mail system (POP3 and IMAP)

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	YES
USE_OPENSSL=	YES
USE_RC_SUBR=	dbmail-pop3d.sh dbmail-lmtpd.sh dbmail-imapd.sh
USE_LDCONFIG=	yes

CFLAGS += -fPIC

.if defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	--with-pgsql
USE_PGSQL=		yes
DATABASE=		postgresql
PLIST_SUB+=		PGSQL=""
PLIST_SUB+=		MYSQL="@comment "
LDFLAGS+=		-L${LOCALBASE}/lib/
.else
USE_MYSQL=		YES
DEFAULT_MYSQL_VER=	51
IGNORE_WITH_MYSQL=	55
CONFIGURE_ARGS+=	--with-mysql
DATABASE=		mysql
PLIST_SUB+=		MYSQL=""
PLIST_SUB+=		PGSQL="@comment "
CFLAGS+=		-I${LOCALBASE}/include/mysql
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
.endif

CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
PORTDOCS=		INSTALL README EXTRAS

MAN1=			dbmail-smtp.1
MAN8=			dbmail-imapd.8 dbmail-lmtpd.8 dbmail-pop3d.8 \
			dbmail-users.8 dbmail-util.8
MANCOMPRESSED=		no
SUB_FILES=		pkg-message

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} "   By default dbmail uses MySQL backend database."
	@${ECHO} "   To build dbmail with PostgreSQL as backend database,"
	@${ECHO} "	define WITH_POSTGRESQL"
	@${ECHO} ""

post-patch:
	@${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -fr
	@${FIND} ${WRKSRC} -name '*.orig' -type f -delete

post-configure:
	@${REINPLACE_CMD} -i.orig 's!/etc/dbmail.conf!${PREFIX}/etc/dbmail.conf!g' \
		${WRKSRC}/dbmail.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${PREFIX}/etc/dbmail.conf-dist
	@${MKDIR} ${DATADIR}/sql
	${INSTALL_DATA} ${WRKSRC}/sql/${DATABASE}/* ${DATADIR}/sql
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
