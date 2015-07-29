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
  }

  function addArsenalUpgrades(aList)
  {
    aWarScrollUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollUpgradeModel.append({'name' : aList[i]});
    }
  }

  function addUnitUpgrades(aList)
  {
    aWarScrollUnitUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollUnitUpgradeModel.append({'name' : aList[i]});
    }
  }

  function addMountUpgrades(aList)
  {
    aWarScrollMountUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollMountUpgradeModel.append({'name' : aList[i]});
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
      var unitUgradeItem = unitUpgradeList.contentItem.children[j];
      var unitUpgradeChi1 = unitUgradeItem.children[0];
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
    var testCount = mountUgradeList.count;
    for (var i = 0; i < mountUgradeList.count; ++i)
    {
      var mountItem = mountUgradeList.contentItem.children[i];
      console.log(mountItem.text);
      var mountChi1 = mountItem.children[0];
      console.log(mountChi1);
      var mountChi2 = mountChi1.children[0];
      console.log(mountChi2);
      var mountChi3 = mountChi2.children[0];
      console.log(mountChi3);
      var mountChi4 = mountChi3.children[0];
      console.log(mountChi4);
      if (mountChi4.checked) {
        itemSelected = true;
        var mountUpgradeName = mountChi3.text
        data["mountUpgrade"] = mountUpgradeName
        break;
      }
    }

    return data;
  }

  id: warScrollFormInternal
  objectName: "warScrollFormInternal"
  width: parent.width
  height: parent.height
  color: "#77000000"

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
                    exclusiveGroup: exclusiveUpgrades
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
  }
}
