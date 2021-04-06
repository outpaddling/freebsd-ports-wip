
PORTNAME=		ldsc
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.0-92
DISTVERSIONSUFFIX=	-gcf1707e
CATEGORIES=		wip biology

MAINTAINER=	bacon@outpaddling.cs.uwm.edu
COMMENT=	Genomics LD Score Regression (LDSC)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bitarray>0:devel/py-bitarray@${FLAVOR} \
		R:math/R

USES=		perl5 python shebangfix
SHEBANG_FILES=	*.py ldscore/*.py ContinuousAnnotations/quantile_M.pl
USE_GITHUB=	yes
GH_ACCOUNT=	bulik

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/ldsc
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "ldscore ContinuousAnnotations" \
		${STAGEDIR}${PREFIX}/libexec/ldsc)

.include <bsd.port.mk>
