#include "UserManager.h"

UserManager::UserManager(QObject *parent) : QObject(parent)
{}

const UserModel &UserManager::userModel() const
{
    return mUserModel;
}
