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

  function addUpgrades(aList)
  {
    aWarScrollUpgradeModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      aWarScrollUpgradeModel.append({'name': aList[i]});
    }
    console.log("Done building upgrades")
  }

  function finalizeWarScroll()
  {
    var data = {}
    var count = unitCapSetter.value
    data["unitCount"] = count;

    var list = aWarScrollUpgradeView
    for (var i = 0; i < list.count; ++i)
    {
      var item = list.contentItem.children[i];
      var chi1 = item.children[0];
      var chi2 = chi1.children[0];
      var chi3 = chi2.children[0];
      var chi4 = chi3.children[0];
      if (chi4.checked) {
        var upgradeName = chi3.text.replace("Weapon Upgrade: ", "");
        data["weaponUpgrade"] = upgradeName
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
        text: "Upgrades"
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
      height: 0.69 * parent.height

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
            height: 35
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
                  text: 'Weapon Upgrade: ' + name
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
  }
}
