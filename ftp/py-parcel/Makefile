# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	parcel
PORTVERSION=	0.2.13
DISTVERSIONPREFIX=v
CATEGORIES=	ftp python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Combining a UDT network proxy with resumable performant HTTP downloads

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python
USE_PYTHON=	distutils
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LabAdvComp

# https://lists.freebsd.org/pipermail/freebsd-ports/2013-February/081632.html
#PYEASYINSTALL_ARCHDEP=yes

MAKE_ENV+=	os=UNIX arch=amd64

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
