# New ports collection makefile for:	Fvwm2
# Date created:		20 Jan 1996
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	fvwm
PORTVERSION=	2.6.3
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Popular virtual window manager for X

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

# Other ports this port cannot coexist with
CONFLICTS?=	fvwm-1.* fvwm-2.[457].*
NO_LATEST_LINK=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X_CFLAGS=-I${LOCALBASE}/include
CONFIGURE_ARGS= --mandir=${MANPREFIX}/man
USE_AUTOTOOLS=	autoconf
USE_GMAKE=	yes
USE_XORG=	xpm xft
USE_BZIP2=	yes
WANT_GNOME=	yes

OPTIONS=	ICONS		"Install default icon set" on \
		ICONV		"Enable iconv character conversion support" on \
		STROKE		"Enable support for mouse gestures" off \
		RPLAY		"Enable RPlay support in FvwmEvent" off \
		SESSION_MGMT	"Enable Session Management support" on \
		PNG		"Build with PNG graphics support" on \
		SVG		"Build with SVG graphics support using librsvg2" off \
		BIDI		"Enable Asian bi-directional text support" off \
		NLS		"Enable National Language Support" on \
		IMLIB		"Enable imlib library (requires gtk12)" off \
		GNOME		"Enable GNOME desktop support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ICONS)
FVWM_ICONS=	fvwm_icons-20070101
DISTFILES+=	${FVWM_ICONS}.tar.bz2
.endif

.if defined(WITHOUT_ICONV)
CONFIGURE_ARGS+=	--disable-iconv
.else
USE_ICONV=		yes
CONFIGURE_ARGS+=	--with-iconv-library=${LOCALBASE}/lib \
			--with-iconv-includes=${LOCALBASE}/include
.endif

.if defined(WITH_STROKE)
LIB_DEPENDS+=	stroke.0:${PORTSDIR}/devel/libstroke
CONFIGURE_ARGS+=	--with-stroke-library=${LOCALBASE}/lib \
			--with-stroke-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-stroke-library
.endif

.if defined(WITH_RPLAY)
LIB_DEPENDS+=	rplay.1:${PORTSDIR}/audio/rplay
CONFIGURE_ARGS+=	--with-rplay-library=${LOCALBASE}/lib \
			--with-rplay-includes=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-rplay-library
.endif

.if defined(WITHOUT_SESSION_MGMT)
CONFIGURE_ARGS+=	--disable-sm
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-png-includes=${LOCALBASE}/include \
			--with-png-library=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-png-library
.endif

.if defined(WITH_SVG) && !defined(WITHOUT_SVG)
USE_GNOME+=	librsvg2
.else
CONFIGURE_ARGS+=	--disable-rsvg
.endif

.if defined(WITHOUT_BIDI)
CONFIGURE_ARGS+=	--disable-bidi
.else
LIB_DEPENDS+=	fribidi.3:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=	--enable-bidi \
			--with-bidi-bindir=${LOCALBASE}/bin
.endif

PLIST_SUB+=	FVWM_VERSION="${PORTVERSION}"

.if defined(WITH_IMLIB) && !defined(WITHOUT_GTK)
USE_GNOME+=	imlib
CONFIGURE_ARGS+=	--enable-gtktest --enable-imlibtest
PLIST_SUB+=	GTK=""
MAN1+=		FvwmGtk.1
.else
CONFIGURE_ARGS+=	--disable-gtktest --disable-imlibtest \
			--with-gtk-prefix=/no/dir --with-imlib-prefix=/no/dir
PLIST_SUB+=	GTK="@comment not installed: "
WITHOUT_GNOME=	true
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--with-intl-library=${LOCALBASE}/lib \
			--with-intl-includes=${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment not installed: "
.endif

.if defined(WITHOUT_GNOME)
CONFIGURE_ARGS+=	--without-gnome
.else
USE_GNOME+=gnomelibs
CONFIGURE_ARGS+=	--with-gnome
.endif

MAN1+=	FvwmAnimate.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 \
	FvwmCommand.1 FvwmConsole.1 FvwmConsoleC.pl.1 FvwmCpp.1 FvwmDebug.1 \
	FvwmDragWell.1 FvwmEvent.1 FvwmForm.1 FvwmIconBox.1 \
	FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmRearrange.1 \
	FvwmSave.1 FvwmSaveDesk.1 FvwmScript.1 FvwmScroll.1 FvwmTaskBar.1 \
	FvwmTheme.1 FvwmWharf.1 FvwmWinList.1 fvwm-menu-desktop.1 \
	fvwm-menu-directory.1 fvwm-menu-headlines.1 fvwm-menu-xlock.1 \
	fvwm.1 fvwm-root.1 fvwm-config.1 fvwm-bug.1 \
	fvwm-convert-2.4.1 fvwm-convert-2.6.1 \
	FvwmPerl.1 fvwm-perllib.1 FvwmProxy.1 FvwmTabs.1 FvwmWindowMenu.1 \
	FvwmGtkDebug.1

MLINKS=	fvwm.1 fvwm2.1 \
	fvwm-root.1 xpmroot.1

.if !defined(WITHOUT_ICONS)
PLIST_SUB+=	ICONS=""
post-extract:
	@${MKDIR} ${WRKDIR}/icons
	@${TAR} -xzf ${DISTDIR}/${FVWM_ICONS}.tar.bz2 -C ${WRKDIR}/icons
.else
PLIST_SUB+=	ICONS="@comment not installed: "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/modules/FvwmM4/FvwmM4.c \
		${WRKSRC}/configure

post-install:
	@${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
		${PREFIX}/etc/system.fvwm2rc.dist
	@if [ ! -e ${PREFIX}/etc/system.fvwm2rc ]; then \
		${INSTALL_DATA} ${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
			${PREFIX}/etc/system.fvwm2rc; \
	fi

.if !defined(WITHOUT_ICONS)
	@${MKDIR} ${PREFIX}/share/fvwm/pixmaps
	${INSTALL_DATA} ${WRKDIR}/icons/${FVWM_ICONS}/*.xpm \
		${PREFIX}/share/fvwm/pixmaps
.endif

.include <bsd.port.post.mk>
