# New ports collection makefile for:	Maui
# Date created:		2010-01-11
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	maui
PORTVERSION=	3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://clusterresources.com/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Open source job scheduler for clusters and supercomputers

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	torque.2:${PORTSDIR}/sysutils/torque

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-spooldir=${PREFIX}/maui
#BUILD_ARGS=	-D${OPSYS}

USE_GMAKE=	yes

RESTRICTED=	Must register to download at http://clusterresources.com

# configure sets this, but ports is overriding for some reason
OPSYS=		__FREEBSD

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING) && \
    !exists(${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX})
pre-everything::
	@${PRINTF} "\nPlease register at http://clusterresources.com, download the source code ${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} and place it in ${DISTDIR}.\n\n" | ${FMT}
	@${FALSE}
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's| sed| gsed|g' \
		-e 's|"sed|"gsed|g' \
		-e 's|^sed|gsed|g' \
		-e 's|HP-UX|FreeBSD|g' \
		-e 's|__HPUX|__FREEBSD|g' \
		${WRKSRC}/configure

# Maui Makefiles use bash extensions
pre-install:
	${REINPLACE_CMD} \
		-e 's|/bin/sh|/usr/local/bin/bash|g' \
		${WRKSRC}/src/*/Makefile

.include <bsd.port.post.mk>
