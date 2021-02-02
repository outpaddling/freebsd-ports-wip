# $FreeBSD$

PORTNAME=	cpac
PORTVERSION=	0.3.9.1
CATEGORIES=	wip python
MASTER_SITES=	http://github.com/FCP-INDI/C-PAC/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Configurable Pipeline for the Analysis of Connectomes

LICENSE=	BSD3CLAUSE

USES=		python:3.6+
USE_PYTHON=	distutils

WRKSRC=		${WRKDIR}/C-PAC-${PORTVERSION}

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nibabel>=0:wip/py-nibabel

# Prereqs from http://fcp-indi.github.io/docs/user/install.html
# Don't assume these are all necessary for CPAC.  For example, cmake is
# a build depend for ANTS, which will not be necessary if ANTS is installed as
# a binary package.  Read the build instructions at the link above before
# adding one of these as a CPAC depend!
#
#    cmake
#    make
#    build
#    git
#    unzip
#    libxp
#    netpbm
#    gcc (with Fortran and C++ compilers and libgfortran)
#    The Python developer libraries
#    lapack and its developer libraries
#    libcanberra (under Linux)
#    The Mesa OpenGL utility library
#    gsl
#    zlib and its developer libraries
#    Graphviz (optional; required for workflow graphs)
#
#
#    SciPy and NumPy
#    Nipype (version 0.10 for versions of C-PAC after 0.3.7, version 0.9.2 for C-PAC versions 0.3.4b, 0.3.5, and 0.3.6)
#    Nibabel
#    NetworkX *
#    Traits *
#    Matplotlib *
#    wxPython
#    PyYAML *
#    Jinja2 *
#    PyLockfile *
#    Cython (version 12.1 or greater) *
#    iPython (optional)
#    PyGraphviz (optional; required for workflow graphs)
#    Patsy
#
#    AFNI
#    FSL
#
# Optional, but recommended
#    C3D
#    ANTS

.include <bsd.port.mk>
