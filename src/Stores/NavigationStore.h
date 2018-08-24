#pragma once

#include <QObject>
#include <QVariant>

#include "IStore.h"

#include "Actions/IAction.h"
#include "Adapters/CustomEnums.h"

#include <map>

class NavigationStore
        : public QObject
        , public IStore
{
    Q_OBJECT

    Q_PROPERTY(Page::Enum page READ page NOTIFY pageChanged)
    Q_PROPERTY(QVariant data READ data NOTIFY dataChanged)

public:
    explicit NavigationStore(QObject *parent = nullptr);

    void process(IAction* action) override;

    Page::Enum page() const;
    void setPage(Page::Enum page);

    QVariant data() const
    {
        return m_data;
    }
    void setData(QVariant data)
    {
        m_data = data;
        emit dataChanged();
    }

signals:
    void pageChanged();
    void dataChanged();

private:
    Page::Enum m_page = Page::Enum::ALL_NOTES_ACTIVITY;
    QVariant m_data;

    static const std::map<ActionType::Enum, Page::Enum> S_ACTIONS_TO_PAGES_MAP;
};
