TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

SOURCES += main.cpp \
  armybalancer.cpp \
  beastmenfaction.cpp \
  bretonniafaction.cpp \
  daemonsofchaoskhornefaction.cpp \
  daemonsofchaosnurglefaction.cpp \
  daemonsofchaosslaaneshfaction.cpp \
  daemonsofchaostzeentchfaction.cpp \
  darkelvesfaction.cpp \
  dwarfsfaction.cpp \
  highelvesfaction.cpp \
  lizardmenfaction.cpp \
  ogrekingdomsfaction.cpp \
  orcsandgoblinsfaction.cpp \
  skavenfaction.cpp \
  theempirefaction.cpp \
  tombkingsfaction.cpp \
  vampirecountsfaction.cpp \
  warriorsofchaosfaction.cpp \
  woodelvesfaction.cpp \
  warscrollfactory.cpp \
  warscroll.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
  armybalancer.h \
  ifaction.h \
  beastmenfaction.h \
  bretonniafaction.h \
  daemonsofchaoskhornefaction.h \
  daemonsofchaosnurglefaction.h \
  daemonsofchaosslaaneshfaction.h \
  daemonsofchaostzeentchfaction.h \
  darkelvesfaction.h \
  dwarfsfaction.h \
  highelvesfaction.h \
  lizardmenfaction.h \
  ogrekingdomsfaction.h \
  orcsandgoblinsfaction.h \
  skavenfaction.h \
  theempirefaction.h \
  tombkingsfaction.h \
  vampirecountsfaction.h \
  warriorsofchaosfaction.h \
  woodelvesfaction.h \
  factions.h \
  warscrollfactory.h \
  warscroll.h

