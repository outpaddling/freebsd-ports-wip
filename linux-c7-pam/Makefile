# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD: head/textproc/linux-c7-aspell/Makefile 503741 2019-06-08 15:59:46Z tijl $

PORTNAME=	pam
PORTVERSION=	1.1.8
DISTVERSIONSUFFIX=	-23.el7
CATEGORIES=	wip security

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	OpenJDK

# ??
LICENSE=	LGPL21+

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
