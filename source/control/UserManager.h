#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>

#include <model/UserModel.h>

class UserManager : public QObject
{
    Q_OBJECT

public:
    explicit UserManager(QObject *parent = 0);

    const UserModel& userModel() const;

private:
    UserModel mUserModel;
};

#endif // USERMANAGER_H
