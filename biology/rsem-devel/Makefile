# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

# FIXME: Should install much more
# https://packages.debian.org/sid/amd64/rsem/filelist
PORTNAME=	rsem
PORTVERSION=	1.2.28
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA-Seq by Expectation-Maximization

LICENSE=	GPLv3

# For bundled samtools, which should be unbundled in the future, when RSEM
# depends only on an unmodified htslib.  Samtools and rsem developers
# are already communicating.
USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	deweylab
GH_PROJECT=	RSEM
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}

.include <bsd.port.mk>
