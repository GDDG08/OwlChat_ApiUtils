/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\socket_utils.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 11:25:29
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 18:19:16
 */
#include "socket_utils.h"

// SocketUtils::SocketUtils(ApiUtils* api) {
//     this->dataHandler = api->resultHandle;
//     SocketUtils();
// }

SocketUtils::SocketUtils() {
    this->client = new QTcpSocket();
    // client->connectToHost("localhost", 10000);
    this->client->connectToHost("192.168.192.92", 10000);
    connect(client, SIGNAL(connected()), this, SLOT(connectCallback()));
}

void SocketUtils::connectCallback(void) {
    connect(client, SIGNAL(readyRead()), this, SLOT(recvCallback()), Qt::QueuedConnection);
    qDebug() << "connected";
}

void SocketUtils::recvCallback(void) {
    QByteArray recvArray = client->readAll();
    qDebug() << "RX_orgin--->" << recvArray.toHex();
    for (int end = 0; end < recvArray.size();) {
        int begin = recvArray.indexOf(pak_header, end);
        end = recvArray.indexOf(pak_header, end + 2);
        if (end == -1)
            end = recvArray.size();
        QByteArray kidArray = recvArray.mid(begin, end - begin);
        qDebug() << "RX--->" << kidArray.toHex();
        emit dataReceived(kidArray);
    }
}

int SocketUtils::sendData(QByteArray data) {
    qDebug() << "TX--->" << data.toHex();
    return client->write(data);
}
