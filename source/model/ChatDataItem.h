#ifndef CHATITEM_H
#define CHATITEM_H

#include <QDateTime>
#include <QObject>

class ChatDataItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString   fullName   READ fullName  CONSTANT)
    Q_PROPERTY(bool      isMyself   READ isMyself  CONSTANT)
    Q_PROPERTY(QDateTime timestamp  READ timestamp CONSTANT)
    Q_PROPERTY(QString   message    READ message   CONSTANT)

public:
    explicit ChatDataItem(QString   fullName,
                          bool      isMyself,
                          QDateTime timestamp,
                          QString   message,
                          QObject*  parent = 0);

    // getters
    QString   fullName() const;
    bool      isMyself() const;
    QDateTime timestamp() const;
    QString   message() const;

private:
	QString   mFullName;
	bool      mIsMyself;
	QDateTime mTimestamp;
	QString   mMessage;
};

#endif // CHATITEM_H
