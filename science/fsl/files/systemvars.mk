# $Id: systemvars.mk,v 1.1 2004/07/09 13:06:21 duncan Exp $

# System dependent paths

RM = /bin/rm
CHMOD = /bin/chmod
MKDIR = /bin/mkdir
CP = /bin/cp
INSTALL = /usr/bin/install -p
TCLSH = /usr/local/bin/tclsh8.4
RANLIB = /usr/bin/ranlib

FSLML = ${FSLDIR}/bin/fslml

# for SHELL, do not change the type of shell - only use Bourne or BASH
SHELL = /bin/sh

# Compiler dependent variables

CC ?= gcc
CXX ?= g++
CSTATICFLAGS ?= -static
CXXSTATICFLAGS ?= -static
CXXFLAGS += -Wno-deprecated

ARCHFLAGS ?=

DEPENDFLAGS ?= -MM

OPTFLAGS ?= -O ${ARCHFLAGS}
MACHDBGFLAGS ?= -g
GNU_ANSI_FLAGS = -Wall -ansi -pedantic -Wno-long-long
ANSI_FLAGS = ${GNU_ANSI_FLAGS}
