import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

//import buttonHandler

Window {
  title: qsTr("Image Viewer")
  width: 1280
  height: 720
  visible: true

  //ButtonHandler {
  //  id: buttonHandler
  //}

  ColumnLayout {
    anchors.fill: parent
    Row {
      Button {
        objectName: "folderBtn"
        width: 121 //71
        height: 31
        text: "Выбрать папку"
        //onClicked: buttonHandler.handleClick()
      }
      Text {
        text: "Текущая папка"
        font.pixelSize: 22
        lineHeightMode: Text.FixedHeight
        lineHeight: 31  // высота - 31 пикселей
      }
      Layout.alignment: Qt.AlignTop
    }
    Text {
      text: "name"
      font.pixelSize: 22
      lineHeightMode: Text.FixedHeight
      lineHeight: 31  // высота - 31 пикселей
      Layout.preferredHeight: 31
      //Layout.fillWidth: true
      Layout.alignment: Qt.AlignHCenter
    }
    Image {
      id: image
      Layout.preferredHeight: 591
      Layout.fillWidth: true
      source: "../test_images/69f86e59a86e8162aea80769f971435a.jpg"
      fillMode: Image.PreserveAspectFit
    }
    Row {
      Button {
        objectName: "firstBtn"
        width: 101
        height: 51
        text: "Первый"
      }
      Button {
        objectName: "prevBtn"
        width: 101
        height: 51
        text: "Пред."
      }
      Button {
        objectName: "slideShowBtn"
        width: 101
        height: 51
        text: "Слайд-шоу"
      }
      Button {
        objectName: "nextBtn"
        width: 101
        height: 51
        text: "След."
      }
      Button {
        objectName: "lastBtn"
        width: 101
        height: 51
        text: "Последний"
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
