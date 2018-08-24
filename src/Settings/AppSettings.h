#pragma once

#include <QSettings>
#include <QObject>
#include <memory>
#include "Adapters/TaskInfoAdapter.h"

// minimal wrapper under the QSettings class
class Settings
{
    Settings();
    ~Settings();

public:
    static Settings& get();

    void setValue(QString key, QVariant value);

    void beginGroup(const QString &prefix);
    void endGroup();

    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;

    bool empty() const;

private:
     std::shared_ptr<QSettings> m_settings;
};


/////////////////////////////////
/////////////////////////////////
class AppSettings
{
    AppSettings();
public:
    static AppSettings& get()
    {
        static AppSettings self;
        return self;
    }

    QList<TaskInfoAdapter*> tasks() const;
    void setTasks(QList<TaskInfoAdapter*>  tasks);

public:
    // Configuration keys
    struct ConfigKey
    {
        static constexpr auto ALL_TASKS = "all_tasks";
    };

    
private: // methods
    void setDefaultConfig();
};
