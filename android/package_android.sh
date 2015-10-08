#!/bin/sh

###############################################################################
# The following variables are expected to be exported when this script is
# called.
###############################################################################
#export ANDROID_QTDIR=""
#export ANDROID_NDK_ROOT=""
#export ANDROID_SDK_ROOT=""

export SCRIPT_PATH=$(realpath ${0});
export SCRIPT_DIR=$(dirname ${SCRIPT_PATH});
export BUILD_PATH=$(dirname ${SCRIPT_PATH})/build;
export INSTALL_PATH=$(dirname ${SCRIPT_DIR})/../ArmyBalancerBuild/android-build

export ANDROID_NDK_HOST=linux-x86_64
export ANDROID_NDK_TOOLCHAIN_PREFIX=arm-linux-androideabi
export ANDROID_NDK_TOOLCHAIN_VERSION=4.8
export ANDROID_NDK_TOOLS_PREFIX=arm-linux-androideabi
export ANDROID_SDK_ZIPALIGN_VERSION="22.0.1"

function run_qmake_make_install()
{
  echo "Removing ${BUILD_PATH}"
  rm -rf ${BUILD_PATH}

  mkdir -p ${BUILD_PATH}
  pushd ${BUILD_PATH} &> /dev/null

  echo "Removing ${INSTALL_PATH}"
  rm -rf ${INSTALL_PATH}

  BUILD_OUTPUT_JSON=`pwd`/android-libArmyBalancer.so-deployment-settings.json
  ${ANDROID_QTDIR}/bin/qmake CONFIG+=release -r -spec android-g++ $(dirname ${SCRIPT_PATH})/../ArmyBalancer.pro
  make -j5
  make install INSTALL_ROOT=${INSTALL_PATH}
  ${ANDROID_QTDIR}/bin/androiddeployqt --verbose --release --input ${BUILD_OUTPUT_JSON} --output ${INSTALL_PATH}
  popd &> /dev/null

  rm -rf ${BUILD_PATH}
}

function sign_and_align_apk()
{
  # Note that the key which expires 6 months from September 5, 2015 was generated using.
  #keytool -genkey -v -keystore CARoot.keystore -keyalg RSA -keysize 2048 -alias ArmyBalancer -validity 10000
  DIR=$(realpath `pwd`/../)
  echo "Searching in ${DIR} for apk"
  APK=$(find ${DIR} -name *.apk | grep '\-release');
  echo "apk to sign" ${APK}
  jarsigner -verbose -sigalg SHA1withRSA -digestalg SHA1 -keystore ${SCRIPT_DIR}/CARoot.keystore ${APK} ArmyBalancer
  jarsigner -verify -verbose -certs ${APk} &> /dev/null
  if [[ -e ${SCRIPT_DIR}/ArmyBalancer.apk ]]; then
    rm -f ${SCRIPT_DIR}/ArmyBalancer.apk
  fi
  ${ANDROID_SDK_ROOT}/build-tools/${ANDROID_SDK_ZIPALIGN_VERSION}/zipalign -v 4 ${APK} ${SCRIPT_DIR}/ArmyBalancer.apk &> /dev/null
}

run_qmake_make_install;
sign_and_align_apk;
