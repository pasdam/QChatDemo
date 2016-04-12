#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QAbstractListModel>
#include <QHash>

#include "ChatDataItem.h"

class MessageModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(bool loading READ loading NOTIFY loadingChanged)

public:
    explicit MessageModel(QObject *parent = 0);

    enum Roles {
        IsMySelfRole = Qt::UserRole + 1,
        FullNameRole,
        MessageRole,
        TimeStampRole
    };

    QHash<int, QByteArray> roleNames() const {
        QHash<int ,QByteArray> roles;
        roles[IsMySelfRole]  = "isMySelf";
        roles[FullNameRole]  = "fullName";
        roles[MessageRole]   = "message";
        roles[TimeStampRole] = "timestamp";
        return roles;
    }

    int         rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant    headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant    data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void        reset();

    void        addItem(ChatDataItem* item);

    ChatDataItem* first();

    bool        loading();
    void        setLoading(bool loading);

signals:
    void        loadingChanged();

private:
    QList<ChatDataItem*> mList;
    bool                 mLoading;
};

#endif // MESSAGEMODEL_H
