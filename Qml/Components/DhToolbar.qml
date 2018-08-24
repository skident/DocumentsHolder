/*!
 *  \file       {File}
 *  \brief      This file is a prart of the project {Project}
 *  \details    Toolbar for all activities
 *  \version    1.0
 *  \author     Bahrii Volodymyr (Skident)
 *  \date       24.08.2018
 *  \warning    Improper use can crash your application
 *  \copyright  GNU Public License.
 *  Contact: bahrii.volodymyr@gmail.com
 */

import QtQuick 2.0

Rectangle {
    id: root

    readonly property int toolbarHeight: 50

    width: parent.width
    height: root.toolbarHeight

    color: "white"

    Item {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        Image {
            id: leftIcon

            anchors.left: parent.left
            anchors.top: parent.top

            width: 50
            height: 50
        }

        Text {
            id: title

//            anchors.left: leftIcon.right
//            anchors.right: rightIcon.left
            anchors.verticalCenter: leftIcon.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            text: "Activity name"
        }

        Image {
            id: rightIcon

            anchors.right: parent.right
            anchors.top: parent.top

            width: 50
            height: 50
        }
    }

//    SizeIndicator {}
}
