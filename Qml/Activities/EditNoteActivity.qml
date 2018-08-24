/*!
 *  \file       {File}
 *  \brief      This file is a prart of the project {Project}
 *  \details    This activity represents an activity for adding one note
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
    id: root

    readonly property var taskInfo: NavigationStore.data

    property alias title: _title.text
    property alias description: _description.text

    Column {
        id: header

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        DhToolbar {
            id: toolbar

            anchors.left: parent.left
            anchors.right: parent.right
        }
    }

    Column {
        id: content

        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Text {
            text: "Title:"
        }
        DhTextEdit {
            id: _title
            text: taskInfo.title
        }

        DhSpacer {}
        Text {
            id: _description
            text: "Description:"
        }
        DhTextEdit {
            text: taskInfo.description
        }

        //////
        DhSpacer {}
        Text {
            id: files
            text: "Attached files " + taskInfo.files.length
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
            }
        }

        Row {
            DhButton {
                text: "take a photo"
                onClicked: {
                    Dispatcher.dispatch(Actions.OPEN_CAMERA_ACTIVITY);
                }
            }
            DhButton {
                text: "upload file"
                onClicked: {
                    console.log("Upload file clicked")
//                    Dispatcher.dispatch(Actions.OPEN_CAMERA_ACTIVITY);
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
            text: "Save"
            onClicked: {
                taskInfo.title = root.title
                taskInfo.description = root.description
                Dispatcher.dispatch(Actions.APPLY_TASK, taskInfo);

                Controller.openActivity(Actions.OPEN_ALL_NOTES_ACTIVITY);
            }
        }

        DhButton {
            text: "Cancel"
            onClicked: {
                Controller.openActivity(Actions.OPEN_ALL_NOTES_ACTIVITY);
            }
        }
    }
}



