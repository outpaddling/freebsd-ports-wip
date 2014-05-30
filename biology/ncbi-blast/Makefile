# Created by: Jason Bacon <bacon@freebie.acadix.biz>
# $FreeBSD$

# ftp://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/ncbi-blast-2.2.29+-src.tar.gz
PORTNAME=	ncbi-blast
PORTVERSION=	2.2.29
CATEGORIES=
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/
DISTNAME=	${PORTNAME}-${PORTVERSION}+-src

MAINTAINER=	bacon@freebie.acadix.biz
COMMENT=

WRKSRC=		${WRKDIR}/${DISTNAME}/c++

GNU_CONFIGURE=	yes
USES=		gmake
# openmp
USE_GCC=	yes

# Fix undefined _ThreadRuneLocale on 10.0
post-patch:
	${REINPLACE_CMD} -e "s|g++|${CXX}|g" \
		-e "s|gcc|${CC}|g" \
		-e "s|-D_THREAD_SAFE|-D_THREAD_SAFE -D__RUNETYPE_INTERNAL|g" \
		${WRKSRC}/src/build-system/configure

do-configure:
	echo ${CC}
	cd ${WRKSRC} && ./configure --srcdir=. --without-debug --with-strip --with-openmp --with-mt --with-build-root=./ReleaseMT --prefix=${STAGEDIR}${PREFIX} --build=${ARCH}-portbld-freebsd10.0

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
