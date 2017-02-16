# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
# 
# to do:
# Unbundle udt

PORTNAME=	parcel
PORTVERSION=	0.2.13
DISTVERSIONPREFIX=v
CATEGORIES=	ftp python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Combining a UDT network proxy with resumable performant HTTP downloads

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# Auto-installed in stage dir by setup.py
# ls /usr/wip/ftp/py-parcel/work/stage/usr/local/lib/python2.7/site-packages/
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
# site.py
# site.pyc
# site.pyo
# sortedcontainers-1.5.7-py2.7.egg
# termcolor-1.1.0-py2.7.egg

USES=		gmake python
USE_PYTHON=	distutils
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LabAdvComp

# https://lists.freebsd.org/pipermail/freebsd-ports/2013-February/081632.html
# PYEASYINSTALL_ARCHDEP=yes

MAKE_ENV+=	arch=${ARCH}
# PYTHONPATH=${STAGEDIR}/usr/local/lib/python2.7/site-packages/

# https://setuptools.readthedocs.io/en/latest/easy_install.html#custom-installation-locations
# PYDISTUTILS_INSTALLARGS+=	--user

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
