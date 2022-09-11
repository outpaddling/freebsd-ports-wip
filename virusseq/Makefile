PORTNAME=	virusseq
PORTVERSION=	2016.06.10
CATEGORIES=	wip biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
DISTNAME=	VirusSeq-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Detecting known viruses and their integration sites
WWW=		https://example.com

#LICENSE=	unspecified

USES=		perl5 shebangfix tar:xz
SHEBANG_FILES=	*.pl *.sh

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${WRKSRC}/*.sh ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
