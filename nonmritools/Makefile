############################################################################
############################################################################
# Metaport for MRI software tools

PORTNAME=	nonmritools
PORTVERSION=	1.0
CATEGORIES=	wip misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Metaport for non-mri software for MRI workstation

RUN_DEPENDS=	setfg:../../misc/setfg

NO_BUILD=	"YES"

# Fetch problem on 3-27-07

OPTIONS=	APE		"Another Programmer's Editor" on \
		THUNDERBIRD	"Mozilla email client" off \
		AUDACITY	"Sound file editor" on \
		RXVT		"Lightweight terminal emulator" on \
		FIREFOX		"Mozilla WEB browser" off \
		NEDIT		"Old graphical editor" on \
		GIMP		"GNU Image Manipulation Program" on \
		GNUPLOT		"Graphing tool" on \
		KRUSADER	"Graphical file manager" on \
		WORDNET		"Dictionary tool for Kdict" off \
		IMAGEMAGICK	"Image editor/converter" on \
		XPDF		"Fast PDF viewer" on \
		GV		"PDF/PS viewer" on \
		XV		"Image viewer/editor" on \
		SCRIBUS		"Desktop publishing program" on \
		ACROREAD	"Adobe (r) Acrobat Reader" on \
		REALPLAYER	"Real Networks (r) RealPlayer" on \
		EMACS		"Text editor" on \
		RSYNC		"Incremental file transfer" on \
		UNIX2DOS	"File converter" on \
		UNIXSTAT	"Command line stats tools" on \
		UNZIP		"Pkunzip compatible unzipper" on \
		WGET		"File transfer tool (like 'fetch')" on \
		ZIP		"Pkzip compatible zipper" on \
		TEX		"Advanced typsetting system" on \
		GINDENT		"Program beautifier" on \
		WEBFONTS	"WEB fonts" on \
		URWFONTS	"urwfonts" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPTIONS +=	PDFTK		"PDF editing tools" on
.endif

.if defined(WITH_PDFTK)
RUN_DEPENDS+=		pdftk:print/pdftk
.endif

.if defined(WITH_KDE)
RUN_DEPENDS+=		kdm:x11/kde3
.endif

.if defined(WITH_APE)
RUN_DEPENDS+=		ape:../../editors/ape
.endif

.if defined(WITH_THUNDERBIRD)
RUN_DEPENDS+=		thunderbird:mail/thunderbird
.endif

.if defined(WITH_AUDACITY)
RUN_DEPENDS+=		audacity:audio/audacity
.endif

.if defined(WITH_RXVT)
RUN_DEPENDS+=		rxvt:x11/rxvt
.endif

.if defined(WITH_FIREFOX)
RUN_DEPENDS+=		firefox:www/firefox
.endif

.if defined(WITH_NEDIT)
RUN_DEPENDS+=		nedit:editors/nedit
.endif

.if defined(WITH_GIMP)
RUN_DEPENDS+=		gimp:graphics/gimp
.endif

.if defined(WITH_GNUPLOT)
RUN_DEPENDS+=		gnuplot:math/gnuplot
.endif

.if defined(WITH_KRUSADER)
RUN_DEPENDS+=		krusader:x11-fm/krusader
.endif

.if defined(WITH_WORDNET)
RUN_DEPENDS+=		wn:textproc/wordnet
.endif

.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=		Magick-config:graphics/ImageMagick
.endif

.if defined(WITH_XPDF)
RUN_DEPENDS+=		xpdf:graphics/xpdf
.endif

.if defined(WITH_GV)
RUN_DEPENDS+=		gv:print/gv
.endif

.if defined(WITH_XV)
RUN_DEPENDS+=		xv:graphics/xv
.endif

.if defined(WITH_SCRIBUS)
RUN_DEPENDS+=		scribus:print/scribus
.endif

.if defined(WITH_REALPLAYER)
RUN_DEPENDS+=		realplay:multimedia/linux-realplayer
.endif

.if defined(WITH_VNC)
RUN_DEPENDS+=		vncviewer:net/vnc
.endif

.if defined(WITH_EMACS)
RUN_DEPENDS+=		emacs:editors/emacs
.endif

.if defined(WITH_RSYNC)
RUN_DEPENDS+=		rsync:net/rsync
.endif

.if defined(WITH_UNIX2DOS)
RUN_DEPENDS+=		unix2dos:converters/unix2dos
.endif

.if defined(WITH_UNIXSTAT)
RUN_DEPENDS+=		anova:math/unixstat
.endif

.if defined(WITH_UNZIP)
RUN_DEPENDS+=		unzip:archivers/unzip
.endif

.if defined(WITH_WGET)
RUN_DEPENDS+=		wget:ftp/wget
.endif

.if defined(WITH_XZGV)
RUN_DEPENDS+=		xzgv:graphics/xzgv
.endif

.if defined(WITH_ZIP)
RUN_DEPENDS+=		zip:archivers/zip
.endif

.if defined(WITH_TEX)
RUN_DEPENDS+=		tex:print/teTeX
.endif

.if defined(WITH_GINDENT)
RUN_DEPENDS+=		gindent:devel/gindent
.endif

.if defined(WITH_WEBFONTS)
RUN_DEPENDS+=		${X11BASE}/lib/X11/fonts/webfonts:x11-fonts/webfonts
.endif

.if defined(WITH_URWFONTS)
RUN_DEPENDS+=		${X11BASE}/lib/X11/fonts/URW:x11-fonts/urwfonts
.endif

.if defined(WITH_) && ${ARCH} == "i386"
RUN_DEPENDS +=	pdftk:print/pdftk
.endif

post-patch:
	${CP} ${FILESDIR}/nonmritools.1 ${WRKDIR}
	${REINPLACE_CMD} -E "s|%%DEPENDS%%|${RUN_DEPENDS}|g" \
		${WRKDIR}/nonmritools.1
	${REINPLACE_CMD} -E "s| *[^ ]*\:/[^/ ]*/[^/ ]*/|, |g" \
		${WRKDIR}/nonmritools.1

do-install:
	@${MKDIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/nonmritools.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
