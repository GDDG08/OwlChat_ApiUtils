/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\api_utils.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 11:48:48
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-21 01:50:12
 */
#ifndef API_UTILS_H
#define API_UTILS_H

#include <QObject>
#include <QCryptographicHash>
#include <ApiUtils/packet.h>
#include <ApiUtils/socket_utils.h>
#include <ApiUtils/tools/logger.h>

enum TASK_STATUS {
    SUCCESS = 0,
    NO_USER_ERROR,
    WRONG_PWD_ERROR,
    USER_EXISTED_ERROR
};

const QString TASK_STATUS_MSG[]{
    "SUCCESS",
    "NO_USER_ERROR",
    "WRONG_PWD_ERROR",
    "USER_EXISTED_ERROR"};

class ApiUtils : public QObject {
    Q_OBJECT

   public:
    ApiUtils();
    int onLogin(uint32_t, QString);
    int onRegister(uint32_t _id, QString _pwd, QString _nickname, uint8_t _gender, uint8_t _age, uint8_t _city, uint8_t _job);
    int sendMessage(uint32_t _sessionID, uint64_t _time, uint8_t _msg_type, QString _content);

   private:
    uint32_t getGUID(QString tag);
    SocketUtils* socketUtils;
    uint32_t login_ID = 0, login_ID_trial = 0;
    char login_token[17] = {0};

   private slots:
    void resultHandle(QByteArray);

   signals:
    void onLoginCallback(uint8_t);
    void onRegisterCallback(uint8_t);
    void sendMessageCallback(uint8_t);
    void recvMessageCallback(uint32_t fromUserID, uint32_t sessionID, uint64_t time, uint8_t msg_type, QString content);
};

#endif  // API_UTILS_H
