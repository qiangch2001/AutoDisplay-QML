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

    property var images: ["res/img1.jpg", "res/img2.jpg", "res/img3.png", "res/img4.png", "res/img5.png"]
    property int img_index: 0
    property real brightness_fbctx: 0.0
    property real alpha_overlay: 1.0

    MouseArea {
        anchors.fill: parent
        onClicked: {
            img_index = (img_index + 1) % 5
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
        color: Qt.rgba(0, 0, 0, alpha_overlay)
        anchors.fill: parent
    }

    Timer {
        interval: 200
        repeat: true
        running: true

        onTriggered: {
            brightness_fbctx = BrightnessReader.readAverageBrightness()
            overlayAlpha = 1.0 - fbBrightness / 255.0

            if (overlayAlpha < 0.1) overlayAlpha = 0.1
            if (overlayAlpha > 1) overlayAlpha = 1

            console.log("FB Brightness:", fbBrightness, "Overlay:", overlayAlpha)
        }
    }
}
