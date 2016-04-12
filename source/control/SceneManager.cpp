#include "SceneManager.h"

#include <QDebug>
#include <QQmlContext>

#include "ApplicationManager.h"

SceneManager::SceneManager(QObject *parent) : QObject(parent)
{}

void SceneManager::initialize()
{
    qDebug() << "<SceneManager::initialize> Initializing view";

    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* rootObject = mEngine.rootObjects().at(0);
    if (rootObject != nullptr) {
        MessageManager* messageManager = ApplicationManager::instance().messageManager();
        bool ok = connect(rootObject, SIGNAL(loadMore()), messageManager, SLOT(loadMore()));
        Q_ASSERT(ok);

        ok = connect(rootObject, SIGNAL(selectContact(int)), messageManager, SLOT(reloadMessages(int)));
        Q_ASSERT(ok);
    }

    qDebug() << "<SceneManager::initialize> Initialization done";
}

void SceneManager::registerModel(const QString &modelName, QObject* model)
{
    // get root context from engine
    QQmlContext *context = mEngine.rootContext();

    // store to context
    if (context != nullptr) {
        context->setContextProperty(modelName, model);
    }
}
