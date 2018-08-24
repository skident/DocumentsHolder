/*!
 *  \file       {File}
 *  \brief      This file is a prart of the project {Project}
 *  \details    Main controller/aggregator for all activities
 *  \version    1.0
 *  \author     Bahrii Volodymyr (Skident)
 *  \date       24.08.2018
 *  \warning    Improper use can crash your application
 *  \copyright  GNU Public License.
 *  Contact: bahrii.volodymyr@gmail.com
 */

import QtQuick 2.0
import Flux.Enums 1.0

Item {
    /////////////////
    property int page: NavigationStore.page

    onPageChanged: {
        switch (page) {
        case Pages.ADD_NOTE_ACTIVITY:
            pageLoader.sourceComponent = addNoteActivityComponent;
            break;

        case Pages.EDIT_NOTE_ACTIVITY:
            pageLoader.sourceComponent = editNoteActivityComponent;
            break;

        case Pages.ALL_NOTES_ACTIVITY:
            pageLoader.sourceComponent = allNotesViewerActivityComponent;
            break;

        case Pages.PREVIEW_NOTE_ACTIVITY:
            pageLoader.sourceComponent = previewNoteActivityComponent;
            break;

        case Pages.CAMERA_ACTIVITY:
            pageLoader.sourceComponent = cameraActivityComponent;
            break;
        }
    }

    /////////////////


    Component {
        id: entryActivityComponent

        EntryActivity {
            anchors.fill: parent
            visible: false
        }
    }

    Component {
        id: addNoteActivityComponent

        AddNoteActivity {
            anchors.fill: parent
        }
    }


    Component {
        id: editNoteActivityComponent

        EditNoteActivity {
            anchors.fill: parent
        }
    }

    Component {
        id: allNotesViewerActivityComponent

        AllNotesViewerActivity {
            anchors.fill: parent
            tasksModel: TasksStore.tasks
        }
    }

    Component {
        id: previewNoteActivityComponent

        ViewNoteActivity {
            anchors.fill: parent
        }
    }

    Component {
        id: cameraActivityComponent

        CameraActivity {
            anchors.fill: parent
        }
    }

    Loader {
        id: pageLoader
        anchors.fill: parent
        sourceComponent: allNotesViewerActivityComponent
    }
}
