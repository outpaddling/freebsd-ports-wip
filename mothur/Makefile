PORTNAME=	mothur
PORTVERSION=	1.40.5
DISTVERSIONPREFIX=v
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bioinformatics tool for the microbial ecology community

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs
RUN_DEPENDS=	uchime>=0:wip/uchime

USES=		gmake ncurses readline

USE_GITHUB=	yes

#MAKEFILE=	makefile
ALL_TARGET=	mothur
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mothur

post-extract:
	@${REINPLACE_CMD} -e "s|thread[*]|std::thread*|g" \
		`find ${WRKSRC} -name '*.cpp'`
	${REINPLACE_CMD} -e 's|new thread(|new std::thread(|g' \
                `find ${WRKSRC} -name '*.cpp'`

# Builds after:
#make clean
#make extract
#root@freebsd11:/usr/ports/wip/mothur-1.40.5 # sed -i '' -e "s|thread[*]|std::thread*|g" `find work -name '*.cpp'`
#root@freebsd11:/usr/ports/wip/mothur-1.40.5 # sed -i '' -e "s| thread(| std::thread(|g" `find work -name '*.cpp'`
#make
.include <bsd.port.mk>
