PORTNAME=	sra-tools
PORTVERSION=	2.11.0
CATEGORIES=	wip biology
MASTER_SITES=	http://ftp-trace.ncbi.nlm.nih.gov/sra/sdk/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	sratoolkit.${PORTVERSION}-centos_linux64

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools and libraries for using data in the INSDC Sequence Read Archives
WWW=		https://github.com/ncbi/sra-tools

LICENSE=	PD

USES=		linux shebangfix

SHEBANG_FILES=	example/perl/splitfastq.pl example/perl/simplefastq.pl

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/sratoolkit-${PORTVERSION}/bin
	(cd ${WRKSRC}/bin && ${COPYTREE_BIN} \
		. ${STAGEDIR}${PREFIX}/sratoolkit-${PORTVERSION}/bin)
	(cd ${WRKSRC} && ${COPYTREE_BIN} \
		"example README-vdb-config schema CHANGES README-blastn README.md" \
		${STAGEDIR}${PREFIX}/sratoolkit-${PORTVERSION})
	cd ${STAGEDIR}${PREFIX}/sratoolkit-${PORTVERSION}/bin && for f in `ls *.${PORTVERSION}`; do \
		${PRINTF} "#!/compat/linux/bin/bash\n\n${PREFIX}/sratoolkit-${PORTVERSION}/bin/$${f} "'"$$@"'"\n" \
		> ${STAGEDIR}${PREFIX}/bin/`basename $${f%%.${PORTVERSION}}`; \
		${CHMOD} a+rx ${STAGEDIR}${PREFIX}/bin/`basename $${f%%.${PORTVERSION}}`; \
	done

.include <bsd.port.mk>
