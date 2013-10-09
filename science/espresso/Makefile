# New ports collection makefile for:	quantum-espresso
# Date created:		2013-10-06
# Whom:			Jason Bacon <bacon@sculpin.jbacon.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	espresso
PORTVERSION=	5.0.2
CATEGORIES=	science
MASTER_SITES=	http://qe-forge.org/gf/download/frsrelease/116/403/

MAINTAINER=	bacon@sculpin.jbacon.dyndns.org
COMMENT=

GNU_CONFIGURE=	yes
USE_FORTRAN=	yes

# Causes gcc conftests to fail
# CPPFLAGS+=	-P -traditional

LD=	${FC}

post-configure:
	${REINPLACE_CMD} \
		-e 's|CPPFLAGS[ \t]*=|CPPFLAGS = -P -traditional|g' \
		-e "s|/usr/local/bin/ld|${FC}|g" \
		${WRKSRC}/make.sys

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
