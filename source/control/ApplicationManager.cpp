#include "ApplicationManager.h"

#include <QDebug>
#include <QStringList>

#define CONTEXT_MODEL_CONTACTS "contactsModel"
#define CONTEXT_MODEL_MESSAGES "messageModel"

ApplicationManager& ApplicationManager::instance()
{
    static ApplicationManager instance;
    return instance;
}

ApplicationManager::ApplicationManager(QObject *parent)
    : QObject(parent)
    , mContactsManager(this)
    , mDbManager(this)
    , mMessageManager(this)
    , mSceneManager(this)
    , mUserManager(this)
{}

ApplicationManager::~ApplicationManager()
{ }

void ApplicationManager::initialize()
{
    initializeContext();

    mDbManager      .initialize();

    mContactsManager.initialize();
    mSceneManager   .initialize();
}

void ApplicationManager::initializeContext()
{
    mSceneManager.registerModel(CONTEXT_MODEL_CONTACTS, mContactsManager.contactsModel());
    mSceneManager.registerModel(CONTEXT_MODEL_MESSAGES, mMessageManager.messageModel());
}

ContactsManager* ApplicationManager::contactsManager()
{
    return &mContactsManager;
}

DBManager *ApplicationManager::dbManager()
{
    return &mDbManager;
}

MessageManager* ApplicationManager::messageManager()
{
    return &mMessageManager;
}

SceneManager* ApplicationManager::sceneManager()
{
    return &mSceneManager;
}

UserManager* ApplicationManager::userManager()
{
    return &mUserManager;
}
