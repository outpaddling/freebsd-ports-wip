
PORTNAME=	plasm
PORTVERSION=	0.1
CATEGORIES=	wip devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Portable Assembler

RUN_DEPENDS=	papp:wip/papp

USES=		tar:xz
.include <bsd.port.pre.mk>
.if ${ARCH} == "powerpc"
USE_GCC=	yes
.endif

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/plasm \
		bin/plasm.bin \
		include/plasm-epc-bits.h \
		man/man1/plasm.1.gz

pre-build:
	make depend

.include <bsd.port.post.mk>
