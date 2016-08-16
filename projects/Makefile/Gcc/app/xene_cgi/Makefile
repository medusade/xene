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
# Generic Gcc Makefile for xene xene_cgi Executable
########################################################################

#
# user defines
#
xene_cgi_USRDEFINES += \
${xene_USRDEFINES} \
${libxslt_USRDEFINES} \

#
# user includes
#
xene_cgi_USRINCLUDES += \
${xene_USRINCLUDES} \
-I${MEDUSA_SRC} \
-I${CORAL_SRC} \
${libxslt_USRINCLUDES} \

#
# user libdirs
#
xene_cgi_USRLIBDIRS += \
${xene_USRLIBDIRS} \
-L${MEDUSA_LIB} \
-L${CORAL_LIB} \
${libxslt_USRLIBDIRS} \

#
# Executable libs
#
xene_cgi_LIBS += \
${xene_LIBS} \
-lmedusa \
-lcoral \
${libxslt_LIBS} \

########################################################################

#
# user c++ flags
#
xene_cgi_USRCXXFLAGS += \
${xene_USRCXXFLAGS} \

#
# user ld flags
#
xene_cgi_USRLDFLAGS += \
${xene_USRLDFLAGS} \

########################################################################

#
# Executable C++ .cpp sources
#
xene_cgi_EXE_CPP_SOURCES += \
${XENE_SRC}/xene/fs/path.cpp \
${XENE_SRC}/xene/io/logger.cpp \
${XENE_SRC}/xene/io/writer.cpp \
${XENE_SRC}/xene/io/reader.cpp \
${XENE_SRC}/xene/base/base.cpp \

xene_cgi_EXE_CPP_SOURCES += \
${XENE_SRC}/xene/xml/libxml2/libxslt/processor.cpp \
${XENE_SRC}/xene/xml/libxml2/libxslt/parameters.cpp \
${XENE_SRC}/xene/xml/libxml2/libxslt/parameter.cpp \
${XENE_SRC}/xene/xml/xslt/extension_module.cpp \
${XENE_SRC}/xene/xml/xslt/extension_function.cpp \
${XENE_SRC}/xene/xml/xslt/stylesheet.cpp \
${XENE_SRC}/xene/xml/xslt/document.cpp \
${XENE_SRC}/xene/xml/attribute_encoder.cpp \
${XENE_SRC}/xene/xml/text_encoder.cpp \
${XENE_SRC}/xene/xml/character_writer.cpp \
${XENE_SRC}/xene/xml/character_reader.cpp \
${XENE_SRC}/xene/xml/character_string.cpp \
${XENE_SRC}/xene/xml/character.cpp \

xene_cgi_EXE_CPP_SOURCES += \
${XENE_SRC}/xene/app/cgi/xene/main.cpp \
${CORAL_SRC}/coral/console/main_main.cpp \

