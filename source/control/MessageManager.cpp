#include "MessageManager.h"

#include <QDebug>
#include <QTimer>

#include "ApplicationManager.h"

MessageManager::MessageManager(QObject *parent)
    : QObject(parent)
    , mMessageModel()
{}

MessageModel* MessageManager::messageModel()
{
    return &mMessageModel;
}

void MessageManager::reloadMessages(int contactId)
{
    qDebug() << QString("<MessageManager::loadContactMessages> Loading messages of contact %1").arg(contactId);

    mMessageModel.reset();

    mContactId = contactId;

    loadMessages(mContactId);
}

void MessageManager::loadMessages(int contactId, const QDateTime &untilTime)
{
    mMessageModel.setLoading(true);

    const QList<ChatDataItem*> results = ApplicationManager::instance().dbManager()->loadContactMessages(contactId, untilTime);
    for (int i = 0; i < results.size(); ++i) {
        mMessageModel.addItem(results.at(i));
    }

    qDebug() << QString("<MessageManager::loadContactMessages> Loaded %1 messages").arg(results.size());

    mMessageModel.setLoading(false);
}

void MessageManager::loadMore()
{
    // simulate a network call, and its delay
    mMessageModel.setLoading(true);
    QTimer::singleShot(3000, [=](){
        loadMessages(mContactId, mMessageModel.first()->timestamp());
    });
}
