import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import backend

Window {
  title: qsTr("Image Viewer")
  width: 1280
  height: 720
  visible: true

  id: window
  property string path: "Текущая папка"
  property string imageName: "name"
  property url imageUrl
  property bool isFirst: true
  property bool isLast: true

  Backend {
    id: backend
  }

  ColumnLayout {
    anchors.fill: parent
    Row {
      Button {
        objectName: "folderBtn"
        width: 121 //71
        height: 31
        text: "Выбрать папку"
        onClicked: backend.handleClick(0)
      }
      Text {
        id: link
        text: window.path
        font.pixelSize: 22
        lineHeightMode: Text.FixedHeight
        lineHeight: 31  // высота - 31 пикселей
      }
      Layout.alignment: Qt.AlignTop
    }
    Text {
      text: window.imageName
      font.pixelSize: 22
      lineHeightMode: Text.FixedHeight
      lineHeight: 31  // высота - 31 пикселей
      Layout.preferredHeight: 31
      //Layout.fillWidth: true
      Layout.alignment: Qt.AlignHCenter
    }
    Image {
      id: image
      objectName: "image"
      Layout.preferredHeight: 591
      Layout.fillWidth: true
      source: window.imageUrl
      fillMode: Image.PreserveAspectFit
    }
    Row {
      Button {
        objectName: "firstBtn"
        width: 101
        height: 51
        text: "Первый"
        onClicked: backend.handleClick(1)
        enabled: !isFirst
      }
      Button {
        objectName: "prevBtn"
        width: 101
        height: 51
        text: "Пред."
        onClicked: backend.handleClick(2)
        enabled: !isFirst
      }
      Button {
        objectName: "slideShowBtn"
        width: 101
        height: 51
        text: "Слайд-шоу"
        onClicked: backend.handleClick(3)
      }
      Button {
        objectName: "nextBtn"
        width: 101
        height: 51
        text: "След."
        onClicked: backend.handleClick(4)
        enabled: !isLast
      }
      Button {
        objectName: "lastBtn"
        width: 101
        height: 51
        text: "Последний"
        onClicked: backend.handleClick(5)
        enabled: !isLast
      }
      Button {
        objectName: "turnBtn"
        width: 101
        height: 51
        text: "По час."
      }
      Button {
        objectName: "delBtn"
        width: 101
        height: 51
        text: "Удалить"
      }
      Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
    }
  }
}
