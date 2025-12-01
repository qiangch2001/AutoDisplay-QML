import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window
    x: 0
    y: 0
    visible: true
    color: "#010000"
    visibility: Window.FullScreen
    title: qsTr("Hello World")

    Column {
        id: column
        anchors.fill: parent

        Row {
            id: row1
            height: parent.height / 2
            width: parent.width

            Rectangle {
                id: rectangle_red
                visible: true
                color: "#ff0000"
                width: parent.width / 2
                height: parent.height
            }

            Rectangle {
                id: rectangle_green
                color: "#00ff00"
                width: parent.width / 2
                height: parent.height
            }
        }

        Row {
            id: row2
            height: parent.height / 2
            width: parent.width

            Rectangle {
                id: rectangle_blue
                color: "#0000ff"
                width: parent.width / 2
                height: parent.height
            }

            Image {
                id: image
                visible: true
                source: "res/img1.jpg"
                fillMode: Image.Stretch
                width: parent.width / 2
                height: parent.height
            }
        }
    }
}
