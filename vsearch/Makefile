PORTNAME=		vsearch
DISTVERSIONPREFIX=	v
DISTVERSION=		2.32.0
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Versatile open-source tool for metagenomics
WWW=		https://github.com/torognes/vsearch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	Explicitly enumerated by upstream developers

USES=		autoreconf ghostscript:build gmake localbase
USE_GITHUB=	yes

GH_ACCOUNT=	torognes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vsearch share/bash-completion/completions/vsearch share/fish/vendor_completions.d/vsearch.fish share/zsh/site-functions/_vsearch

.include <bsd.port.mk>
