#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QAbstractItemModel>
#include <QObject>
#include <QQmlApplicationEngine>

class SceneManager : public QObject
{
    Q_OBJECT

public:
    explicit SceneManager(QObject *parent = 0);

    void initialize();

    void registerModel(const QString& modelName, QObject *model);

private:
    QQmlApplicationEngine mEngine;
};

#endif // SCENEMANAGER_H
