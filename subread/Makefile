PORTNAME=		subread
DISTVERSION=		2.0.2
DISTVERSIONSUFFIX=	-source
CATEGORIES=		wip biology
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance read alignment, quantification and mutation discovery
WWW=		https://bioinf.wehi.edu.au/subread-package/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		gmake localbase:ldflags

MAKEFILE=	${FILESDIR}/Makefile.pkg
WRKSRC_SUBDIR=	src
CFLAGS+=	-fcommon
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
