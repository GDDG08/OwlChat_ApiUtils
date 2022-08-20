/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\api_utils.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 11:48:48
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 18:40:11
 */
#include "api_utils.h"

ApiUtils::ApiUtils() {
    // socketUtils = new SocketUtils(this);
    socketUtils = new SocketUtils();
    connect(socketUtils, SIGNAL(dataReceived(QByteArray)), this, SLOT(resultHandle(QByteArray)));
}

int ApiUtils::onLogin(uint32_t _id, QString _pwd) {
    qDebug() << "ApiUtils::"
             << "onLogin";
    uint32_t guid = getGUID("login");
    Pak_Login* pak = new Pak_Login(guid, _id, _pwd.toLocal8Bit().data());
    QByteArray* data = new QByteArray((char*)pak, sizeof(*pak));

    socketUtils->sendData(*data);
    this->login_ID_trial = _id;
    return 0;
}

int ApiUtils::onRegister(uint32_t _id, QString _pwd, QString _nickname, uint8_t _gender, uint8_t _age, uint8_t _city, uint8_t _job) {
    qDebug() << "ApiUtils::"
             << "onRegister";
    uint32_t guid = getGUID("register");
    Pak_Register* pak = new Pak_Register(guid, _id, _pwd.toLocal8Bit().data(), _nickname.toLocal8Bit().data(), _gender, _age, _city, _job);
    QByteArray* data = new QByteArray((char*)pak, sizeof(*pak));

    socketUtils->sendData(*data);
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
    }
}
