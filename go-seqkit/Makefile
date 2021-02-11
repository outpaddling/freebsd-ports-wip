# $FreeBSD$

PORTNAME=		seqkit
DISTVERSIONPREFIX=	v
DISTVERSION=		0.15.0
PKGNAMEPREFIX=		go-
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Cross-platform and ultrafast toolkit for FASTA/Q file manipulation

LICENSE=	MIT
#LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	shenwei356
GH_TUPLE=	mattn:go-colorable:v0.1.8:colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:isatty/vendor/github.com/mattn/go-isatty \
		shenwei356:go-logging:c6b9702:logging/vendor/github.com/shenwei356/go-logging

GO_BUILDFLAGS=	-ldflags '-X main.BuildVersion=${DISTVERSION}'

WRKSRC_SUBDIR=	seqkit

PLIST_FILES=	bin/seqkit

.include <bsd.port.mk>
