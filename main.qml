import QtQuick 2.9
import QtQuick.Window 2.2

import "Qml/Activities"

Window {
    visible: true
    width: 480
    height: 640
    title: qsTr("Documents holder")

    MainActivity {
        anchors.fill: parent
    }
}
