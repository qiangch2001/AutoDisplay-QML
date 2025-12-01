import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window
    x: 0
    y: 0
    width: 640
    height: 480
    visible: true
    color: "#010000"
    visibility: Window.FullScreen
    title: qsTr("Hello World")

    Grid {
        id: grid
        width: 640
        height: 480
        verticalItemAlignment: Grid.AlignVCenter
        horizontalItemAlignment: Grid.AlignHCenter
        rightPadding: 0
        leftPadding: 0
        bottomPadding: 0
        topPadding: 0
        rows: 2
        columns: 2

        Rectangle {
            id: rectangle_red
            width: 320
            height: 240
            visible: true
            color: "#ff0000"
        }

        Rectangle {
            id: rectangle_green
            width: 320
            height: 240
            color: "#00ff00"
        }

        Rectangle {
            id: rectangle_blue
            width: 320
            height: 240
            color: "#0000ff"
        }

        Image {
            id: image
            width: 320
            height: 240
            visible: true
            source: "res/img1.jpg"
            fillMode: Image.Stretch
        }
    }
}
