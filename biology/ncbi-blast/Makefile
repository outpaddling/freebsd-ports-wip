# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	blast
PORTVERSION=	2.2.29
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/
PKGNAMEPREFIX=	ncbi
DISTNAME=	${PKGNAMEPREFIX}-${PORTNAME}-${PORTVERSION}+-src

MAINTAINER=	jwbacon@tds.net
COMMENT=	NCBI implementation of Basic Local Alignment Search Tool

LICENSE=	Public_domain
LICENSE_NAME=	Public Domain
LICENSE_FILE=	${WRKSRC}/scripts/projects/blast/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libbz2.so:${PORTSDIR}/archivers/bzip2

WRKSRC=		${WRKDIR}/${DISTNAME}/c++

GNU_CONFIGURE=	yes
USES=		gmake shebangfix perl5
SHEBANG_FILES=	src/app/blast/legacy_blast.pl \
		src/app/blast/update_blastdb.pl \
		src/app/winmasker/windowmasker_2.2.22_adapter.py
# Requires openmp
USE_GCC=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes

# configure chooses /usr/local/bin/ar with no flags
# FreeBSD boost port flagged by configure as untested version
CONFIGURE_ARGS+=AR="ar cr" --without-boost

# Fix "undefined _ThreadRuneLocale" error on 10.0
# Add staging support to configure-generated Makefile
post-patch:
	${REINPLACE_CMD} \
		-e "s|-D_THREAD_SAFE|-D_THREAD_SAFE -D__RUNETYPE_INTERNAL|g" \
		${WRKSRC}/src/build-system/configure
	${REINPLACE_CMD} \
		-e 's|@prefix@|${STAGEDIR}@prefix@|g' \
		${WRKSRC}/src/build-system/Makefile.in.top

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
