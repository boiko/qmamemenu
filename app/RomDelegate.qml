import QtQuick 2.0

Item {
    id: romDelegate

    property bool current: false
    property string romId: model.id
    width: 256
    height: 256

    Image {
        id: snapshot
        anchors {
            fill: parent
            margins: 2
        }
        source: model.snapshotPath
        fillMode: Image.PreserveAspectCrop
        Rectangle {
            anchors {
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }
            height: description.height + 20
            gradient: Gradient {
                GradientStop { position: 0.0; color: "transparent" }
                GradientStop { position: 0.5; color: Qt.rgba(0,0,0, 0.7) }
            }

            Text {
                id: description
                anchors {
                    left: parent.left
                    leftMargin: 4
                    right: parent.right
                    rightMargin: 4
                    verticalCenter: parent.verticalCenter
                }

                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WordWrap
                text: model.description
                font.bold: true
            }
        }
    }
}
