#include "AppSettings.h"
#include <QProcess>
#include <QDir>
#include <QCoreApplication>
#include <QStringList>

#include <QDataStream>

Settings::Settings()
{
    m_settings = std::make_shared<QSettings>(QSettings::IniFormat, QSettings::UserScope,
                                             "FluxTasks", "Settings");
}

Settings::~Settings()
{
    m_settings->sync();
}

Settings &Settings::get()
{
    static Settings settings;
    return settings;
}

void Settings::setValue(QString key, QVariant value)
{
    m_settings->setValue(key, value);
}

void Settings::beginGroup(const QString &prefix)
{
    m_settings->beginGroup(prefix);
}

void Settings::endGroup()
{
    m_settings->endGroup();
}

QVariant Settings::value(const QString &key, const QVariant &defaultValue) const
{
    return m_settings->value(key, defaultValue);
}

bool Settings::empty() const
{
    return m_settings->allKeys().size() == 0;
}

/////////////////////////////////
/////////////////////////////////
/////////////////////////////////

AppSettings::AppSettings()
{
    Settings& settings = Settings::get();

    // set default values
    if (settings.empty())
    {
        setDefaultConfig();
    }
}

QList<TaskInfoAdapter*> AppSettings::tasks() const
{
//    QList<TaskInfoAdapter*> tasks;
////    QDataStream stream;
//    QVariant stream;
//    Settings::get().value(ConfigKey::ALL_TASKS, stream);
//    tasks = stream.value<QList<TaskInfoAdapter*> >();

////    stream >> tasks;
//    return tasks;


    ///////
}

void AppSettings::setTasks(QList<TaskInfoAdapter *> tasks)
{
//    QDataStream stream;
//    stream << tasks;
//    QVariant stream = QVariant::fromValue(tasks);
//    Settings::get().setValue(ConfigKey::ALL_TASKS, stream);
}

void AppSettings::setDefaultConfig()
{
//    setTasks();
}

