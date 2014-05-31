# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

# ftp://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/ncbi-blast-2.2.29+-src.tar.gz
PORTNAME=	ncbi-blast
PORTVERSION=	2.2.29
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/
DISTNAME=	${PORTNAME}-${PORTVERSION}+-src

MAINTAINER=	<jwbacon@tds.net>
COMMENT=	Basic Local Alignment Search Tool

WRKSRC=		${WRKDIR}/${DISTNAME}/c++

GNU_CONFIGURE=	yes
USES=		gmake shebangfix
SHEBANG_FILES=	src/app/blast/legacy_blast.pl \
		src/app/blast/update_blastdb.pl \
		src/app/winmasker/windowmasker_2.2.22_adapter.py

USE_GCC=	yes	# openmp

# FIXME: Add depends

# configure chooses /usr/local/bin/ar with no flags
CONFIGURE_ARGS+=AR="ar cr"

# configure script falsely indicates that it supports --mandir and --infodir
# Fix undefined _ThreadRuneLocale on 10.0
post-patch:
	${REINPLACE_CMD} \
		-e "s|-D_THREAD_SAFE|-D_THREAD_SAFE -D__RUNETYPE_INTERNAL|g" \
		${WRKSRC}/src/build-system/configure

post-configure:
	${REINPLACE_CMD} \
		-e 's|$${prefix}|${STAGEDIR}$${prefix}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
