# Ports collection makefile for:    netatalk
# Date created:         4 Jul 2011
# Whom:                 jdw
#
# $FreeBSD$
#

PORTNAME=	netatalk
PORTVERSION=	2.2-beta4
PORTEPOCH=	1
CATEGORIES=	net print
MASTER_SITES=	SF

MAINTAINER=	kallous@gmail.com
COMMENT=	File server for Mac OS X

USE_AUTOTOOLS=	libtool
USE_BDB=	46+
USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	netatalk


LIB_DEPENDS=	gcrypt.>=15::security/libgcrypt \
		avahi::net/avahi \
		dbus-1::devel/dbus

CONFIGURE_ARGS+=	--with-pkgconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--with-libiconv=${LOCALBASE}
CONFIGURE_ARGS+=	--with-libgcrypt-dir=${LOCALBASE}
CONFIGURE_ARGS+=	--with-uams-path=${PREFIX}/libexec/netatalk-uams
CONFIGURE_ARGS+=	--with-bdb=${LOCALBASE}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-ssl-dir=/usr
CONFIGURE_ARGS+=	--disable-overwrite
CONFIGURE_ARGS+=	--disable-cups

FILES=		AppleVolumes.default AppleVolumes.system afpd.conf \
	        netatalk.conf
LINKS=		unbin unhex unsingle hqx2bin single2bin macbinary \
		binheader nadheader
MAN1=		ad.1 afpldaptest.1 afppasswd.1 \
		apple_dump.1 asip-status.pl.1 dbd.1 \
		hqx2bin.1 macbinary.1 megatron.1 \
		netatalk-config.1 \
		single2bin.1 unbin.1 unhex.1 uniconv.1 unsingle.1
MAN5=		AppleVolumes.5 AppleVolumes.default.5 \
		AppleVolumes.system.5 afp_ldap.conf.5 afp_signature.conf.5 \
		afpd.conf.5 netatalk.conf.5
MAN8=		afpd.8 cnid_dbd.8 cnid_metad.8 \
		timelord.8

CONFLICTS=	bigloo-2.* cap-6.0.* tct-1.* netatalk-1* yudit-[0-9]*

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%DB_NAME%%|${BDB_INCLUDE_DIR:T}| ; \
	    	s|%%DB_LIB%%|-l${BDB_LIB_NAME}|g' \
		${WRKSRC}/configure

post-install:
	@${RM} -f ${PREFIX}/bin/nu ${PREFIX}/bin/lp2pap.sh \
		${PREFIX}/bin/test_parse_mtab \
		${PREFIX}/bin/afpd-mtab.pl
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/macusers/macusers \
		${PREFIX}/bin/macusers
.for i in ${FILES}
	[ -f ${PREFIX}/etc/${i} ] || \
		${INSTALL_DATA} -c ${PREFIX}/etc/${i}.dist ${PREFIX}/etc/${i}
.endfor
.for i in ${LINKS}
	( cd ${PREFIX}/bin && ${LN} -sf megatron ${i} )
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
