# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	rsem
PORTVERSION=	1.2.27
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA-Seq by Expectation-Maximization

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	deweylab
GH_PROJECT=	RSEM
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=		${WRKDIR}/RSEM-${PORTVERSION}

BUILD_DEPENDS+=	samtools01==0.1.19:/usr/wip/biology/samtools0119

.include <bsd.port.mk>
