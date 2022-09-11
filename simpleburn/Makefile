PORTNAME=	simpleburn
PORTVERSION=	1.8.4
CATEGORIES=	wip sysutils
MASTER_SITES=	http://simpleburn.tuxfamily.org/IMG/gz/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Simple CD burning utility with minimal dependencies
WWW=		https://example.com

# Cecill
LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	cdrecord:sysutils/cdrtools
LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
		libdvdread.so:multimedia/libdvdread \
		libcddb.so:audio/libcddb
RUN_DEPENDS=	cdrecord:sysutils/cdrtools \
		mencoder:multimedia/mencoder

USES=		cmake gettext gnome

USE_GNOME+=	cairo gtk30

INSTALLS_ICONS=	yes

LDFLAGS+=	-rdynamic

# SimpleBurn was designed to have minimal dependencies:

#     GTK3 (default) or GTK2 libs for the interface;
#    burning suite: cdrtools (cdrecord, cdda2wav, mkisofs) / cdrkit (with compatibility symlinks: cdrecord->wodim, cdda2wav->icedax, genisoimage->mkisofs)
#    detection: libdvdread, libcddb, libcdio
#    audio burning and extracting: flac (flac<->wav), mpg123 (mp3->wav), lame (wav->mp3), vorbis-tools (ogg<->wav)
#    video DVD ripping: mencoder with optional xvid and mp3 codec support - simpleburn.sh can be edited to change quality & codecs
#    video / audio preview: gmplayer, gnome-mplayer or smplayer (failback to mplayer)

.include <bsd.port.mk>
