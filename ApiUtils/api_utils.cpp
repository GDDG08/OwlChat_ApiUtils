/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\api_utils.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 11:48:48
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-21 01:49:12
 */
#include "api_utils.h"

ApiUtils::ApiUtils() {
    // socketUtils = new SocketUtils(this);
    socketUtils = new SocketUtils();
    connect(socketUtils, SIGNAL(dataReceived(QByteArray)), this, SLOT(resultHandle(QByteArray)), Qt::QueuedConnection);
}

int ApiUtils::onLogin(uint32_t _id, QString _pwd) {
    qDebug() << "ApiUtils::"
             << "onLogin";
    uint32_t guid = getGUID("login");

    QString _pwd_md5 = QCryptographicHash::hash(_pwd.toLatin1(), QCryptographicHash::Md5).toHex().right(16);
    Pak_Login* pak = new Pak_Login(_id, _pwd_md5.toLocal8Bit().data());
    pak->GUID = guid;
    QByteArray* data = new QByteArray((char*)pak, sizeof(*pak));

    socketUtils->sendData(*data);
    this->login_ID_trial = _id;
    return 0;
}

int ApiUtils::onRegister(uint32_t _id, QString _pwd, QString _nickname, uint8_t _gender, uint8_t _age, uint8_t _city, uint8_t _job) {
    qDebug() << "ApiUtils::"
             << "onRegister";
    uint32_t guid = getGUID("register");

    QString _pwd_md5 = QCryptographicHash::hash(_pwd.toLatin1(), QCryptographicHash::Md5).toHex().right(16);
    Pak_Register* pak = new Pak_Register(_id, _pwd_md5.toLocal8Bit().data(), _nickname.toLocal8Bit().data(), _gender, _age, _city, _job);
    pak->GUID = guid;
    QByteArray* data = new QByteArray((char*)pak, sizeof(*pak));

    socketUtils->sendData(*data);
    return 0;
}

int ApiUtils::sendMessage(uint32_t _sessionID, uint64_t _time, uint8_t _msg_type, QString _content) {
    qDebug() << "ApiUtils::"
             << "sendMessage";
    uint32_t guid = getGUID("msg");

    uint32_t _msg_len = _content.size() + 1;
    Pak_Message* pak = new Pak_Message(this->login_ID, _sessionID, _time, _msg_type, _msg_len, _content);
    pak->GUID = guid;
    strcpy(pak->token, login_token);
    QByteArray* data = new QByteArray((char*)pak, sizeof(*pak));
    data->chop(sizeof(char*));
    data->append(_content + '\0');

    int a = socketUtils->sendData(*data);
    qDebug() << a;
    return 0;
}

uint32_t ApiUtils::getGUID(QString tag) {
    return 111111112;
}

void ApiUtils::resultHandle(QByteArray data) {
    qDebug() << "ApiUtils::"
             << "resultHandle";

    PacketRTN* pak = (PacketRTN*)data.data();
    switch (pak->type) {
        case PACKET_TYPE::LOGIN: {
            Pak_LoginRTN* rtn = (Pak_LoginRTN*)data.data();
            qDebug() << "LOGIN-->"
                     << "msg:" << pak->msg << ", token:" << rtn->token;
            if (pak->msg == TASK_STATUS::SUCCESS) {
                this->login_ID = this->login_ID_trial;
                strcpy(login_token, rtn->token);
            }
            emit onLoginCallback(pak->msg);
        } break;
        case PACKET_TYPE::REGISTER: {
            qDebug() << "REGISTER-->"
                     << "msg:" << pak->msg;
            emit onRegisterCallback(pak->msg);
        } break;
        case PACKET_TYPE::SEND_MESSAGE: {
            qDebug() << "SEND_MESSAGE-->"
                     << "msg:" << pak->msg;
            emit sendMessageCallback(pak->msg);
        } break;
        case PACKET_TYPE::RECV_MESSAGE: {
            Pak_Message* rtn = (Pak_Message*)data.data();
            char* buff = (char*)&rtn->content;
            QByteArray byteArray(buff, rtn->msg_len);
            QString content(buff);
            qDebug() << "RECV_MESSAGE-->"
                     << "fromUser:" << rtn->userID << ", toSession:" << rtn->sessionID << ", type:" << rtn->msg_type << ", msg:" << content;
            emit recvMessageCallback(rtn->userID, rtn->sessionID, rtn->time, rtn->msg_type, content);
        } break;
    }
}
