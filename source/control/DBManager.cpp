#include "DBManager.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlResult>

#include "ApplicationManager.h"
#include "UserManager.h"

#define DB_PATH     "db.sqlite"

DBManager::DBManager(QObject *parent) : QObject(parent)
{}

void DBManager::initialize()
{
    mDB = QSqlDatabase::addDatabase("QSQLITE");
    mDB.setDatabaseName(DB_PATH);

    bool ok = mDB.open();
    Q_ASSERT(ok);

    // DEBUG
    insertMockedData();
    // END_DEBUG
}

QStringList DBManager::loadContacts()
{
    QStringList results;
    QSqlQuery query;

    query.exec("SELECT fullName FROM contacts");
    while (query.next()) {
        results << query.value(0).toString();
    }

    qDebug() << "<DBManager::loadContactMessages> Loaded " << results.size() << " contacts";

    return results;
}

QList<ChatDataItem*> DBManager::loadContactMessages(int contactId, QDateTime untilTime, unsigned int limitResults)
{
    QSqlQuery query;
    if (untilTime.isValid()) {
        query.exec(QString("SELECT * FROM messages WHERE uid = %1 AND timestamp < %2 ORDER BY timestamp DESC LIMIT %3")
               .arg(contactId)
               .arg(untilTime.toMSecsSinceEpoch())
               .arg(limitResults));

    } else {
        query.exec(QString("SELECT * FROM messages WHERE uid = %1 ORDER BY timestamp DESC LIMIT %2;")
                   .arg(contactId)
                   .arg(limitResults));
    }

    QList<ChatDataItem*> results;
    ContactsManager* contactManager = ApplicationManager::instance().contactsManager();
    int myUid = ApplicationManager::instance().userManager()->userModel().getUserId();

    while (query.next()) {
        int senderId     = query.value(1).toInt();
        qint64 timestamp = query.value(2).toInt();
        QString message  = query.value(3).toString();

        ChatDataItem* item = new ChatDataItem(
            contactManager->getContactName(senderId),
            senderId == myUid,
            QDateTime::fromMSecsSinceEpoch(timestamp),
            message
        );

        results.append(item);
    }

    qDebug() << "<DBManager::loadContactMessages> Loaded " << results.size() << " messages";

    return results;
}

void DBManager::insertMockedData()
{
    QSqlQuery query;

    query.exec("CREATE TABLE contacts (id int primary key, "
                                      "fullName varchar(40))");

    query.exec("INSERT INTO contacts VALUES (1, 'Bill Gates')");
    query.exec("INSERT INTO contacts VALUES (2, 'Linus Torvalds')");
    query.exec("INSERT INTO contacts VALUES (3, 'Sergey Brin')");
    query.exec("INSERT INTO contacts VALUES (4, 'Larry page')");
    query.exec("INSERT INTO contacts VALUES (5, 'Mark Zuckemberg')");
    query.exec("INSERT INTO contacts VALUES (6, 'Luke Skywalker')");
    query.exec("INSERT INTO contacts VALUES (7, 'Yoda')");
    query.exec("INSERT INTO contacts VALUES (8, 'Thomas Anderson')");
    query.exec("INSERT INTO contacts VALUES (9, 'Tony Stark')");
    query.exec("INSERT INTO contacts VALUES (10, 'Bruce Banner')");
    query.exec("INSERT INTO contacts VALUES (11, 'Bruce Wayne')");
    query.exec("INSERT INTO contacts VALUES (12, 'Peter Parker')");
    query.exec("INSERT INTO contacts VALUES (13, 'Luke Cage')");

    query.exec("CREATE TABLE messages (uid int NOT NULL, "
                                      "senderId int NOT NULL, "
                                      "timestamp int NOT NULL, "
                                      "message varchar(150), "
                                      "PRIMARY KEY (uid, senderId, timestamp))");

    query.exec("INSERT INTO messages VALUES (1, 1, 1460311200, 'hi')");
    query.exec("INSERT INTO messages VALUES (1, 1, 1460311210, 'how are you')");
    query.exec("INSERT INTO messages VALUES (1, 0, 1460311414, 'fine thanks')");
    query.exec("INSERT INTO messages VALUES (1, 0, 1460311449, 'you?')");
    query.exec("INSERT INTO messages VALUES (1, 1, 1460311569, 'fine')");
    query.exec("INSERT INTO messages VALUES (1, 1, 1460311611, 'are U ready 4 the interview?')");
    query.exec("INSERT INTO messages VALUES (1, 0, 1460311666, 'of course')");
    query.exec("INSERT INTO messages VALUES (1, 0, 1460311706, ';)')");

    query.exec("INSERT INTO messages VALUES (2, 0, 1460311200, 'do you like the app?')");
    query.exec("INSERT INTO messages VALUES (2, 2, 1460311210, 'it is awesome!!')");

    query.exec("INSERT INTO messages VALUES (3, 3, 1460306200, 'message-1460306200')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460306210, 'message-1460306210')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460306414, 'message-1460306414')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460306449, 'message-1460306449')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460306569, 'message-1460306569')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460306611, 'message-1460306611')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460306666, 'message-1460306666')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460306706, 'message-1460306706')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460307200, 'message-1460307200')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460307210, 'message-1460307210')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460307414, 'message-1460307414')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460307449, 'message-1460307449')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460307569, 'message-1460307569')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460307611, 'message-1460307611')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460307666, 'message-1460307666')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460307706, 'message-1460307706')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460308200, 'message-1460308200')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460308210, 'message-1460308210')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460308414, 'message-1460308414')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460308449, 'message-1460308449')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460308569, 'message-1460308569')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460308611, 'message-1460308611')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460308666, 'message-1460308666')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460308706, 'message-1460308706')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460309200, 'message-1460309200')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460309210, 'message-1460309210')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460309414, 'message-1460309414')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460309449, 'message-1460309449')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460309569, 'message-1460309569')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460309611, 'message-1460309611')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460309666, 'message-1460309666')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460309706, 'message-1460309706')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460310200, 'message-1460310200')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460310210, 'message-1460310210')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460310414, 'message-1460310414')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460310449, 'message-1460310449')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460310569, 'message-1460310569')");
    query.exec("INSERT INTO messages VALUES (3, 3, 1460310611, 'message-1460310611')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460310666, 'message-1460310666')");
    query.exec("INSERT INTO messages VALUES (3, 0, 1460310706, 'message-1460310706')");
}

