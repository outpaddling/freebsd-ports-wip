# Use ?= to allow overriding from the env or command-line, e.g.
#
#       make CXX=c++ CXXFLAGS="-O3 -fPIC" install
#
# Package managers will override many of these variables automatically, so
# this is aimed at making it easy to create packages (Debian packages,
# FreeBSD ports, MacPorts, pkgsrc, etc.)

# Default to the default compiler on all *nix systems
# cc is gcc on GNU/Linux systems, and clang on FreeBSD, macOS, ...
# c++ is g++ on GNU/Linux systems, and clang++ on FreeBSD, macOS, ...
CC	?= cc
CXX	?= c++
# Support for GNU DESTDIR staged installs.  DESTDIR and PREFIX are
# provided by most package managers, so this should work out of the box.
DESTDIR	?= stage
PREFIX	?= /usr/local
MKDIR	?= mkdir
INSTALL	?= install -c
STRIP	?= strip

BINS	= multichoose multipermute cmultichoose

.PHONY: all install install-strip clean

all: ${BINS}

#multichoose_recursive: multichoose_recursive.cpp
#	${CXX} ${LDFLAGS} ${CPPFLAGS} ${CXXFLAGS} multichoose_recursive.cpp -o multichoose_recursive

multichoose: multichoose.cpp multichoose.h
	${CXX} ${LDFLAGS} ${CPPFLAGS} ${CXXFLAGS} multichoose.cpp -o multichoose

multipermute: multipermute.cpp multipermute.h
	${CXX} ${LDFLAGS} ${CPPFLAGS} ${CXXFLAGS} multipermute.cpp -o multipermute

cmultichoose: multichoose.c
	${CC} ${LDFLAGS} ${CPPFLAGS} ${CXXFLAGS} multichoose.c -o cmultichoose

install: all
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	${MKDIR} -p ${DESTDIR}${PREFIX}/include/multichoose
	${INSTALL} ${BINS} ${DESTDIR}${PREFIX}/bin
	${INSTALL} *.py ${DESTDIR}${PREFIX}/bin
	${INSTALL} *.h ${DESTDIR}${PREFIX}/include/multichoose

install-strip: install
	${STRIP} ${DESTDIR}${PREFIX}/bin/*e

clean:
	rm -rf ${BINS} ${DESTDIR}
