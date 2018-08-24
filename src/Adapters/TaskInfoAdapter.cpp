#include "TaskInfoAdapter.h"

#include <QDebug>

TaskInfoAdapter::TaskInfoAdapter(int id)
{
    m_id = id;
    qDebug() << "Task with id" << m_id << "created";
}

TaskInfoAdapter::~TaskInfoAdapter()
{
    qDebug() << "Task with id" << m_id << "destroyed";
}

int TaskInfoAdapter::id() const
{
    return m_id;
}

QString TaskInfoAdapter::title() const
{
    return m_title;
}

QString TaskInfoAdapter::description() const
{
    return m_description;
}

void TaskInfoAdapter::setTitle(const QString &title)
{
    m_title = title;
    emit titleChanged();
}

void TaskInfoAdapter::setDescription(const QString &description)
{
    m_description = description;
    emit descriptionChanged();
}

bool TaskInfoAdapter::operator==(const TaskInfoAdapter &rhs)
{
    return m_id == rhs.m_id;
}
