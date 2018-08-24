pragma Singleton

import QtQuick 2.0
import Flux.Enums 1.0

Item {
    function doAction(action) {
        console.log("Requested action: " + action)
    }

    function openNoteDetails(noteId) {
        console.log("Requested action 'open details for a note with id' " + noteId)
    }

    function openAddNoteActivity() {
        console.log("openAddNoteActivity")
//        NavigationStore.page(Page.ADD_TASK/*Actions.ADD_TASK*/)
//        var task = AdaptersFactory.create(AdaptersFactory.TASK_INFO);
//        task.title = "New title"

        Dispatcher.dispatch(Actions.OPEN_ADD_NOTE_ACTIVITY);
    }

    function openActivity(activity) {
        console.log("open activity", activity)
        Dispatcher.dispatch(activity);
    }
}
