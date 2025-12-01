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


            Item {
                id: item1
                width: parent.width / 2
                height: parent.height
                Image {
                    id: image1
                    visible: true
                    anchors.fill: parent
                    source: "res/img1.jpg"
                    fillMode: Image.Stretch
                }
                /*
                Rectangle {
                    id: rectangle1
                    color: Qt.rgba(0, 0, 0, 0.0)
                    anchors.fill: parent
                }
                */
            }
            Item {
                id: item2
                width: parent.width / 2
                height: parent.height

                Image {
                    id: image2
                    visible: true
                    anchors.fill: parent
                    source: "res/img1.jpg"
                    fillMode: Image.Stretch
                }

                Rectangle {
                    id: rectangle2
                    color: Qt.rgba(0, 0, 0, 0.1)
                    anchors.fill: parent
                }
            }
        }

        Row {
            id: row2
            height: parent.height / 2
            width: parent.width

            Item {
                id: item3
                width: parent.width / 2
                height: parent.height

                Image {
                    id: image3
                    visible: true
                    anchors.fill: parent
                    source: "res/img1.jpg"
                    fillMode: Image.Stretch
                }

                Rectangle {
                    id: rectangle3
                    color: Qt.rgba(0, 0, 0, 0.5)
                    anchors.fill: parent
                }
            }

            Item {
                id: item4
                width: parent.width / 2
                height: parent.height
                Image {
                    id: image4
                    visible: true
                    anchors.fill: parent
                    source: "res/img1.jpg"
                    fillMode: Image.Stretch
                }

                Rectangle {
                    id: rectangle4
                    color: Qt.rgba(0, 0, 0, 1)
                    anchors.fill: parent
                }
            }
        }
    }
}
