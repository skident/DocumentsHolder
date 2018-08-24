#pragma once

#include <QObject>

class Page
{
    Q_GADGET

public:
    enum class Enum : int
    {
        ALL_NOTES_ACTIVITY,
        ADD_NOTE_ACTIVITY,
        EDIT_NOTE_ACTIVITY,
        PREVIEW_NOTE_ACTIVITY,
        CAMERA_ACTIVITY,
    };
    Q_ENUM(Enum)
};
