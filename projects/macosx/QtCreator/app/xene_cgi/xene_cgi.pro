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
#   File: xene_cgi.pro
#
# Author: $author$
#   Date: 8/3/2016
########################################################################
include(../../../../../build/QtCreator/libxslt.pri)
include(../../libxslt.pri)
include(../../../../QtCreator/xene.pri)
include(../../xene.pri)
include(../../../../QtCreator/app/xene_cgi/xene_cgi.pri)

TARGET = xene-cgi

INCLUDEPATH += \
$${xene_INCLUDEPATH} \
$${libxslt_INCLUDEPATH} \

DEFINES += \
$${xene_DEFINES} \

########################################################################
HEADERS += \
$${xene_cgi_HEADERS} \

SOURCES += \
$${xene_cgi_SOURCES} \

########################################################################
LIBS += \
$${xene_LIBS} \
$${libxslt_LIBS} \

