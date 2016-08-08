########################################################################
# Copyright (c) 1988-2016 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 8/7/2016
#
# MacOSX Gcc Makefile for xene xene_cgi Executable
########################################################################
PKG = ../../../../../..

MAK = projects/Makefile/Gcc
PRJ = projects/macosx/Makefile/Gcc
SRC = src

include $(PKG)/$(MAK)/Makedefines
include $(PKG)/$(PRJ)/Makedefines
include $(PKG)/$(MAK)/Makefile
include $(PKG)/$(MAK)/app/xene_cgi/Makefile

#
# target
#
EXETARGET = xene-cgi

########################################################################

#
# user defines
#
USRDEFINES = \
${xene_cgi_USRDEFINES} \

#
# user includes
#
USRINCLUDES = \
${xene_cgi_USRINCLUDES} \

#
# user libdirs
#
USRLIBDIRS = \
${xene_cgi_USRLIBDIRS} \

########################################################################

#
# user c++ flags
#
USRCXXFLAGS = \
${xene_cgi_USRCXXFLAGS} \

#
# user c flags
#
USRCFLAGS = \
${xene_cgi_USRCFLAGS} \

#
# user ld flags
#
USRLDFLAGS = \
${xene_cgi_USRLDFLAGS} \

########################################################################

#
# Executable C sources
#
EXE_C_SOURCES = \
${xene_cgi_EXE_C_SOURCES} \

#
# Executable C++ .cc sources
#
EXE_CC_SOURCES = \
${xene_cgi_EXE_CC_SOURCES} \

#
# Executable C++ .cxx sources
#
EXE_CXX_SOURCES = \
${xene_cgi_EXE_CXX_SOURCES} \

#
# Executable C++ .cpp sources
#
EXE_CPP_SOURCES = \
${xene_cgi_EXE_CPP_SOURCES} \

#
# Executable Objective C .m sources
#
EXE_M_SOURCES = \
${xene_cgi_EXE_M_SOURCES} \

#
# Executable Objective C++ .mm sources
#
EXE_MM_SOURCES = \
${xene_cgi_EXE_MM_SOURCES} \

########################################################################

#
# Executable libs
#
#LIBS = \
#-lsomelib
#
LIBS = \
${xene_cgi_LIBS} \

#
# Executable depends
#
#EXEDEP = \
#$(PKG)/$(BLD)/libsomelib \
#
EXEDEP = \

#
# Executable depend dirs
#
#EXEDEP_DIRS = \
#../libsomelib
#
EXEDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Executable depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#
