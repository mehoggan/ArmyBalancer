import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0

import ArmyBalancer 1.0

Item
{
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
      font.pointSize: 36
      text: "Army Balancer"
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
      width: parent.width
      ComboBox
      {
        id: selectFactionComboBox
        width: parent.width
        height: 100
        anchors.centerIn: parent.Center
        model: armyBalancer.factionList

        onActivated:
        {
          armyBalancer.factionSelectionChanged(index)
          selectWarScroll.currentIndex = 0
        }
      }

      ComboBox
      {
        id: selectWarScroll
        width: parent.width
        height: 100
        anchors.centerIn: parent.Center
        model: armyBalancer.warScrolls

        onActivated:
        {
          armyBalancer.warScrollSelectionChanged(index)
        }
      }
    }
  }
}


