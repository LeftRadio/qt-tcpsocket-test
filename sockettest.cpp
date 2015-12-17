#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("192.168.1.119", 2323);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";


        QByteArray ba;
        ba.resize(6);
        ba[0] = 0x5b;
        ba[1] = 0x81;
        ba[2] = 0x02;
        ba[3] = 0x86;
        ba[4] = 0x93;
        ba[5] = 0x51;

        // send
        socket->write(ba);
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();

        /* blocking while connection no closed */
        // qDebug() << socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }

    // sent

    // got

    // closed
}
