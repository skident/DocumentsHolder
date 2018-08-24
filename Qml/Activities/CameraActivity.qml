/*!
 *  \file       {File}
 *  \brief      This file is a prart of the project {Project}
 *  \details    Open the camera activity for aquire the content from it
 *  \version    1.0
 *  \author     Bahrii Volodymyr (Skident)
 *  \date       24.08.2018
 *  \warning    Improper use can crash your application
 *  \copyright  GNU Public License.
 *  Contact: bahrii.volodymyr@gmail.com
 */

import QtQuick 2.0
import QtMultimedia 5.8

import Flux.Enums 1.0
import "../Components"

Item {
    id: root

    readonly property var taskInfo: NavigationStore.data

    Camera {
        id: camera

        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

        exposure {
            exposureCompensation: -1.0
            exposureMode: Camera.ExposurePortrait
        }

        flash.mode: Camera.FlashRedEyeReduction

        imageCapture {
            onImageCaptured: {
                photoPreview.source = preview  // Show the preview in an Image
            }

            onImageSaved: {
                console.log("Image saved: ", path)
                if (taskInfo) {
                    taskInfo.addFile(path);
                }
                // TODO: previous activity should be opened
                Dispatcher.dispatch(Actions.OPEN_EDIT_NOTE_ACTIVITY);
            }
        }
    }

    VideoOutput {
        source: camera
        anchors.fill: parent
        focus : visible // to receive focus and capture key events when visible
    }

    DhButton {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 10

        text: "Take a photo"

        onClicked: {
            camera.imageCapture.capture();
        }
    }

    Image {
        id: photoPreview

        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        onSourceChanged: {
            console.log("Source: ", source)
        }
    }
}
