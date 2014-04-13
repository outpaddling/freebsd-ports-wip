# New ports collection makefile for:	remmina-plugin-vnc
# Date created:				24 June 2010
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD: ports/net/remmina-plugin-vnc/Makefile,v 1.2 2011/06/05 18:43:10 novel Exp $
#

PORTREVISION=	1
PKGNAMESUFFIX=	-vnc

COMMENT=	Remmina plugin for VNC protocol

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		gnutls:${PORTSDIR}/security/gnutls

MASTERDIR=	${.CURDIR}/../remmina-plugins

.include "${MASTERDIR}/Makefile"
