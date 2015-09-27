import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0

import ArmyBalancer 1.0
import WarScrollRelationsGraphScene 1.0
import "./"

Item
{
  id: root
  objectName: "root"

  function updateWarScrollList(aList)
  {
    var curr = selectWarScroll.currentIndex;
    warScrollModel.clear();
    for (var i = 0; i < aList.length; ++i) {
      warScrollModel.append({'name': aList[i]});
    }
    var min = Math.min(aList.length - 1, curr)
    selectWarScroll.currentIndex = min
  }

  function addToCurrentPoints(val)
  {
    pointsText.text = Number(pointsText.text) + val
  }

  function clearCurrentPoints()
  {
    pointsText.text = "0"
  }

  Rectangle
  {
    id: title
    width: parent.width
    height: 0.15 * parent.height

    Rectangle
    {
      id: horizGradient
      width: parent.height
      height: parent.width
      anchors.centerIn: parent
      rotation: 270
      gradient: Gradient
      {
        GradientStop { position: 0.00; color: "#000099" }
        GradientStop { position: 0.47; color: "#222222" }
        GradientStop { position: 0.50; color: "#999999" }
        GradientStop { position: 0.53; color: "#222222" }
        GradientStop { position: 1.00; color: "#990000" }
      }
    }
    Text
    {
      id: text
      width: parent.width
      height: parent.height
      color: "#FFD700"
      font.pointSize: 28
      text: "Army Balancer"
      font.family: "Courier"
      verticalAlignment: Text.AlignVCenter
      horizontalAlignment: Text.AlignHCenter
    }
    LinearGradient
    {
      anchors.fill: text
      source: text
      gradient: Gradient
      {
        GradientStop { position: 0.00; color: "#FFD700" }
        GradientStop { position: 0.50; color: "#DDDDDD" }
        GradientStop { position: 0.75; color: "#FFD700" }
      }
    }
  }

  ArmyBalancer
  {
    id: armyBalancer
    objectName: "armyBalancer"
  }

  Rectangle
  {
    id: body
    width: parent.width
    height: 0.85 * parent.height

    anchors.bottom: parent.bottom

    color: "#FFFF00"
    RadialGradient
    {
      anchors.fill: parent
      horizontalOffset: 0
      verticalOffset: 0
      horizontalRadius: 100
      verticalRadius: 300
      gradient: Gradient
      {
        GradientStop { position: 0.00; color: "#FFFFFF" }
        GradientStop { position: 0.75; color: "#F5F5DC" }
      }
    }

    Column
    {
      id: mainColumn
      objectName: "mainColumn"
      width: parent.width
      height: parent.height
      visible: true
      Row
      {
        width: parent.width
        height: 0.10 * parent.height

        Text
        {
          width: 0.20 *parent.width
          height: parent.height
          font.pointSize: 7
          font.family: "Courier"
          text: "Faction"
          horizontalAlignment: TextEdit.AlignHCenter
          verticalAlignment: TextEdit.AlignVCenter
        }

        ComboBox
        {
          id: selectFactionComboBox
          width: 0.80 *parent.width
          height: parent.height
          anchors.centerIn: parent.Center
          model: armyBalancer.factionList

          onCurrentIndexChanged:
          {
            if (currentIndex > 0) {
              warScrollSelectionRect.visible = false;
              warScrollSelectionRow.visible = true;
            } else {
              warScrollSelectionRect.visible = true;
              warScrollSelectionRow.visible = false;
              currentIndex = -1
              currentIndex = -1
            }

            if (currentIndex != -1) {
              armyBalancer.factionSelectionChanged(currentIndex)
            }
          }
        }
      }

      ListModel
      {
        id: warScrollModel
      }

      Row
      {
        id: warScrollSelectionRect
        width: parent.width
        height: 0.10 * parent.height
        visible: true

        Rectangle
        {
          color: "#F5F5DC"
        }
      }

      Row
      {
        id: warScrollSelectionRow
        width: parent.width
        height: 0.10 * parent.height
        visible: false

        Text
        {
          width: 0.20 *parent.width
          height: parent.height
          font.pointSize: 7
          font.family: "Courier"
          text: "War Scroll"
          horizontalAlignment: TextEdit.AlignHCenter
          verticalAlignment: TextEdit.AlignVCenter
        }
        ComboBox
        {
          id: selectWarScroll
          width: 0.80 * parent.width
          height: parent.height
          anchors.centerIn: parent.Center
          model: warScrollModel

          onCurrentIndexChanged:
          {
            armyBalancer.warScrollSelectionChanged(currentIndex)
          }
        }
      }

      Row
      {
        width: parent.width
        height: 0.70 * parent.height
        Rectangle
        {
          width: parent.width
          height: parent.height

          color: "#77000000"
          border.width: 2
          border.color: "#F5F5DF"
          Column
          {
            width: parent.width
            height: parent.height

            Text
            {
              text: "Point Balance"
              font.pointSize: 24
              font.family: "Courier"
              width: parent.width
              height: 0.25 * parent.height
              horizontalAlignment: TextEdit.AlignHCenter
              verticalAlignment: TextEdit.AlignVCenter
            }
            Text
            {
              id: pointsText
              objectName: "pointsText"
              text: "0"
              font.pointSize: 72
              font.family: "Courier"
              width: parent.width
              height: 0.75 * parent.height
              horizontalAlignment: TextEdit.AlignHCenter
              verticalAlignment: TextEdit.AlignVCenter
            }
          }
        }
      }

      Row
      {
        width: parent.width
        height: 0.10 * parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        Button
        {
          width: 1/4 * parent.width
          height: parent.height
          text: "Add"

          onClicked: {
            if (selectFactionComboBox.currentText != "" &&
              selectWarScroll.currentText != "") {
              viewRemoveColumn.visible = false
              mainColumn.visible = false
              armyBalancer.warScrollSeleted();
              addColumn.visible = true
              warscrollRelationsGraphScene.draw = false;
            }
          }
        }
        Button
        {
          width: 1/4 * parent.width
          height: parent.height
          text: "View/Remove"

          onClicked: {
            viewRemoveColumn.visible = true
            mainColumn.visible = false
            addColumn.visible = false
            armyBalancer.clearCurrentWarScroll();
            warscrollRelationsGraphScene.draw = false;
          }
        }
        Button
        {
          width: 1/4 * parent.width
          height: parent.height
          text: "Finalize"

          onClicked: {
            graphColumn.visible = true
            mainColumn.visible = false
            addColumn.visible = false
            viewRemoveColumn.visible = false
            armyBalancer.buildAndPublishSynergyGraph();
            warscrollRelationsGraphScene.draw = true;
          }
        }
        Button
        {
          width: 1/4 * parent.width
          height: parent.height
          text: "Clear"

          onClicked: {
            armyBalancer.clearCurrentWarScrolls();
            warscrollRelationsGraphScene.draw = false;
          }
        }
      }
    }

    Column
    {
      id: graphColumn
      objectName: "graphColumn"
      width: parent.width
      height: parent.height
      visible: false

      Row
      {
        width: parent.width
        height: 0.90 * parent.height

        Item
        {
          width: parent.width
          height: parent.height

          WarScrollRelationsGraphScene
          {
            id: warscrollRelationsGraphScene
            width: parent.width
            height: parent.height
            SequentialAnimation on t
            {
              NumberAnimation
              {
                to: 1; duration: 2500; easing.type: Easing.InQuad
              }
              NumberAnimation
              {
                to: 0; duration: 2500; easing.type: Easing.OutQuad
              }
              loops: Animation.Infinite
              running: true
            }
          }
        }
      }

      Row
      {
        width: parent.width
        height: 0.10 * parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        Button
        {
          width: parent.width
          height: parent.height
          text: "Back"

          onClicked: {
            mainColumn.visible = true
            addColumn.visible = false
            viewRemoveColumn.visible = false
            graphColumn.visible = false
            warscrollRelationsGraphScene.draw = false;
          }
        }
      }
    }

    Column
    {
      id: addColumn
      objectName: "addColumn"
      width: parent.width
      height: parent.height
      visible: false

      Row
      {
        width: parent.width
        height: 0.90 * parent.height

        WarScrollForm
        {
          id: warScrollForm
          objectName: "warScrollForm"
          width: parent.width
          height: parent.height
        }
      }

      Row
      {
        width: parent.width
        height: 0.10 * parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        Button
        {
          width: 1/2 * parent.width
          height: parent.height
          text: "Cancel Add"

          onClicked: {
            mainColumn.visible = true
            addColumn.visible = false
            viewRemoveColumn.visible = false
            armyBalancer.clearCurrentWarScroll();
          }
        }
        Button
        {
          width: 1/2 * parent.width
          height: parent.height
          text: "Add to Army"

          onClicked: {
            if ("" + warScrollForm.spinBox.value === "") {
              console.error("Invalid value")
            } else if (Number(warScrollForm.spinBox.value) >=
              warScrollForm.spinBox.minimumValue &&
              Number(warScrollForm.spinBox.value) <=
              warScrollForm.spinBox.maximumValue) {
              mainColumn.visible = true
              addColumn.visible = false
              viewRemoveColumn.visible = false
              var data = warScrollForm.finalizeWarScroll();
              armyBalancer.warScrollAccepted(data);
            } else {
              console.error("Invalid value")
            }
          }
        }
      }
    }

    Column
    {
      id: viewRemoveColumn
      objectName: "viewRemoveColumn"
      width: parent.width
      height: parent.height
      visible: false

      Row
      {
        id: warScrollValues
        width: parent.width
        height: 0.90 * parent.height
        visible: false

        Rectangle
        {
          width: parent.width
          height: parent.height
          TextArea
          {
            id: warScrollData
            width: parent.width
            height: parent.height
            text: ""
            font.pointSize: 11
            font.family: "Courier"
            backgroundVisible: false
          }
        }
      }

      Row
      {
        id: warScrollList
        width: parent.width
        height: 0.90 * parent.height
        visible: true

        Rectangle
        {
          width: parent.width
          height: parent.height
          WarScrollList
          {
            id: currentWarScrolls
            objectName: "currentWarScrolls"
          }
        }
      }

      Row
      {
        width: parent.width
        height: 0.10 * parent.height
        anchors.horizontalCenter: parent.horizontalCenter

        Button
        {
          width: 0.50 * parent.width
          height: parent.height
          text: "Done"

          onClicked: {
            mainColumn.visible = true
            addColumn.visible = false
            viewRemoveColumn.visible = false
            warScrollValues.visible = false
            warScrollList.visible = true
            viewScrollButton.displayMode = true
            viewScrollButton.text = "View Scroll"
          }
        }

        Button
        {
          id: viewScrollButton
          width: 0.50 * parent.width
          height: parent.height
          text: "View Scroll"
          property bool displayMode: true

          onClicked: {
            if (displayMode) {
              warScrollValues.visible = true
              warScrollList.visible = false
              displayMode = false
              viewScrollButton.text = "Back"
              var guid = currentWarScrolls.getCurrentSelectedUnit()
              warScrollData.text = armyBalancer.getCurrentScrollText(guid);
            } else {
              warScrollValues.visible = false
              warScrollList.visible = true
              displayMode = true
              viewScrollButton.text = "View Scroll"
            }
          }
        }
      }
    }
  }
}
