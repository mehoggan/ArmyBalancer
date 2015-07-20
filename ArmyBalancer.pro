TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

SOURCES += main.cpp \
  armybalancer.cpp \
  beastmenarmy.cpp \
  bretonniaarmy.cpp \
  daemonsofchaoskhornearmy.cpp \
  daemonsofchaosnurglearmy.cpp \
  daemonsofchaosslaanesharmy.cpp \
  daemonsofchaostzeentcharmy.cpp \
  darkelvesarmy.cpp \
  dwarfsarmy.cpp \
  highelvesarmy.cpp \
  lizardmenarmy.cpp \
  ogrekingdomsarmy.cpp \
  orcsandgoblinsarmy.cpp \
  skavenarmy.cpp \
  theempirearmy.cpp \
  tombkingsarmy.cpp \
  vampirecountsarmy.cpp \
  warriorsofchaosarmy.cpp \
  woodelvesarmy.cpp \
    warscrollfactory.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
  armybalancer.h \
  iarmy.h \
  beastmenarmy.h \
  bretonniaarmy.h \
  daemonsofchaoskhornearmy.h \
  daemonsofchaosnurglearmy.h \
  daemonsofchaosslaanesharmy.h \
  daemonsofchaostzeentcharmy.h \
  darkelvesarmy.h \
  dwarfsarmy.h \
  highelvesarmy.h \
  lizardmenarmy.h \
  ogrekingdomsarmy.h \
  orcsandgoblinsarmy.h \
  skavenarmy.h \
  theempirearmy.h \
  tombkingsarmy.h \
  vampirecountsarmy.h \
  warriorsofchaosarmy.h \
  woodelvesarmy.h \
    armies.h \
    warscrollfactory.h

