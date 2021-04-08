PORTNAME=	miva
PORTVERSION=	2.0
CATEGORIES=	wip science biology
MASTER_SITES=	http://www.neuro.mcw.edu/Ports/distfiles/MIVA/ \
		http://ccni.wpi.edu/downloads/
DISTFILES=	MIVA20BC83Linux_042005a.tar.gz \
		MIVA20BC83Linux_042005c.tar.gz \
		MIVA20BC83Linux_042005d.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Analysis of FMRI Animal Data

USE_LINUX=	yes
NO_BUILD=	yes

OPTIONS=	EXAMPLES	"Install examples"	off

.include <bsd.port.pre.mk>
.if defined(WITH_EXAMPLES)
DISTFILES+=	CWB-examples.tar.gz
.endif
.include <bsd.port.post.mk>
