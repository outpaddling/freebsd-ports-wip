# New ports collection makefile for:	openfoam
# Date created:		2012-08-23
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freefoam
PORTVERSION=	0.1.2
CATEGORIES=	science math
MASTER_SITES=	SF/freefoam/FreeFOAM/${PORTVERSION}/

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_PYTHON=     yes
PYDISTUTILS_PKGNAME=    FreeFOAM

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Open source computational fluid dynamics toolbox

# FreeFOAM depends: libccmio metis mcgridgen parmetis scotch zlib
# apt-get install # cmake-curses-gui build-essential flex bison zlib1g-dev
# python paraview m4 libreadline-dev libscotch-dev libopenmpi-dev
# ccmio is for Ccm26ToFoam (Star CCM to FOAM converter)

# source $HOME/OpenFOAM/OpenFOAM-2.1.x/etc/bashrc
# export FOAM_INST_DIR=/data/app/OpenFOAM
# foamDotFile=$FOAM_INST_DIR/OpenFOAM-2.1.x/etc/bashrc
# [ -f $foamDotFile ] && . $foamDotFile 

# scotch 5.0.6 doesn't cut it.  Missing SCOTCH_archCmpltw.
# scotch 5.1.2b port builds mpich2 by default
# Use jb-ports scotch for testing

BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison \
		${LOCALBASE}/lib/libscotch.a:../../cad/scotch

# RUN_DEPENDS=	paraview:${PORTSDIR}/science/paraview

.if USE_MPI
BUILD_DEPENDS+=	${LOCALBASE}/lib/parmetis/libmetis.a:${PORTSDIR}/math/parmetis
RUN_DEPENDS+=	-DPARMETIS_metis_LIBRARY=${LOCALBASE}/parmetis/libmetis.a \
		-DPARMETIS_parmetis_LIBRARY=${LOCALBASE}/parmetis/libparmetis.a
.endif

# Need metis 5.0.1, for which the FreeBSD port won't build in a stock 8.3
# or 9.0 ports tree due to the use of new features.  Let FOAM build it's
# own metis for now.
# Build fails with ports flex
CMAKE_ARGS+=	-DFOAM_BUILD_PRIVATE_METIS:BOOL=ON \
		-DFOAM_BUILD_PRIVATE_PARMETIS:BOOL=ON \
		-DSCOTCH_scotcherrexit_LIBRARY=${LOCALBASE}/lib/libscotcherrexit.a \
		-DFOAM_USE_MPI:BOOL=OFF \
		-DFLEX_EXECUTABLE:FILEPATH=/usr/bin/flex

.include <bsd.port.mk>
