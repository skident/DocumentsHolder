#include "Persistency.h"
#include <QDataStream>
#include "Adapters/TaskInfoAdapter.h"

Persistancy::Persistancy(const QString &filename)
{
    m_fileName = filename;
}

QList<QObject *> Persistancy::loadTasks() const
{
    QList<TaskInfoAdapter*> readList;
    QList<QObject*> tasks;

    QFile file(m_fileName);
    bool opened = file.open(QIODevice::ReadOnly);
    if (!opened)
    {
        return tasks;
    }

    QDataStream in(&file);
    in >> readList;

    for (auto it : readList)
    {
        tasks.push_back(it);
    }

    return tasks;
}

void Persistancy::storeTasks(QList<QObject *> tasks)
{
    QList<TaskInfoAdapter*> allTasks;
    for (auto it : tasks)
    {
        allTasks.push_back(dynamic_cast<TaskInfoAdapter*>(it));
    }

    QFile file(m_fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    out << allTasks;
}
