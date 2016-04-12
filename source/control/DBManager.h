#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

#include <model/ChatDataItem.h>

class DBManager : public QObject
{
    Q_OBJECT

public:
    explicit        DBManager(QObject *parent = 0);

    void            initialize();

    QStringList     loadContacts();
    QList<ChatDataItem*> loadContactMessages(int contactId, QDateTime untilTime = QDateTime(), unsigned int limitResults = 5);

private:
    void            insertMockedData();

    QSqlDatabase    mDB;
};

#endif // DBMANAGER_H
