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
#   Date: 8/2/2016
#
# Common Gcc Makefile for xene
########################################################################
XENE_PKG = ${PKG}
XENE_SRC = ${XENE_PKG}/src
XENE_BLD = ${XENE_PKG}/${BLD}/${BUILD_TYPE}
XENE_LIB = ${XENE_BLD}/lib
XENE_BIN = ${XENE_BLD}/bin

########################################################################
# libxslt
libxslt_USRDEFINES += \

libxslt_USRINCLUDES += \
-I${HOME}/build/libxslt/include \
-I${HOME}/build/libxml2/include \
-I${HOME}/build/libxml2/include/libxml2 \

libxslt_USRLIBDIRS += \
-L${HOME}/build/libxslt/lib \
-L${HOME}/build/libxml2/lib \
-L${HOME}/build/zlib/lib \

libxslt_LIBS += \
-lxslt \
-lexslt \
-lxml2 \
-lz \

########################################################################
# nadir
NADIR_PKG = ${XENE_PKG}/../nadir
NADIR_SRC = ${NADIR_PKG}/src
NADIR_BLD = ${NADIR_PKG}/${BLD}/${BUILD_TYPE}
NADIR_LIB = ${NADIR_BLD}/lib
NADIR_BIN = ${NADIR_BLD}/bin

########################################################################
# coral
CORAL_PKG = ${XENE_PKG}/../coral
CORAL_SRC = ${CORAL_PKG}/src
CORAL_BLD = ${CORAL_PKG}/${BLD}/${BUILD_TYPE}
CORAL_LIB = ${CORAL_BLD}/lib
CORAL_BIN = ${CORAL_BLD}/bin

########################################################################
# medusa
MEDUSA_PKG = ${XENE_PKG}/../medusa
MEDUSA_SRC = ${MEDUSA_PKG}/src
MEDUSA_BLD = ${MEDUSA_PKG}/${BLD}/${BUILD_TYPE}
MEDUSA_LIB = ${MEDUSA_BLD}/lib
MEDUSA_BIN = ${MEDUSA_BLD}/bin

########################################################################
# xene
xene_USRDEFINES += \

xene_USRINCLUDES += \
-I${XENE_SRC} \
-I${NADIR_SRC} \

xene_USRCXXFLAGS += \
-std=c++0x

xene_USRLIBDIRS += \
-L${NADIR_LIB} \

xene_LIBS += \
-lxosnadir \

