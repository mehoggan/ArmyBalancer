import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Rectangle
{
  property alias spinBox: unitCapSetter

  function setWarScrollTitleName(name)
  {
    warScrollTitle.text = name
  }

  function setMinMaxUnitCount(min, max)
  {
    unitCapSetter.minimumValue = Math.max(0, min)
    unitCapSetter.maximumValue = max
    unitCapSetter.value = unitCapSetter.minimumValue;
  }

  function addArsenalUpgrades(aList)
  {
    aWarScrollUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollUpgradeModel.append({'name' : aList[i]});
    }

    if (aList.length === 0) {
      aresenalRect.visible = false
      aresenalRect.height = 0
    } else {
      aresenalRect.visible = true
      aresenalRect.height = 0.25 * aresenalRect.parent.height
    }
  }

  function addUnitUpgrades(aList)
  {
    aWarScrollUnitUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollUnitUpgradeModel.append({'name' : aList[i]});
    }

    if (aList.length === 0) {
      unitRect.visible = false
      unitRect.height = 0
    } else {
      unitRect.visible = true
      unitRect.height = 0.25 * unitRect.parent.height
    }
  }

  function addMountUpgrades(aList)
  {
    aWarScrollMountUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollMountUpgradeModel.append({'name' : aList[i]});
    }

    if (aList.length === 0) {
      mountRect.visible = false
      mountRect.height = 0
    } else {
      mountRect.visible = true
      mountRect.height = 0.25 * mountRect.parent.height
    }
  }

  function addChampionOption(aList)
  {
    aWarScrollChampionUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollChampionUpgradeModel.append({'name' : aList[i]});
    }

    if (aList.length === 0) {
      championRect.visible = false
      championRect.height = 0
    } else {
      championRect.visible = true
      championRect.height = 0.25 * championRect.parent.height
    }
  }

  function addMagicSpecializations(aList)
  {
    aWarScrollMagicalSpecializationUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollMagicalSpecializationUpgradeModel.append({'name' : aList[i]});
    }

    if (aList.length === 0) {
      magicalSpecializationRect.visible = false
      magicalSpecializationRect.height = 0
    } else {
      magicalSpecializationRect.visible = true
      magicalSpecializationRect.height =
        0.25 * magicalSpecializationRect.parent.height
    }
  }

  function finalizeWarScroll()
  {
    var data = {}
    var count = unitCapSetter.value
    data["unitCount"] = count;

    var arsenalUgradeList = aWarScrollUpgradeView;
    var itemSelected = false;
    for (var i = 0; i < arsenalUgradeList.count; ++i)
    {
      var arsenalItem = arsenalUgradeList.contentItem.children[i];
      var arsenalChi1 = arsenalItem.children[0];
      var arsenalChi2 = arsenalChi1.children[0];
      var arsenalChi3 = arsenalChi2.children[0];
      var arsenalChi4 = arsenalChi3.children[0];
      if (arsenalChi4.checked) {
        itemSelected = true;
        var arsenalUpgradeName = arsenalChi3.text
        data["weaponUpgrade"] = arsenalUpgradeName
        break;
      }
    }

    if (!itemSelected && arsenalUgradeList.count > 0) {
      var arsenalItemTest = arsenalUgradeList.contentItem.children[0];
      var arsenalChi1Test = arsenalItemTest.children[0];
      var arsenalChi2Test = arsenalChi1Test.children[0];
      var arsenalChi3Test = arsenalChi2Test.children[0];
      var arsenalChi4Test = arsenalChi3Test.children[0];
      var arsenalUpgradeNameTest = arsenalChi3Test.text
      data["weaponUpgrade"] = arsenalUpgradeNameTest
    }

    var unitUpgradeList = aWarScrollUnitUpgradeView
    for (var j = 0; j < unitUpgradeList.count; ++j)
    {
      var unitUpgradeItem = unitUpgradeList.contentItem.children[j];
      var unitUpgradeChi1 = unitUpgradeItem.children[0];
      var unitUpgradeChi2 = unitUpgradeChi1.children[0];
      var unitUpgradeChi3 = unitUpgradeChi2.children[0];
      var unitUpgradeChi4 = unitUpgradeChi3.children[0];
      if (unitUpgradeChi4.checked) {
        var unitUpgradeName = unitUpgradeChi3.text
        data["unitUpgrade" + j] = unitUpgradeName
      }
    }

    var mountUgradeList = aWarScrollMountUpgradeView;
    var moustSelected = false;
    for (var k = 0; k < mountUgradeList.count; ++k)
    {
      var mountItem = mountUgradeList.contentItem.children[k];
      var mountChi1 = mountItem.children[0];
      var mountChi2 = mountChi1.children[0];
      var mountChi3 = mountChi2.children[0];
      var mountChi4 = mountChi3.children[0];
      if (mountChi4.checked) {
        itemSelected = true;
        var mountUpgradeName = mountChi3.text
        data["mountUpgrade"] = mountUpgradeName
        break;
      }
    }

    var championUgradeList = aWarScrollChampionUpgradeView;
    for (var k = 0; k < championUgradeList.count; ++k)
    {
      var championItem = championUgradeList.contentItem.children[k];
      var championChi1 = championItem.children[0];
      var championChi2 = championChi1.children[0];
      var championChi3 = championChi2.children[0];
      var championChi4 = championChi3.children[0];
      if (championChi4.checked) {
        itemSelected = true;
        var championUpgradeName = championChi3.text
        data["championUpgrade"] = championUpgradeName
        break;
      }
    }

    var magicUpgradeList = aWarScrollMagicalSpecializationUpgradeView;
    var magicSelected = false;
    for (var l = 0; l < magicUpgradeList.count; ++l)
    {
      var magicItem = magicUpgradeList.contentItem.children[l];
      var magicChi1 = magicItem.children[0];
      var magicChi2 = magicChi1.children[0];
      var magicChi3 = magicChi2.children[0];
      var magicChi4 = magicChi3.children[0];
      if (magicChi4.checked) {
        magicSelected = true;
        var magicUpgradeName = magicChi3.text
        data["magicUpgrade"] = magicUpgradeName
        break;
      }
    }

    if (!magicSelected && magicUpgradeList.count > 0) {
      var magicItemTest = magicUpgradeList.contentItem.children[0];
      var magicChi1Test = magicItemTest.children[0];
      var magicChi2Test = magicChi1Test.children[0];
      var magicChi3Test = magicChi2Test.children[0];
      var magicChi4Test = magicChi3Test.children[0];
      var magicUpgradeNameTest = magicChi3Test.text
      data["magicUpgrade"] = magicUpgradeNameTest
    }

    return data;
  }

  id: warScrollFormInternal
  objectName: "warScrollFormInternal"
  width: parent.width
  height: parent.height
  color: "#777777"

  Column
  {
    width: parent.width
    height: parent.height
    Text
    {
      id: warScrollTitle
      objectName: "warScrollTitle"
      text: ""
      font.pointSize: 12
      font.family: "Courier"
      width: parent.width
      height: 0.14 * parent.height
      verticalAlignment: TextEdit.AlignVCenter
    }

    Row
    {
      width: parent.width
      height: 0.07 * parent.height

      Text
      {
        id: unitCap
        objectName: "unitCap"
        text: "Model Count"
        font.pointSize: 10
        font.family: "Courier"
        width: 0.40 * parent.width
        height: parent.height
        horizontalAlignment: TextEdit.AlignHCenter
        verticalAlignment: TextEdit.AlignVCenter
      }

      SpinBox
      {
        id: unitCapSetter
        objectName: "unitCopSetter"
        width: 0.60 * parent.width
        height: parent.height
        decimals: 0
        stepSize: 1
        minimumValue: 1
        maximumValue: 1
        font.pointSize: 12
        font.family: "Courier"
      }
    }

    Row
    {
      id: aresenalRect
      width: parent.width
      height: 0.25 * parent.height

      ExclusiveGroup {
        id: exclusiveUpgrades
      }

      Rectangle
      {
        width: parent.width
        height: parent.height
        color: "#00000000"

        Component
        {
          id: warScrollDelegate
          Rectangle
          {
            width: parent.width
            height: 70
            color: "#00000000"
            Column
            {
              width: parent.width
              height: parent.height
              Row
              {
                width: parent.width
                height: parent.height
                Text
                {
                  id: warScrollDelegateName
                  width: parent.width
                  height: parent.height
                  font.pointSize: 8
                  font.family: "Courier"
                  text: name
                  verticalAlignment: TextEdit.AlignVCenter

                  RadioButton
                  {
                    id: warScrollDelegateSelected
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    exclusiveGroup: exclusiveUpgrades
                  }
                }
              }
            }
          }
        }

        ListModel
        {
          id: aWarScrollUpgradeModel
        }

        GroupBox
        {
          id: aWarScrollUpgradeGroupBox
          title: "Weapons"
          width: parent.width
          height: parent.height

          ListView
          {
            id: aWarScrollUpgradeView
            anchors.fill: parent
            model: aWarScrollUpgradeModel
            delegate: warScrollDelegate
            highlight: Rectangle { color: "#00000000" }
            focus: false
          }
        }
      }
    }

    Row
    {
      id: unitRect
      width: parent.width
      height: 0.25 * parent.height

      Rectangle
      {
        width: parent.width
        height: parent.height
        color: "#00000000"

        Component
        {
          id: warScrollUnitUpgradeDelegate
          Rectangle
          {
            width: parent.width
            height: 70
            color: "#00000000"
            Column
            {
              width: parent.width
              height: parent.height
              Row
              {
                width: parent.width
                height: parent.height
                Text
                {
                  id: warScrollUnitUpgradeDelegateName
                  width: parent.width
                  height: parent.height
                  font.pointSize: 8
                  font.family: "Courier"
                  text: name
                  verticalAlignment: TextEdit.AlignVCenter

                  CheckBox
                  {
                    id: warScrollDelegateSelected
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                  }
                }
              }
            }
          }
        }

        ListModel
        {
          id: aWarScrollUnitUpgradeModel
        }

        GroupBox
        {
          id: aWarScrollUnitUpgradeGroupBox
          title: "Unit"
          width: parent.width
          height: parent.height

          ListView
          {
            id: aWarScrollUnitUpgradeView
            anchors.fill: parent
            model: aWarScrollUnitUpgradeModel
            delegate: warScrollUnitUpgradeDelegate
            highlight: Rectangle { color: "#00000000" }
            focus: false
          }
        }
      }
    }

    Row
    {
      id: mountRect
      width: parent.width
      height: 0.25 * parent.height

      ExclusiveGroup {
        id: exclusiveMountUpgrades
      }

      Rectangle
      {
        width: parent.width
        height: parent.height
        color: "#00000000"

        Component
        {
          id: warScrollMountDelegate
          Rectangle
          {
            width: parent.width
            height: 70
            color: "#00000000"
            Column
            {
              width: parent.width
              height: parent.height
              Row
              {
                width: parent.width
                height: parent.height
                Text
                {
                  id: warScrollMountDelegateName
                  width: parent.width
                  height: parent.height
                  font.pointSize: 8
                  font.family: "Courier"
                  text: name
                  verticalAlignment: TextEdit.AlignVCenter

                  RadioButton
                  {
                    id: warScrollMoustDelegateSelected
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    exclusiveGroup: exclusiveMountUpgrades
                  }
                }
              }
            }
          }
        }

        ListModel
        {
          id: aWarScrollMountUpgradeModel
        }

        GroupBox
        {
          id: aWarScrollMountUpgradeGroupBox
          title: "Mounts"
          width: parent.width
          height: parent.height
          ListView
          {
            id: aWarScrollMountUpgradeView
            anchors.fill: parent
            model: aWarScrollMountUpgradeModel
            delegate: warScrollMountDelegate
            highlight: Rectangle { color: "#00000000" }
            focus: false
          }
        }
      }
    }

    Row
    {
      id: championRect
      width: parent.width
      height: 0.25 * parent.height

      ExclusiveGroup {
        id: exclusiveChampionUpgrades
      }

      Rectangle
      {
        width: parent.width
        height: parent.height
        color: "#00000000"

        Component
        {
          id: warScrollChampionDelegate
          Rectangle
          {
            width: parent.width
            height: 70
            color: "#00000000"
            Column
            {
              width: parent.width
              height: parent.height
              Row
              {
                width: parent.width
                height: parent.height
                Text
                {
                  id: warScrollChampionDelegateName
                  width: parent.width
                  height: parent.height
                  font.pointSize: 8
                  font.family: "Courier"
                  text: name
                  verticalAlignment: TextEdit.AlignVCenter

                  RadioButton
                  {
                    id: warScrollMoustDelegateSelected
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    exclusiveGroup: exclusiveChampionUpgrades
                  }
                }
              }
            }
          }
        }

        ListModel
        {
          id: aWarScrollChampionUpgradeModel
        }

        GroupBox
        {
          id: aWarScrollChampionUpgradeGroupBox
          title: "Champions"
          width: parent.width
          height: parent.height
          ListView
          {
            id: aWarScrollChampionUpgradeView
            anchors.fill: parent
            model: aWarScrollChampionUpgradeModel
            delegate: warScrollChampionDelegate
            highlight: Rectangle { color: "#00000000" }
            focus: false
          }
        }
      }
    }

    Row
    {
      id: magicalSpecializationRect
      width: parent.width
      height: 0.25 * parent.height

      ExclusiveGroup {
        id: exclusiveMagicalSpecializationUpgrades
      }

      Rectangle
      {
        width: parent.width
        height: parent.height
        color: "#00000000"

        Component
        {
          id: warScrollMagicalSpecializationDelegate
          Rectangle
          {
            width: parent.width
            height: 70
            color: "#00000000"
            Column
            {
              width: parent.width
              height: parent.height
              Row
              {
                width: parent.width
                height: parent.height
                Text
                {
                  id: warScrollMagicalSpecializationDelegateName
                  width: parent.width
                  height: parent.height
                  font.pointSize: 8
                  font.family: "Courier"
                  text: name
                  verticalAlignment: TextEdit.AlignVCenter

                  RadioButton
                  {
                    id: warScrollMoustDelegateSelected
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    exclusiveGroup: exclusiveMagicalSpecializationUpgrades
                  }
                }
              }
            }
          }
        }

        ListModel
        {
          id: aWarScrollMagicalSpecializationUpgradeModel
        }

        GroupBox
        {
          id: aWarScrollMagicalSpecializationUpgradeGroupBox
          title: "MagicalSpecializations"
          width: parent.width
          height: parent.height
          ListView
          {
            id: aWarScrollMagicalSpecializationUpgradeView
            anchors.fill: parent
            model: aWarScrollMagicalSpecializationUpgradeModel
            delegate: warScrollMagicalSpecializationDelegate
            highlight: Rectangle { color: "#00000000" }
            focus: false
          }
        }
      }
    }
  }
}
