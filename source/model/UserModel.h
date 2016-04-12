#ifndef USERMODEL_H
#define USERMODEL_H

#include <QObject>

class UserModel : public QObject
{
    Q_OBJECT
public:
    explicit UserModel(QObject *parent = 0);

    int getUserId() const;

private:
    int mUserId; // This should be set with the value received from the server
};

#endif // USERMODEL_H
