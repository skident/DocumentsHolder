#pragma once

#include <QObject>

class ActionType
{
    Q_GADGET

public:
    enum class Enum : int
    {
        NONE = 0,
        ADD_TASK,
        EDIT_TASK,
        REMOVE_TASK,
        APPLY_TASK,
        CANCEL_EDIT_TASK,

        // Navigation
        OPEN_ALL_NOTES_ACTIVITY,
        OPEN_ADD_NOTE_ACTIVITY,
        OPEN_EDIT_NOTE_ACTIVITY,
        OPEN_PREVIEW_NOTE_ACTIVITY,
        OPEN_CAMERA_ACTIVITY,
    };
    Q_ENUM(Enum)
};
Q_DECLARE_METATYPE(ActionType::Enum)

inline long long operator | (ActionType::Enum lhs, ActionType::Enum rhs)
{
    long long left = 1 << static_cast<long long>(lhs);
    long long right = 1 << static_cast<long long>(rhs);
    long long result = (long long)(left | right);
    return result;
}

inline long long operator | (long long lhs, ActionType::Enum rhs)
{
    return (long long)(lhs | 1 << static_cast<long long>(rhs));
}

