# New ports collection makefile for:	Structures_DataGrid_Renderer_XLS
# Date created:				12 Jan 2008
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid_Renderer_XLS
PORTVERSION=	0.1.3
CATEGORIES=	textproc databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Renderer driver that generates a XLS string

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:${PORTSDIR}/databases/pear-Structures_DataGrid_DataSource_Array \
		${PEARDIR}/Spreadsheet/Excel/Writer.php:${PORTSDIR}/textproc/pear-Spreadsheet_Excel_Writer
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:${PORTSDIR}/databases/pear-Structures_DataGrid_DataSource_Array \
		${PEARDIR}/Spreadsheet/Excel/Writer.php:${PORTSDIR}/textproc/pear-Spreadsheet_Excel_Writer

CATEGORY=	Structures

FILES=		DataGrid/Renderer/XLS.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
