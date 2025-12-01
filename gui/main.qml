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

    property var brightnesses: [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    property var images: ["res/img1.jpg", "res/img2.jpg", "res/img3.png", "res/img4.png", "res/img5.png"]
    property int bright_index: 0
    property int img_index: 0

    MouseArea {
        anchors.fill: parent
        onClicked: {
            img_index = (img_index + 1) % 5
            console.log("Brightness:", brightnesses[bright_index])
        }
    }

    Image {
        id: image
        visible: true
        anchors.fill: parent
        source: images[img_index]
        fillMode: Image.Stretch
    }
    Rectangle {
        id: rectangle
        color: Qt.rgba(0, 0, 0, brightnesses[bright_index])
        anchors.fill: parent
    }
}
