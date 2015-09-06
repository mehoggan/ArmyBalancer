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

win32 {
    home_dir = $$(HOMEDRIVE)$$(HOMEPATH)
    CONFIG(debug, debug|release) {
    } else {
    contains(QMAKE_HOST.arch, x86_64) {
      QMAKE_POST_LINK += set PATH=%PATH%;C:\Qt\5.4\msvc2013_64_opengl\bin & \
        C:\Qt\5.4\msvc2013_64_opengl\bin\windeployqt.exe $$home_dir\Devel\ArmyBalancer\release\ArmyBalancer.exe
    } else {
      QMAKE_POST_LINK += set PATH=%PATH%;C:\Qt\5.4\msvc2013_opengl\bin & \
        C:\Qt\5.4\msvc2013_opengl\bin\windeployqt.exe $$home_dir\Devel\ArmyBalancer\release\ArmyBalancer.exe
    }
  }
}

android {
  message("Unix Android Called")
  DISTFILES += \
      android/AndroidManifest.xml \
      android/gradle/wrapper/gradle-wrapper.jar \
      android/gradlew \
      android/res/values/libs.xml \
      android/build.gradle \
      android/gradle/wrapper/gradle-wrapper.properties

  ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
}
