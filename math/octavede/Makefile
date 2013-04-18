# New ports collection makefile for:	octavede
# Date created:		16 April 2012
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	octavede
PORTVERSION=	0.3
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/OctaveDE/${PORTNAME}-0.3

MAINTAINER=	jwbacon@tds.net
COMMENT=	Octave graphical user interface based on GTK

BUILD_DEPENDS=	octave:${PORTSDIR}/math/octave
LIB_DEPENDS=	glib-2:${PORTSDIR}/devel/glib20 \
		glibmm-2:${PORTSDIR}/devel/glibmm \
		gtkmm-2:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gtksourceview-2:${PORTSDIR}/x11-toolkits/gtksourceview2 \
		gdl-1:${PORTSDIR}/x11-toolkits/gdl \
		xapian.2[0-9]:${PORTSDIR}/databases/xapian-core \
		vte:${PORTSDIR}/x11-toolkits/vte

USE_AUTOTOOLS=	autoconf

MAN1=		octavede.1

.include <bsd.port.mk>
