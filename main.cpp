#include <QGuiApplication>

#include <control/ApplicationManager.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ApplicationManager::instance().initialize();

    return app.exec();
}
