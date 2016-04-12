#include "ChatDataItem.h"

ChatDataItem::ChatDataItem(QString   fullName,
                   bool      isMyself,
                   QDateTime timestamp,
                   QString   message,
                   QObject *parent)
    : mFullName(fullName)
    , mIsMyself(isMyself)
    , mTimestamp(timestamp)
    , mMessage(message)
    , QObject(parent)
{}

QString ChatDataItem::fullName() const
{
    return mFullName;
}

bool ChatDataItem::isMyself() const
{
    return mIsMyself;
}

QDateTime ChatDataItem::timestamp() const
{
    return mTimestamp;
}

QString ChatDataItem::message() const
{
    return mMessage;
}
