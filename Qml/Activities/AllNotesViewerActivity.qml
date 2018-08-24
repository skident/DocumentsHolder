/*!
 *  \file       {File}
 *  \brief      This file is a prart of the project {Project}
 *  \details    See all notes on the one page with possibility of search and open any of them
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

    property var tasksModel: null

    Item {
        anchors.fill: parent

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

            DhTextEdit {
                id: searchBar

                anchors.left: parent.left

                text: "Enter your search request here"
            }

//            Rectangle {
//                id: searchBar

//                anchors.left: parent.left
//                //                anchors.top: parent.top
//                width: parent.width
//                height: toolbar.height

//                color: "lightgreen"

//                Rectangle {
//                    anchors.fill: parent
//                    anchors.margins: 10
//                    anchors.centerIn: parent
//                    border.width: 1


//                    TextEdit {
//                        anchors.fill: parent
//                        anchors.margins: 3
//                        text: "Enter your search request here"
//                    }
//                }
//            }
        }

        Item {
            id: addButton

            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 20

            width: 50
            height: width

            z: 100

            Rectangle {
                id: background

                anchors.fill: parent
                radius: width / 2
                color: "lightgreen"
                opacity: 0.3
            }

            Text {
                anchors.centerIn: parent
                text: "Add"
            }

            MouseArea {
                hoverEnabled: true
                anchors.fill: parent
                onClicked: {
                    Controller.openActivity(Actions.OPEN_ADD_NOTE_ACTIVITY);
                }

                onHoveredChanged: {
                    background.opacity = containsMouse ? 0.7 : 0.3
                }
            }
        }

        Rectangle {
            id: content

            anchors.top: header.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            ListView {
                anchors.fill: parent
                model: root.tasksModel

                delegate: Rectangle {
                    width: parent.width
                    height: 30
                    color: index % 2 ? "gray" : "lightgray"

                    Text {
                        id: title

                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10

                        text: modelData.title
                    }


                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            Dispatcher.dispatch(Actions.OPEN_PREVIEW_NOTE_ACTIVITY, modelData);
//                            Controller.openNoteDetails(modelData);
//                            Controller.openNoteDetails(index); // TODO: modelData.id
                        }
                    }
                }
            }
        }
    }
}
