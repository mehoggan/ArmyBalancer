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

  function finalizeWarScroll()
  {
    var data = {}
    var count = unitCapSetter.value
    data["unitCount"] = count;

    var arsenalUgradeList = aWarScrollUpgradeView
    for (var i = 0; i < arsenalUgradeList.count; ++i)
    {
      var arsenalItem = arsenalUgradeList.contentItem.children[i];
      var arsenalChi1 = arsenalItem.children[0];
      var arsenalChi2 = arsenalChi1.children[0];
      var arsenalChi3 = arsenalChi2.children[0];
      var arsenalChi4 = arsenalChi3.children[0];
      if (arsenalChi4.checked) {
        var arsenalUpgradeName = arsenalChi3.text
        data["weaponUpgrade"] = arsenalUpgradeName
        break;
      }
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
      font.pointSize: 18
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
        font.pointSize: 16
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
        font.pointSize: 18
        font.family: "Courier"
      }
    }

    Row
    {
      width: parent.width
      height: 0.10 * parent.height

      Text
      {
        text: "Arsenal Upgrades"
        font.pointSize: 16
        font.family: "Courier"
        width: parent.width
        height: parent.height
        horizontalAlignment: TextEdit.AlignHCenter
        verticalAlignment: TextEdit.AlignVCenter
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
                  font.pointSize: 12
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

    Row
    {
      width: parent.width
      height: 0.10 * parent.height

      Text
      {
        text: "Unit Upgrades"
        font.pointSize: 16
        font.family: "Courier"
        width: parent.width
        height: parent.height
        horizontalAlignment: TextEdit.AlignHCenter
        verticalAlignment: TextEdit.AlignVCenter
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
                  font.pointSize: 12
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
}
