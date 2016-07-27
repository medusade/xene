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
#   File: xene.pri
#
# Author: $author$
#   Date: 7/26/2016
########################################################################

xene_INCLUDEPATH += \
$${xene_INCLUDEPATH} \

xene_DEFINES += \
$${xene_DEFINES} \

########################################################################
# xene
xene_HEADERS += \
$${XENE_SRC}/xene/xml/xslt/processor.hpp \
$${XENE_SRC}/xene/xml/character_writer.hpp \
$${XENE_SRC}/xene/xml/character_reader.hpp \
$${XENE_SRC}/xene/xml/character_string.hpp \
$${XENE_SRC}/xene/xml/character.hpp \

xene_SOURCES += \
$${XENE_SRC}/xene/xml/xslt/processor.cpp \
$${XENE_SRC}/xene/xml/character_writer.cpp \
$${XENE_SRC}/xene/xml/character_reader.cpp \
$${XENE_SRC}/xene/xml/character_string.cpp \
$${XENE_SRC}/xene/xml/character.cpp \

########################################################################
# xene
xene_HEADERS += \
$${XENE_SRC}/xene/app/console/xene/main.hpp \
$${XENE_SRC}/xene/console/main.hpp \
$${XENE_SRC}/xene/console/main_opt.hpp \
$${XENE_SRC}/xene/console/main_main.hpp \

xene_SOURCES += \
$${XENE_SRC}/xene/app/console/xene/main.cpp \
$${XENE_SRC}/xene/console/main_opt.cpp \
$${XENE_SRC}/xene/console/main_main.cpp \

_xene_SOURCES += \

########################################################################
# xene
xene_HEADERS += \
$${XENE_SRC}/xene/io/logger.hpp \
$${XENE_SRC}/xene/io/writer.hpp \
$${XENE_SRC}/xene/io/reader.hpp \
$${XENE_SRC}/xene/base/base.hpp \

xene_SOURCES += \
$${XENE_SRC}/xene/io/logger.cpp \
$${XENE_SRC}/xene/io/writer.cpp \
$${XENE_SRC}/xene/io/reader.cpp \
$${XENE_SRC}/xene/base/base.cpp \

########################################################################
xene_LIBS += \
$${xene_LIBS} \

