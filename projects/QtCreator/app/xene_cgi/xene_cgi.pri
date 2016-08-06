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
#   File: xene_cgi.pri
#
# Author: $author$
#   Date: 8/3/2016
########################################################################

########################################################################
# xene
xene_cgi_HEADERS += \
$${XENE_SRC}/xene/xml/libxml2/libxslt/processor.hpp \
$${XENE_SRC}/xene/xml/libxml2/libxslt/parameters.hpp \
$${XENE_SRC}/xene/xml/libxml2/libxslt/parameter.hpp \
$${XENE_SRC}/xene/xml/xslt/processor.hpp \
$${XENE_SRC}/xene/xml/xslt/extension_module.hpp \
$${XENE_SRC}/xene/xml/xslt/extension_function.hpp \
$${XENE_SRC}/xene/xml/xslt/stylesheet.hpp \
$${XENE_SRC}/xene/xml/xslt/document.hpp \
$${XENE_SRC}/xene/xml/xslt/parameters.hpp \
$${XENE_SRC}/xene/xml/xslt/parameter.hpp \
$${XENE_SRC}/xene/xml/attribute_encoder.hpp \
$${XENE_SRC}/xene/xml/text_encoder.hpp \
$${XENE_SRC}/xene/xml/character_writer.hpp \
$${XENE_SRC}/xene/xml/character_reader.hpp \
$${XENE_SRC}/xene/xml/character_string.hpp \
$${XENE_SRC}/xene/xml/character.hpp \

xene_cgi_SOURCES += \
$${XENE_SRC}/xene/xml/libxml2/libxslt/processor.cpp \
$${XENE_SRC}/xene/xml/libxml2/libxslt/parameters.cpp \
$${XENE_SRC}/xene/xml/libxml2/libxslt/parameter.cpp \
$${XENE_SRC}/xene/xml/xslt/extension_module.cpp \
$${XENE_SRC}/xene/xml/xslt/extension_function.cpp \
$${XENE_SRC}/xene/xml/xslt/stylesheet.cpp \
$${XENE_SRC}/xene/xml/xslt/document.cpp \
$${XENE_SRC}/xene/xml/attribute_encoder.cpp \
$${XENE_SRC}/xene/xml/text_encoder.cpp \
$${XENE_SRC}/xene/xml/character_writer.cpp \
$${XENE_SRC}/xene/xml/character_reader.cpp \
$${XENE_SRC}/xene/xml/character_string.cpp \
$${XENE_SRC}/xene/xml/character.cpp \

########################################################################
# xene
xene_cgi_HEADERS += \
$${XENE_SRC}/xene/fs/path.hpp \
$${XENE_SRC}/xene/io/logger.hpp \
$${XENE_SRC}/xene/io/writer.hpp \
$${XENE_SRC}/xene/io/reader.hpp \
$${XENE_SRC}/xene/base/base.hpp \

xene_cgi_SOURCES += \
$${XENE_SRC}/xene/fs/path.cpp \
$${XENE_SRC}/xene/io/logger.cpp \
$${XENE_SRC}/xene/io/writer.cpp \
$${XENE_SRC}/xene/io/reader.cpp \
$${XENE_SRC}/xene/base/base.cpp \

########################################################################
# xene_cgi
xene_cgi_HEADERS += \
$${XENE_SRC}/xene/app/cgi/xene/main.hpp \
$${XENE_SRC}/xene/app/xene/main.hpp \
$${XENE_SRC}/xene/inet/cgi/main.hpp \

xene_cgi_SOURCES += \
$${XENE_SRC}/xene/app/cgi/xene/main.cpp \

########################################################################
# coral
xene_cgi_HEADERS += \
$${CORAL_SRC}/coral/app/cgi/main.hpp \
$${CORAL_SRC}/coral/inet/cgi/main.hpp \
$${CORAL_SRC}/coral/console/main.hpp \
$${CORAL_SRC}/coral/console/main_main.hpp \

xene_cgi_SOURCES += \
$${CORAL_SRC}/coral/console/main_main.cpp \

########################################################################
# nadir
xene_cgi_HEADERS += \
$${NADIR_SRC}/xos/io/string/writer.hpp \

xene_cgi_SOURCES += \

