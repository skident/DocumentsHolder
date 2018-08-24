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

    property alias title: title.text
    property alias description: description.text

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
            id: title
            text: "title"
        }

        DhSpacer {}
        Text {
            id: description
            text: "Description:"
        }
        DhTextEdit {
            text: "description"
        }

        //////
        DhSpacer {}
        Text {
            id: files
            text: "Attached files "
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
                var task = AdaptersFactory.create(AdaptersFactory.TASK_INFO);
                task.title = root.title
                task.description = root.description
                Dispatcher.dispatch(Actions.ADD_TASK, task);

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
