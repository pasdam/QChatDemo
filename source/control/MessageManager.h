#ifndef CHATMANAGER_H
#define CHATMANAGER_H

#include <QObject>

#include <source/model/ChatDataItem.h>
#include <source/model/MessageModel.h>

class MessageManager : public QObject
{
    Q_OBJECT

public:
    explicit MessageManager(QObject *parent = 0);

    MessageModel* messageModel();

    QList<ChatDataItem> previousMessages(const QDateTime& timestamp);

public slots:
    void        reloadMessages(int contactId);
    void        loadMore();

private:
    void        loadMessages(int contactId, const QDateTime& untilTime = QDateTime());

    int          mContactId;

    MessageModel mMessageModel;
};

#endif // CHATMANAGER_H
