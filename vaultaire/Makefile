PORTNAME=	vaultaire
PORTVERSION=	1.1
DISTVERSIONSUFFIX=rc1
CATEGORIES=	wip graphics

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	QT frontend to scanimage and related tools

LICENSE=	APACHE20

# INSTALL_TARGET=	install-strip
USE_QT5=	core gui widgets
USE_GL=		gl
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	vimofthevine

WRKSRC=		${WRKDIR}/Vaultaire-${PORTVERSION}${DISTVERSIONSUFFIX}

PLIST_FILES=	bin/vaultaire \
		share/applications/vaultaire.desktop \
		share/icons/hicolor/scalable/apps/vaultaire.svg

.include <bsd.port.mk>
