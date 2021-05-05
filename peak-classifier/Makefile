# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	peak-classifier
DISTVERSION=	0.0.1-27
DISTVERSIONSUFFIX=	-g16cd294
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Classify ChIP/ATAC-Seq peaks based on features provided in a GFF

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	biolibc>=0.1.1.14:wip/biolibc \
		libxtendc>=0.0.0.1:wip/libxtendc
RUN_DEPENDS=	bedtools:biology/bedtools \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		gsort:sysutils/coreutils	# parallel, much faster

USES=		localbase python:3.7 shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	auerlab
SHEBANG_FILES=	feature-view.py

PLIST_FILES=	bin/peak-classifier \
		bin/filter-overlaps \
		bin/feature-view \
		man/man1/peak-classifier.1.gz \
		man/man1/filter-overlaps.1.gz

pre-build:
	cd ${WRKSRC} && make depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
