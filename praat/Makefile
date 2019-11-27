# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: audio/praat/Makefile 327706 2013-09-20 14:36:35Z bapt $

PORTNAME=	praat
PORTVERSION=	6.1.07
CATEGORIES=	wip audio science
MASTER_SITES=	http://www.fon.hum.uva.nl/praat/
DISTNAME=	praat5359_sources

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Phonetics by Computer

LICENSE=	GPLv2

DOS2UNIX_REGEX=	.*Makefile
USES=		dos2unix iconv motif
WRKSRC=		${WRKDIR}/sources_5359
MAKEFILE=	makefile
PLIST_FILES=	bin/praat man/man1/praat.1.gz

LIB_DEPENDS+=	libasound.so:audio/alsa-lib

post-patch:
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|' "{}" \;
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CPPFLAGS =|CPPFLAGS +=|' "{}" \;
	@${CP} ${FILESDIR}/makefile.defs.freebsd.alsa \
		${WRKSRC}/makefile.defs
	@${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKSRC}|g' \
			  -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/makefile.defs
	@${REINPLACE_CMD} -e 's| log2| NUMlog2|g' \
			  -e 's|feof (f)|feof (f.get_ptr())|g' \
			  -e 's|ferror (f)|ferror (f.get_ptr())|g' \
		${WRKSRC}/dwtools/Sound_extensions.cpp \
		${WRKSRC}/fon/Sound_files.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/praat.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
