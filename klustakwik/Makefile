
PORTNAME=	klustakwik
PORTVERSION=	0.3.0.rc3
CATEGORIES=	wip math science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Unsupervised classification of multidimensional continuous data

# LICENSE=	GPLv1

MAKEFILE=	makefile
ALL_TARGET=	#empty

PLIST_FILES=	bin/KlustaKwik

USES=		gmake compiler:openmp

USE_GITHUB=	yes
GH_ACCOUNT=	klusta-team

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KlustaKwik ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
