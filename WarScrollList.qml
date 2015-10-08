import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0

Rectangle
{
  property alias unitList: currentWarScrollsView

  function addNewUnit(aMap)
  {
    currentWarScrollsModel.append({'name' : aMap['name'],
      'guid' : aMap['guid'], 'unit' : aMap['unit']})
  }

  function removeUnit(aGuid)
  {
    var list = currentWarScrollsModel;
    var i = 0;
    for (; i < list.count; ++i)
    {
      var guid = list.get(i).guid
      if (guid === aGuid) {
        currentWarScrollsModel.remove(i);
        armyBalancer.removeCurrentWarScroll(guid);
        break;
      }
    }
  }

  function clearAllUnits()
  {
    currentWarScrollsModel.clear();
  }

  function getCurrentSelectedUnit()
  {
    if (typeof currentWarScrollsView.model.get(
      currentWarScrollsView.currentIndex) != 'undefined') {
      return currentWarScrollsView.model.get(
        currentWarScrollsView.currentIndex).guid
    } else {
      return 'not_valid'
    }
  }

  width: parent.width
  height: parent.height

  color: "#22111111"

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

  Rectangle
  {
    width: parent.width
    height: parent.height
    color: "#00000000"

    Component
    {
      id: currentWarScrollDelegate
      Rectangle
      {
        MouseArea
        {
          anchors.fill: parent
          onClicked:
          {
            currentWarScrollsView.currentIndex = index
          }
        }
        width: parent.width
        height: 75
        color: "#CCCCCCCC"
        Column
        {
          width: parent.width
          height: parent.height
          RowLayout
          {
            width: parent.width
            height: parent.height
            Text
            {
              id: currentWarScrollDelegateName
              width: parent.width
              height: parent.height
              font.pointSize: 8
              font.family: "Courier"
              text: name + " -- count(" + unit + ")"
              verticalAlignment: TextEdit.AlignVCenter
            }
            Rectangle
            {
              width: 0.10 * parent.width
              height: parent.height
              color: "#22222222"
              anchors.right: parent.right

              Rectangle
              {
                id: currentWarScrollRemove
                width: 15
                height: 3.5
                color: "#220099"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
              }

              MouseArea
              {
                property bool validClick: false
                width: parent.width
                height: parent.height
                onPressed:
                {
                  validClick = true
                  currentWarScrollRemove.color = "#990022"
                }
                onReleased:
                {
                  currentWarScrollRemove.color = "#220099"
                  if (validClick) {
                    removeUnit(guid);
                  }
                }
                onExited:
                {
                  validClick = false
                  currentWarScrollRemove.color = "220099"
                }
              }
            }
          }
        }
      }
    }

    ListModel
    {
      id: currentWarScrollsModel
    }

    ListView
    {
      id: currentWarScrollsView
      anchors.fill: parent
      model: currentWarScrollsModel
      delegate: currentWarScrollDelegate
      highlight: Rectangle { color: "#77440000" }
      focus: true
      interactive: true

      property string currentWarScroll: ""

      onCurrentItemChanged:
      {
        if (typeof model.get(currentWarScrollsView.currentIndex) != 'QString') {
          currentWarScroll = ''
        } else if (typeof currentWarScroll === 'undefined') {
          currentWarScrollsView.currentIndex = 0;
        } else {
          currentWarScroll = model.get(currentWarScrollsView.currentIndex)
          var currentWarScrollGuid = currentWarScrollGuid.guid
          console.log(currentWarScrollGuid, " selected");
        }
      }

      function currentWarScrollsView()
      {
        currentWarScrollsView.currentIndex = 0;
      }
    }
  }
}

