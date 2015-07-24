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

  id: warScrollFormInternal
  objectName: "warScrollFormInternal"
  width: parent.width
  height: parent.height
  color: "#77000000"

  Column
  {
    width: parent.width
    height: parent.height
    TextArea
    {
      id: warScrollTitle
      objectName: "warScrollTitle"
      text: ""
      font.pointSize: 18
      textColor: "#FFFFFF"
      font.family: "Courier"
      width: parent.width
      height: 0.14 * parent.height
      backgroundVisible: false;
      verticalAlignment: TextEdit.AlignVCenter
      readOnly: true
    }

    Row
    {
      width: parent.width
      height: 0.07 * parent.height

      TextArea
      {
        id: unitCap
        objectName: "unitCap"
        text: "Model Count"
        font.pointSize: 10
        textColor: "#FFFFFF"
        font.family: "Courier"
        width: 0.40 * parent.width
        height: parent.height
        backgroundVisible: false;
        horizontalAlignment: TextEdit.AlignHCenter
        verticalAlignment: TextEdit.AlignVCenter
        readOnly: true
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
  }
}
