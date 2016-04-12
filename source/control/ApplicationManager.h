#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <QObject>

#include "ContactsManager.h"
#include "DBManager.h"
#include "MessageManager.h"
#include "SceneManager.h"
#include "UserManager.h"

class ApplicationManager : public QObject
{
    Q_OBJECT

public:

    static ApplicationManager& instance();

    void initialize();

    ContactsManager* contactsManager();
    DBManager*       dbManager();
    MessageManager*  messageManager();
    SceneManager*    sceneManager();
    UserManager*     userManager();

private:
    ApplicationManager(QObject *parent = nullptr);
    virtual ~ApplicationManager();
    ApplicationManager(const ApplicationManager& other);
    ApplicationManager& operator= (const ApplicationManager&);

    void initializeContext();

    ContactsManager  mContactsManager;
    DBManager        mDbManager;
    MessageManager   mMessageManager;
    SceneManager     mSceneManager;
    UserManager      mUserManager;
};

#endif // APPLICATIONMANAGER_H
