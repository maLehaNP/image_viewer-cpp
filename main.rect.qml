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
      //Button {
      //  width: 101 //71
      //  height: 31
      //  text: "Выбрать папку"
      //  //anchors.verticalCenter: parent    // расположение по центру
      //}
      //Text{
      //  text: "Текущая папка"
      //  //font.pixelSize: 22
      //  lineHeightMode: Text.FixedHeight
      //  lineHeight: 31  // высота - 31 пикселей
      //}
      Rectangle{
        //Layout.preferredHeight: 80
        //Layout.preferredWidth: 80
        color: "#eb4d4b"    // красный
        width: 101
        height: 31
      }
      Rectangle {
        color: "#16a085"    // зеленый
        width: 101
        height: 31
      }
      Layout.alignment: Qt.AlignTop
    }
    Rectangle{
      color: "#eb4d4b"    // красный
      Layout.preferredHeight: 31
      Layout.fillWidth: true
      //anchors.bottom: image.top
    }
    Rectangle{
      id: image
      color: "#16a085"    // зеленый
      Layout.preferredHeight: 591
      Layout.fillWidth: true
    }
    Row {
      Rectangle{
        color: "#eb4d4b"    // красный
        width: 101
        height: 51
      }
      Rectangle {
        color: "#16a085"    // зеленый
        width: 101
        height: 51
      }
      Rectangle {
        color: "#0984e3"    // синий
        width: 101
        height: 51
      }
      Rectangle {
        color: "#16a085"    // зеленый
        width: 101
        height: 51
      }
      Rectangle{
        color: "#eb4d4b"    // красный
        width: 101
        height: 51
      }
      Rectangle {
        color: "#0984e3"    // синий
        width: 101
        height: 51
      }
      Rectangle {
        color: "#16a085"    // зеленый
        width: 101
        height: 51
      }
      Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
    }
  }
}
