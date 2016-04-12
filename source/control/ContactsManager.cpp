#include "ContactsManager.h"

#include <QDebug>

#include "ApplicationManager.h"

ContactsManager::ContactsManager(QObject *parent) : QObject(parent)
{}

void ContactsManager::initialize()
{
    loadContacts();
}

QStringListModel* ContactsManager::contactsModel()
{
    return &mContacts;
}

void ContactsManager::loadContacts()
{
    QStringList contacts = ApplicationManager::instance().dbManager()->loadContacts();
    mContacts.setStringList(contacts);

    qDebug() << "<ContactsManager::loadContacts> Loaded " << contacts.size() << " contact(s)";
}

const QString& ContactsManager::getContactName(int userId) const
{
    if (userId >= 0 && userId < mContacts.rowCount()) {
        return mContacts.stringList().at(userId);

    } else {
        return QString();
    }
}
