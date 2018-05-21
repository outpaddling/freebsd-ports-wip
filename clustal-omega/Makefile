# $FreeBSD$

PORTNAME=	clustal-omega
PORTVERSION=	1.2.4
CATEGORIES=	wip biology
MASTER_SITES=	http://www.clustal.org/omega/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Multiple alignment of nucleic acid and protein, replaces clustalw

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libargtable2.so:devel/argtable

USES=		libtool

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
