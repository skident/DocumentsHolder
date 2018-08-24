#pragma once

#include <QDataStream>
#include <QFile>
#include <QList>

class TaskInfoAdapter;

class Persistancy
{
public:
    Persistancy(const QString& filename);


    QList<QObject *> loadTasks() const;
    void storeTasks(QList<QObject*>  loadTasks);

private:
    QString m_fileName;
};

