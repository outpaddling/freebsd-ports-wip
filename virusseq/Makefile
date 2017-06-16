# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	virusseq
PORTVERSION=	2016.06.10
CATEGORIES=	wip biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
DISTNAME=	VirusSeq-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Detecting known viruses and their integration sites

#LICENSE=	unspecified

USES=		perl5 shebangfix tar:xz
SHEBANG_FILES=	*.pl *.sh

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${WRKSRC}/*.sh ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
