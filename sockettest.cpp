#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}
void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1",6000);

    if(socket->waitForConnected(5000))
    {
        qDebug() <<"Connected";
        socket->close();
    }

    else
    {
        qDebug() <<"Not Connected";
    }
}
