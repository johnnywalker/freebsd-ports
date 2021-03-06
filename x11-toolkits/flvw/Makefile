# New ports collection makefile for:   	flvw
# Date created:				17 August 2001
# Whom:                			Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	flvw
PORTVERSION=	20000224
PORTREVISION=	10
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Febrary%20beta
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual Widgets for the Fast Light ToolKit

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}/1.0
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	x11 xt
MAKE_ARGS=	DIRS=src
CONFIGURE_ENV+=	LIBS="`fltk-config --ldflags`"

PLIST_SUB=	INCSDIR="${INCSDIR:S,^${PREFIX}/,,}"

INCSDIR=	${PREFIX}/include/FL

DOC_FILES=	documentation/html/*.html
INC_FILES=	Flv_CStyle.H Flv_Data_Source.H Flv_List.H Flv_Style.H \
		Flv_Table.H Flve_Check_Button.H Flve_Combo.H Flve_Input.H

USE_LDCONFIG=	yes

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	${REINPLACE_CMD} 's/^#define fl_inactive inactive//' \
		${WRKSRC}/FL/Flv_List.H
	${REINPLACE_CMD} 's/\(friend\) \(Flv_Style_List\)/\1 class \2/' \
		${WRKSRC}/FL/Flv_Style.H
	${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/makeinclude.in

post-install: symlink-inc install-doc

symlink-inc:
.for file in ${INC_FILES}
	@${LN} -fs ${file} ${INCSDIR}/${file:R}.${file:E:L}
.endfor

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
