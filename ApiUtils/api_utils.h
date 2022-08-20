/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\api_utils.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 11:48:48
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 18:40:18
 */
#ifndef API_UTILS_H
#define API_UTILS_H

#include <QObject>
#include <QCryptographicHash>
#include <ApiUtils/packet.h>
#include <ApiUtils/socket_utils.h>

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

   private:
    uint32_t getGUID(QString tag);
    SocketUtils* socketUtils;
    uint32_t login_ID = 0, login_ID_trial;
    char login_token[17];

   private slots:
    void resultHandle(QByteArray);

   signals:
    void onLoginCallback(uint8_t);
    void onRegisterCallback(uint8_t);
};

#endif  // API_UTILS_H
