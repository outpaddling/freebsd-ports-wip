# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: head/biology/plinkseq/Makefile 369969 2014-10-04 15:12:44Z sunpoet $

PORTNAME=	plinkseq
PORTVERSION=	0.10
CATEGORIES=	biology science
MASTER_SITES=	http://psychgen.u.hpc.mssm.edu/plinkseq_downloads/
DISTFILES=	${PORTNAME}-src-${PORTVERSION}.tgz

MAINTAINER=	jwbacon@tds.net
COMMENT=	Toolset for working with human genetic variation data

LICENSE=	GPLv2

LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USES=		dos2unix libtool shebangfix
#SHEBANG_FILES=	${WRKSRC}/browser/pbrowse.in ${WRKSRC}/index/index.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-protobuf=${LOCALBASE}

WRKSRC=		${WRKDIR}/${DISTNAME}/sources

post-patch:
	#${REINPLACE_CMD} -e 's|PF_INET|AF_INET|g' ${WRKSRC}/browser/mongoose.c
	#${REINPLACE_CMD} -e 's|-ldl||g' \
		#${WRKSRC}/browser/Makefile.in \
		#${WRKSRC}/client/Makefile.in \
		#${WRKSRC}/index/Makefile.in

.include <bsd.port.mk>
