# $FreeBSD$

PORTNAME=	qctool
DISTVERSION=	2.0.8
CATEGORIES=	wip biology
MASTER_SITES=	https://enkre.net/cgi-bin/code/qctool/tarball/3d76073841/
DISTNAME=	qctool-3d76073841

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Manipulation and quality control of gwas datasets

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		eigen:3 localbase:ldflags python:2.7 waf

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libzstd.so:archivers/zstd

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3
LDFLAGS+=	-L${LOCALBASE}/lib \
		-lboost_unit_test_framework \
		-lboost_filesystem \
		-lboost_iostreams \
		-lboost_thread \
		-lzstd

.include <bsd.port.mk>
