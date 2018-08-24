#pragma once

#include <QObject>

#include "TaskInfoAdapter.h"

class AdaptersFactory : public QObject
{
    Q_OBJECT

public:
    enum AdapterType
    {
        TASK_INFO,
    };
    Q_ENUMS(AdapterType)


    AdaptersFactory();

    Q_INVOKABLE TaskInfoAdapter* create(AdapterType adapterType)
    {
        static int taskId = 0;

        switch (adapterType) {
        case TASK_INFO:
            return new TaskInfoAdapter(++taskId);
            break;
        default:
            break;
        }
        return nullptr;
    }
};

