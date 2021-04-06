
PORTNAME=	seqkit
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=v
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Cross-platform and ultrafast toolkit for FASTA/Q file manipulation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	shenwei356

PLIST_FILES=	bin/seqkit

# Temporary hack until we figure out how to build from downloaded src
do-build:
	export GOPATH=${WRKSRC} && \
		cd ${WRKSRC} && \
		go get -u -v github.com/shenwei356/seqkit/seqkit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/seqkit ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
