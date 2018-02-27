# $FreeBSD: head/biology/ncbi-blast+/Makefile 460452 2018-01-31 01:07:07Z jwb $

PORTNAME=	blast+
DISTVERSION=	2.7.1
CATEGORIES=	wip biology
MASTER_SITES=	https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/ \
		https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/${PORTVERSION}/
PKGNAMEPREFIX=	ncbi-
DISTNAME=	ncbi-blast-${PORTVERSION}+-src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI implementation of Basic Local Alignment Search Tool

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/scripts/projects/blast/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		liblmdb.so:databases/lmdb \
		liblzo2.so:archivers/lzo2 \
		libgnutls.so:security/gnutls \
		libtspi.so:security/trousers \
		libgmp.so:math/gmp \
		libidn2.so:dns/libidn2 \
		libnettle.so:security/nettle \
		libhogweed.so:security/nettle \
		libtasn1.so:security/libtasn1 \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils

WRKSRC=		${WRKDIR}/${DISTNAME}/c++

GNU_CONFIGURE=	yes
USES=		compiler:openmp gmake shebangfix perl5 python
SHEBANG_FILES=	src/app/blast/legacy_blast.pl \
		src/app/blast/update_blastdb.pl \
		src/app/winmasker/windowmasker_2.2.22_adapter.py

# MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

# The test for amq can hang, but amq is not needed so just avoid the test
# CONFIGURE_ENV=	ncbi_cv_prog_amq_w=no

# configure chooses /usr/local/bin/ar with no flags
# FreeBSD boost port flagged by configure as untested version
# Conflict with graphics/proj on lib/libproj.a
# --libdir=${PREFIX}/lib/ncbi-tools++ doesn't respect DESTDIR
CONFIGURE_ARGS+=	AR="ar cr" \
			--without-boost

# Fix "undefined _ThreadRuneLocale" error on 10.0
# Fix unknown options in configure
# Add staging support to configure-generated Makefile
post-patch:
	${REINPLACE_CMD} \
		-e 's|-D_THREAD_SAFE|-D_THREAD_SAFE -D__RUNETYPE_INTERNAL|' \
		-e '/--infodir=DIR/d' \
		-e '/--mandir=DIR/d' \
		${WRKSRC}/src/build-system/configure
	${REINPLACE_CMD} -e 's|@prefix@|${STAGEDIR}@prefix@|g' \
		${WRKSRC}/src/build-system/Makefile.in.top

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/*/*/.cvsignore.extra
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ncbi-tools++
	@${MV} ${STAGEDIR}${PREFIX}/lib/lib* \
		${STAGEDIR}${PREFIX}/lib/X11 \
		${STAGEDIR}${PREFIX}/lib/debug \
		${STAGEDIR}${PREFIX}/lib/ncbi-tools++
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ncbi-tools++/*.so

.include <bsd.port.mk>
