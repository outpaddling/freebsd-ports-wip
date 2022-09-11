PORTNAME=	gdc-client
PORTVERSION=	1.2.0
CATEGORIES=	wip ftp python
#MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genomic Data Commons download tool
WWW=		https://gdc.cancer.gov/access-data/gdc-data-transfer-tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}parcel>0:wip/py-parcel \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema

USES=		python:3.6+
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	NCI-GDC

.include <bsd.port.mk>
