#include "NavigationStore.h"
#include "Actions/QmlAction.h"
#include "Adapters/TaskInfoAdapter.h"

const std::map<ActionType::Enum, Page::Enum> NavigationStore::S_ACTIONS_TO_PAGES_MAP =
{
    {ActionType::Enum::OPEN_ADD_NOTE_ACTIVITY, Page::Enum::ADD_NOTE_ACTIVITY},
    {ActionType::Enum::OPEN_EDIT_NOTE_ACTIVITY, Page::Enum::EDIT_NOTE_ACTIVITY},
    {ActionType::Enum::OPEN_ALL_NOTES_ACTIVITY, Page::Enum::ALL_NOTES_ACTIVITY},
    {ActionType::Enum::OPEN_PREVIEW_NOTE_ACTIVITY, Page::Enum::PREVIEW_NOTE_ACTIVITY},
    {ActionType::Enum::OPEN_CAMERA_ACTIVITY, Page::Enum::CAMERA_ACTIVITY},
};

NavigationStore::NavigationStore(QObject *parent) : QObject(parent)
{
    std::vector<ActionType::Enum> actions;
    for (const auto& actionPagePair : S_ACTIONS_TO_PAGES_MAP)
    {
        actions.push_back(actionPagePair.first);
    }
    setSupportedActions(actions);
}

void NavigationStore::process(IAction *action)
{
    if (!action)
    {
        return;
    }

    auto it = S_ACTIONS_TO_PAGES_MAP.find(action->actionType());
    if (it == S_ACTIONS_TO_PAGES_MAP.end())
    {
        return;
    }

    this->setPage(it->second);

    auto* ptr = dynamic_cast<QmlAction*>(action);
    if (ptr)
    {
        if (it->first == ActionType::Enum::OPEN_PREVIEW_NOTE_ACTIVITY)
        {
            TaskInfoAdapter* taskInfo = ptr->data<TaskInfoAdapter>();
            this->setData(QVariant::fromValue(taskInfo));
        }
    }
}

Page::Enum NavigationStore::page() const
{
    return m_page;
}

void NavigationStore::setPage(Page::Enum page)
{
    m_page = page;
    emit pageChanged();
}
