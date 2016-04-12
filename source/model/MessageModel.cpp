#include "MessageModel.h"

#include <QDebug>

MessageModel::MessageModel(QObject *parent)
    : QAbstractListModel(parent)
    , mLoading(false)
{}

int MessageModel::rowCount(const QModelIndex&) const
{
    return mList.size();
}

QVariant MessageModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && section == 0) {
        switch (role) {
            case IsMySelfRole:
                return "Is my self";

            case FullNameRole:
                return "Full name";

            case MessageRole:
                return "Message";

            case TimeStampRole:
                return "TimeStamp";
        }
    }
    return QVariant();
}

QVariant MessageModel::data(const QModelIndex &index, int role) const
{
    int rowIndex = index.row();


    if (rowIndex >= 0 && rowIndex < mList.size()) {
        switch (role) {
            case IsMySelfRole:
                return mList.at(rowIndex)->isMyself();

            case FullNameRole:
                return mList.at(rowIndex)->fullName();

            case MessageRole:
                return mList.at(rowIndex)->message();

            case TimeStampRole:
                return mList.at(rowIndex)->timestamp();
        }
    }

    return QVariant();
}

void MessageModel::reset()
{
    beginResetModel();

    for (int i = mList.size()-1; i >= 0; i--) {
        mList.takeAt(i)->deleteLater();
    }

    endResetModel();
}

void MessageModel::addItem(ChatDataItem *item)
{
    // TODO: find a more efficient way
    int insertionIndex = mList.size();
    for (int i = 0; i < mList.size(); i++) {
        if (item->timestamp() < mList.at(i)->timestamp()) {
            insertionIndex = i;
            break;
        }
    }

    beginInsertRows(QModelIndex(), insertionIndex, insertionIndex);

    mList.insert(insertionIndex, item);

    endInsertRows();
}

ChatDataItem *MessageModel::first()
{
    return mList.first();
}

bool MessageModel::loading()
{
    return mLoading;
}

void MessageModel::setLoading(bool loading)
{
    if (loading != mLoading) {
        qDebug() << "<MessageModel::setLoading> Changing value to " << (loading ? "true" : "false");

        mLoading = loading;
        emit loadingChanged();
    }
}
