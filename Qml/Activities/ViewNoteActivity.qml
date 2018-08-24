/*!
 *  \file       {File}
 *  \brief      This file is a prart of the project {Project}
 *  \details    View one note information
 *  \version    1.0
 *  \author     Bahrii Volodymyr (Skident)
 *  \date       24.08.2018
 *  \warning    Improper use can crash your application
 *  \copyright  GNU Public License.
 *  Contact: bahrii.volodymyr@gmail.com
 */

import QtQuick 2.0

import Flux.Enums 1.0
import "../Components"
import "../Global"

Item {
    readonly property var taskInfo: NavigationStore.data

    Column {
        id: content

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        Text {
            anchors.centerIn: parent
            text: taskInfo ? taskInfo.title : ""
        }

        ListView {
            id: gallery

            orientation: ListView.Horizontal
            spacing: 10

            width: parent.width
            height: 100

            model: taskInfo.files
            delegate: Image {
                width: 100
                height: 100

                fillMode: Image.PreserveAspectFit

                source: "file://" + modelData

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        fullScreenImage.source = parent.source
                        fullScreenImage.visible = true;
                    }
                }
            }
        }
    }

    Row {
        id: footer

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10

        spacing: 20

        DhButton {
            text: "Edit"
            onClicked: {
                Controller.openActivity(Actions.OPEN_EDIT_NOTE_ACTIVITY);
            }
        }

        DhButton {
            text: "Close"
            onClicked: {
                Controller.openActivity(Actions.OPEN_ALL_NOTES_ACTIVITY);
            }
        }
    }

    Image {
        id: fullScreenImage

        anchors.fill: parent
        visible: false

        fillMode: Image.PreserveAspectFit

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.visible = false;
            }
        }
    }
}
