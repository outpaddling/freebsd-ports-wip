PORTNAME=	multiqc
DISTVERSION=	1.21
CATEGORIES=	wip biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Aggregate bioinformatics analysis reports across samples and tools
WWW=		https://github.com/MultiQC/MultiQC

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich-click>0:wip/py-rich-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0.14.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coloredlogs>0:devel/py-coloredlogs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=5.18:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=10:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=4:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml-env>0:devel/py-pyaml-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lzstring>0:archivers/py-lzstring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spectra>=0.0.10:graphics/py-spectra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colormath>0:math/py-colormath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kiwisolver>0:math/py-kiwisolver@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	multiqc/utils/config.py

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/multiqc/utils/config.py.orig

.include <bsd.port.mk>
