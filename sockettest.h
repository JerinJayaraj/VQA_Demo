#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTcpSocket>
#include <QDebug>

class SocketTest : public QObject
{
    Q_OBJECT
    public:
        explicit SocketTest(QObject *parent = nullptr);

    QString Connect();
    signals:

    public slots:

    private:
        QTcpSocket *socket;
};

#endif // SOCKETTEST_H
