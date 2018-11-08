# $FreeBSD$

PORTNAME=	subread
DISTVERSION=	1.6.3
DISTVERSIONSUFFIX=	-source
CATEGORIES=	wip biology
MASTER_SITES=	SF/subread/subread-1.6.3/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	high-performance read alignment, quantification and mutation discovery

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

USES=		gmake

MAKEFILE=	${FILESDIR}/Makefile.pkg
WRKSRC_SUBDIR=	src

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
