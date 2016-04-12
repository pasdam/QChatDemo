#include "UserModel.h"

UserModel::UserModel(QObject *parent)
    : QObject(parent)
    , mUserId(0)
{}

int UserModel::getUserId() const
{
    return mUserId;
}
