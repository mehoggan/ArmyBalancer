TEMPLATE = app

QT += qml quick widgets opengl
CONFIG += c++11

INCLUDEPATH += ./opengl_core/includes \
  ./opengl_graphics/includes \
  ./opengl_math/includes

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
  glslversionselector.cpp \
  highelvesfaction.cpp \
  khornebloodboundfaction.cpp \
  lizardmenfaction.cpp \
  nurglerotbringersfaction.cpp \
  ogrekingdomsfaction.cpp \
  orcsandgoblinsfaction.cpp \
  skavenfaction.cpp \
  skavenpestilensfaction.cpp \
  stormcasteternalsfaction.cpp \
  sylvanethfaction.cpp \
  tamurkhanshordefaction.cpp \
  theempirefaction.cpp \
  thelegionofazgorhfaction.cpp \
  tombkingsfaction.cpp \
  vampirecountsfaction.cpp \
  warriorsofchaosfaction.cpp \
  woodelvesfaction.cpp \
  warscrollfactory.cpp \
  warscroll.cpp \
  warscrollrelationsgraph.cpp \
  warscrollrelationsgraphscene.cpp \
  warscrollsynergygraph.cpp \
  geometries/projectedrainbow2texturedsquare.cpp \
  geometries/splines.cpp \
  glshaderresourcemanager.cpp \
  gltextureresourcemanager.cpp \
    geometries/ellipse.cpp

RESOURCES += qml.qrc \
    shaders.qrc \
    textures.qrc

#QML_IMPORT_PATH =

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
  glslversionselector.h \
  highelvesfaction.h \
  khornebloodboundfaction.h \
  lizardmenfaction.h \
  nurglerotbringersfaction.h \
  ogrekingdomsfaction.h \
  orcsandgoblinsfaction.h \
  skavenfaction.h \
  skavenpestilensfaction.h \
  stormcasteternalsfaction.h \
  sylvanethfaction.h \
  tamurkhanshordefaction.h \
  theempirefaction.h \
  thelegionofazgorhfaction.h \
  tombkingsfaction.h \
  vampirecountsfaction.h \
  warriorsofchaosfaction.h \
  woodelvesfaction.h \
  factions.h \
  warscrollfactory.h \
  warscroll.h \
  warscrollrelationsgraph.h \
  warscrollrelationsgraphscene.h \
  warscrollsynergygraph.h \
  geometries/geometry.h \
  geometries/projectedrainbow2texturedsquare.h \
  geometries/splines.h \
  glshaderresourcemanager.h \
  gltextureresourcemanager.h \
    geometries/ellipse.h

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

DISTFILES +=
