import QtQuick 2.4
import Ubuntu.Components 1.3
import Qmamemenu 1.0
/*!
    \brief MainView with a Label and Button elements.
*/

GridView {
    id: gridView

    property int itemSize: width / 3

    width: 480
    height: 800
    cellWidth: itemSize
    cellHeight: itemSize

    currentIndex: 0

    highlight: SelectionDelegate {
        width: itemSize
        height: itemSize
    }
    highlightFollowsCurrentItem: false
    focus: true

    header: Item {
        width: parent.width
        height: 100
        Text {
            id: name
            text: qsTr("ARCADE")
            anchors.centerIn: parent
        }

    }

    model: MameRomModel {
        id: romModel
    }

    delegate: RomDelegate {
        width: itemSize
        height: itemSize
        current: index == gridView.currentIndex
    }

    Keys.onReturnPressed: {
        console.log("Running rom: " + currentItem.romId)
        romModel.runRom(currentItem.romId)
    }
}


