# 
# to do:
# Unbundle udt

PORTNAME=	parcel
PORTVERSION=	0.2.13
DISTVERSIONPREFIX=v
CATEGORIES=	wip ftp python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Combining a UDT network proxy with resumable performant HTTP downloads
WWW=		https://pypi.python.org/pypi/parcel

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# ls wip/
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>0:textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug \
		${PYTHON_PKGNAMEPREFIX}cmd2>0:devel/py-cmd2 \
		${PYTHON_PKGNAMEPREFIX}intervaltree>0:devel/py-intervaltree \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>0:security/py-itsdangerous \
		${PYTHON_PKGNAMEPREFIX}progressbar>0:misc/py-progressbar \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>0:devel/py-sortedcontainers \
		${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor

# Auto-installed in stage dir by setup.py
# Flask-0.10.1-py2.7.egg/
# Jinja2-2.9.5-py2.7.egg/
# MarkupSafe-0.23-py2.7-freebsd-10.3-RELEASE-p11-amd64.egg/
# Werkzeug-0.11.15-py2.7.egg/
# cmd2-0.6.8-py2.7.egg
# easy-install.pth
# intervaltree-2.0.4-py2.7.egg
# itsdangerous-0.24-py2.7.egg/
# parcel-0.1.13-py2.7.egg/
# progressbar-2.3-py2.7.egg
# pyparsing-2.1.10-py2.7.egg
# requests-2.5.1-py2.7.egg/
# sortedcontainers-1.5.7-py2.7.egg
# termcolor-1.1.0-py2.7.egg

USES=		gmake python:3.6+
USE_PYTHON=	distutils
# Temporary hack
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LabAdvComp

# https://lists.freebsd.org/pipermail/freebsd-ports/2013-February/081632.html
# PYEASYINSTALL_ARCHDEP=yes

MAKE_ENV+=	arch=${ARCH} PYTHONPATH=${PYTHONPATH}:${STAGEDIR}/usr/local/lib/python2.7/site-packages/

# https://setuptools.readthedocs.io/en/latest/easy_install.html#custom-installation-locations
# PYDISTUTILS_INSTALLARGS+=	--user

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
