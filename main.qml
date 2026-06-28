import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Window {
  title: qsTr("Image Viewer")
  //width: 300
  //height: 250
  visible: true
  ColumnLayout {
    anchors.fill: parent
    Row {
      Button {
        width: 101 //71
        height: 31
        text: "Выбрать папку"
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
      Layout.fillWidth: true
    }
    Image {
      id: image
      Layout.preferredHeight: 591
      Layout.fillWidth: true
      source: "test_images/69f86e59a86e8162aea80769f971435a.jpg"
      fillMode: Image.PreserveAspectFit
    }
    Row {
      Button {
        width: 101
        height: 51
        text: "Первый"
      }
      Button {
        width: 101
        height: 51
        text: "Пред."
      }
      Button {
        width: 101
        height: 51
        text: "Слайд-шоу"
      }
      Button {
        width: 101
        height: 51
        text: "След."
      }
      Button {
        width: 101
        height: 51
        text: "Последний"
      }
      Button {
        width: 101
        height: 51
        text: "По час."
      }
      Button {
        width: 101
        height: 51
        text: "Удалить"
      }
      Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
    }
  }
}
