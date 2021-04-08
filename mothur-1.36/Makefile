PORTNAME=	mothur
PORTVERSION=	1.36.1
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bioinformatics tool for the microbial ecology community

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs
RUN_DEPENDS=	uchime>=0:wip/uchime

USES=		gmake ncurses readline

USE_GITHUB=	yes

MAKEFILE=	makefile
ALL_TARGET=	mothur
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mothur

.include <bsd.port.mk>
