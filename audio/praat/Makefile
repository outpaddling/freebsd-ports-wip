# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD: audio/praat/Makefile 327706 2013-09-20 14:36:35Z bapt $

PORTNAME=	praat
PORTVERSION=	5.3.59
CATEGORIES=	audio science
# http://www.fon.hum.uva.nl/praat/praat5359_sources.tar.gz
MASTER_SITES=	http://www.fon.hum.uva.nl/praat/
DISTNAME=	praat5359_sources

MAINTAINER=	jwbacon@tds.net
COMMENT=	Phonetics by Computer

LICENSE=	GPLv2

USE_DOS2UNIX=	yes
NO_STAGE=	yes
DOS2UNIX_REGEX=	.*Makefile
USES=		iconv motif
WRKSRC=		${WRKDIR}/sources_5359
MAKEFILE=	makefile
PLIST_FILES=	bin/praat
MAKE_JOBS_UNSAFE=	yes
# CFLAGS+=	-ltinfow

# USE_GCC=	4.5+

LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa

MAN1=		praat.1

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
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/praat.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
