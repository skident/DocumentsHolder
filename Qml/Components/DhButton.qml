import QtQuick 2.0


Rectangle {
    id: root

    property alias text: text.text

    signal clicked();

    width: 100
    height: 30

    border.width: 1
    color: "white"

    Text {
        id: text

        anchors.centerIn: parent
        text: "button"
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onHoveredChanged: {
            root.color = containsMouse ? "lightgray" : "white"
        }

        onClicked: {
            root.clicked();
        }


    }
}

