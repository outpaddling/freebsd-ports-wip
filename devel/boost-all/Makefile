# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD: head/devel/boost-all/Makefile 412346 2016-04-01 14:00:51Z mat $

PORTNAME=	boost-all

USES=		metaport

COMMENT?=	The "meta-port" for boost libraries

OPTIONS_DEFINE=	JAM LIBRARIES PYTHON DOCS
OPTIONS_DEFAULT=	JAM LIBRARIES
JAM_DESC=	Boost.Jam - Build tool from the boost.org
LIBRARIES_DESC=	Free portable C++ libraries
PYTHON_DESC=	Boost.Python - interfacing Python and C++

.include "common.mk"

LIBRARIES_RUN_DEPENDS=	${LOCALBASE}/lib/libboost_thread.so:devel/boost-libs
JAM_RUN_DEPENDS=	${LOCALBASE}/bin/bjam:devel/boost-jam
PYTHON_RUN_DEPENDS=	${LOCALBASE}/lib/libboost_python.so:devel/boost-python-libs
DOCS_RUN_DEPENDS=	${LOCALBASE}/share/doc/boost/doc/html/index.html:devel/boost-docs

.include <bsd.port.mk>
