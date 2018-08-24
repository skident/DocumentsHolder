#pragma once

#include <QObject>
#include <QDataStream>

class TaskInfoAdapter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ id NOTIFY idChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QStringList files READ files WRITE setFiles NOTIFY filesChanged)

public:
    TaskInfoAdapter(int id = 0);
    ~TaskInfoAdapter();

    int id() const;

    QString title() const;

    QString description() const;

    void setTitle(const QString& title);

    void setDescription(const QString& description);

    QStringList files() const
    {
        return m_files;
    }

    void setFiles(const QStringList& files)
    {
        m_files = files;
        emit filesChanged();
    }

    Q_INVOKABLE void addFile(const QString& file)
    {
        m_files.append(file);
        emit filesChanged();
    }

    bool operator==(const TaskInfoAdapter& rhs);

signals:
    void idChanged();
    void titleChanged();
    void descriptionChanged();
    void filesChanged();

    //private:
public:
    int m_id = 0;
    QString m_title;
    QString m_description;
    QStringList m_files;
};


inline QDataStream& operator<<(QDataStream& out, const TaskInfoAdapter& v)
{
    out << v.id() << v.title() << v.description() << v.files();
    return out;
}

inline QDataStream& operator>>(QDataStream& in, TaskInfoAdapter& v)
{
    in >> v.m_id
            >> v.m_title
            >> v.m_description
            >> v.m_files;
    return in;
}


inline QDataStream& operator<<(QDataStream& out, const TaskInfoAdapter* v)
{
    out << (*v);
    return out;
}

inline QDataStream& operator>>(QDataStream& in, TaskInfoAdapter* v)
{
    in >> (*v);
    return in;
}

inline QDataStream& operator<<(QDataStream& out, const QList<TaskInfoAdapter*>& v)
{
    out << v.size();

    for (auto it : v)
    {
        out << *it;
    }
    return out;
}

inline QDataStream& operator>>(QDataStream& in, QList<TaskInfoAdapter*>& v)
{
    int size = 0;
    in >> size;

    for (int i = 0; i < size; i++)
    {
        TaskInfoAdapter* ptr = new TaskInfoAdapter;
        in >> (*ptr);
        v.push_back(ptr);
    }
    return in;
}

