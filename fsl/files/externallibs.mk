# $Id: externallibs.mk,v 1.2 2004/07/13 17:05:32 duncan Exp $

# External Library and Include Paths

FSLEXTLIB=${FSLDIR}/extras/lib
FSLEXTINC=${FSLDIR}/extras/include

LOCALBASE=/usr/local

# CEPHES library
LIB_CEPHES = ${FSLEXTLIB}
INC_CEPHES = ${FSLEXTINC}/cephes

# FFTW library
LIB_FFTW = ${LOCALBASE}/lib
INC_FFTW = ${LOCALBASE}/include

# GD library
LIB_GD = ${LOCALBASE}/lib
INC_GD = ${LOCALBASE}/include

# GDC library (port requires extra gcc install)
LIB_GDC = ${FSLEXTLIB}
INC_GDC = ${FSLEXTINC}/libgdc

# GSL library
LIB_GSL = ${FSLEXTLIB}
INC_GSL = ${FSLEXTINC}/gsl

# PNG library
LIB_PNG = ${LOCALBASE}/lib
INC_PNG = ${LOCALBASE}/include

# PROB library
LIB_PROB = ${FSLEXTLIB}
INC_PROB = ${FSLEXTINC}/libprob

# CPROB library
LIB_CPROB = ${FSLEXTLIB}
INC_CPROB = ${FSLEXTINC}/libcprob

# NEWMAT library
LIB_NEWMAT = ${FSLEXTLIB}
INC_NEWMAT = ${FSLEXTINC}/newmat

# NEWRAN library
LIB_NEWRAN = ${FSLEXTLIB}
INC_NEWRAN = ${FSLEXTINC}/newran

# ZLIB library
LIB_ZLIB = ${LOCALBASE}/lib
INC_ZLIB = ${LOCALBASE}/include

# BOOST library
BOOSTDIR = ${LOCALBASE}
LIB_BOOST = ${BOOSTDIR}/lib
INC_BOOST = ${BOOSTDIR}/include

# QT library
QTDIR = ${X11BASE}
LIB_QT = ${QTDIR}/lib
INC_QT = ${QTDIR}/include

# QWT library
QWTDIR = ${LOCALBASE}
LIB_QWT = ${QWTDIR}/lib
INC_QWT = ${QWTDIR}/include/qwt4
 
# FFTW3 library
LIB_FFTW3 = ${LOCALBASE}/lib
INC_FFTW3 = ${LOCALBASE}/include
