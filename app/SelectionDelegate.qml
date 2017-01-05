import QtQuick 2.0

Rectangle {
    id: selectionDelegate
    border.color: "#FFFF88"
    border.width: 7
    color: "transparent"
    y: gridView.currentItem.y;
    Behavior on y { NumberAnimation { duration: 150 } }
    x: gridView.currentItem.x;
    Behavior on x { NumberAnimation { duration: 150 } }
    z: 1

    Timer {
        interval: 250
        repeat: true
        running: true
        onTriggered: {
            selectionDelegate.border.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
        }
    }
}
