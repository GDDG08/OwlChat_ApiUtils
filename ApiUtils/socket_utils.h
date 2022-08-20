/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\socket_utils.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 11:25:29
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 18:07:47
 */
#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>
#include <ApiUtils/byte_convert.h>

// typedef int (*DataHandler)(QByteArray);
const char SOCKET_PACKET_HEADR_0 = 0xa5;
const char SOCKET_PACKET_HEADR_1 = 0x5a;

class SocketUtils : public QObject {
    Q_OBJECT

   public:
    // SocketUtils(ApiUtils* api);
    SocketUtils();
    int sendData(QByteArray);

   private:
    QTcpSocket* client;
    // DataHandler dataHandler;
    char pak_header[3] = {SOCKET_PACKET_HEADR_0, SOCKET_PACKET_HEADR_1, '\0'};

   private slots:
    void
    connectCallback(void);
    void recvCallback(void);

   signals:
    void dataReceived(QByteArray);
};

#endif  // SOCKET_UTILS_H
