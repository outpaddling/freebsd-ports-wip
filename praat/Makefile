# $FreeBSD: head/audio/praat/Makefile 517040 2019-11-08 09:27:56Z tobik $

PORTNAME=		praat
DISTVERSIONPREFIX=	v
DISTVERSION=		6.1.12
CATEGORIES=		wip audio science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Phonetics by Computer

LICENSE=	GPLv2

USES=		compiler:c++11-lang dos2unix gnome iconv pkgconfig
USE_GNOME=	gtk20
USE_GITHUB=	yes

DOS2UNIX_REGEX=	.*Makefile
PLIST_FILES=	bin/praat man/man1/praat.1.gz

post-patch:
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|' {} \;
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CPPFLAGS =|CPPFLAGS +=|' {} \;
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
