import QtQuick 2.0

Rectangle {
    id: root

    property alias text: text.text

    implicitWidth: parent.width
    implicitHeight: 50

    color: "lightgreen"

    Rectangle {
        anchors.fill: parent
        anchors.margins: 10
        anchors.centerIn: parent
        border.width: 1

        TextEdit {
            id: text
            anchors.fill: parent
            anchors.margins: 3
            text: "Enter your search request here"
        }
    }
}
