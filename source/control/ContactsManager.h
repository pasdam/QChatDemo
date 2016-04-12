#ifndef CONTACTSMANAGER_H
#define CONTACTSMANAGER_H

#include <QObject>
#include <QStringListModel>

class ContactsManager : public QObject
{
    Q_OBJECT

public:
    explicit          ContactsManager(QObject *parent = 0);

    void              initialize();

    QStringListModel* contactsModel();

    void              loadContacts();

    const QString&    getContactName(int userId) const;

private:
    QStringListModel  mContacts;
};

#endif // CONTACTSMANAGER_H
