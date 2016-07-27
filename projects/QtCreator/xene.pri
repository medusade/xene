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
XENE_PKG = ../../../../..
XENE_BLD = ../..

XENE_PRJ = $${XENE_PKG}
XENE_BIN = $${XENE_BLD}/bin
XENE_LIB = $${XENE_BLD}/lib
XENE_SRC = $${XENE_PKG}/src

CONFIG(debug, debug|release) {
XENE_CONFIG = Debug
} else {
XENE_CONFIG = Release
}

########################################################################
# nadir
NADIR_PKG = $${XENE_PKG}/../nadir
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

########################################################################
# coral
CORAL_PKG = $${XENE_PKG}/../coral
CORAL_PRJ = $${CORAL_PKG}
CORAL_SRC = $${CORAL_PKG}/src

coral_INCLUDEPATH += \
$${CORAL_SRC} \

coral_DEFINES += \

########################################################################
# medusa
MEDUSA_PKG = $${XENE_PKG}/../medusa
MEDUSA_PRJ = $${MEDUSA_PKG}
MEDUSA_SRC = $${MEDUSA_PKG}/src

medusa_INCLUDEPATH += \
$${MEDUSA_SRC} \

medusa_DEFINES += \

########################################################################
# xene
xene_INCLUDEPATH += \
$${XENE_SRC} \
$${medusa_INCLUDEPATH} \
$${coral_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \

xene_DEFINES += \
$${nadir_DEFINES} \
$${coral_DEFINES} \
$${medusa_DEFINES} \

