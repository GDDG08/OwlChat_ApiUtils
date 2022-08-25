/*
 * @Project      :
 * @FilePath     : \IM-Network2\mainwindow.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:50:46
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-25 10:04:12
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // DEMO
    api = new ApiUtils(this);
    connect(api, SIGNAL(onLoginCallback(uint8_t)), this, SLOT(test0(uint8_t)));
    connect(api, SIGNAL(onRegisterCallback(uint8_t)), this, SLOT(test1(uint8_t)));
    connect(api, SIGNAL(sendMessageCallback(uint8_t, uint32_t)), this, SLOT(test2(uint8_t, uint32_t)));
    connect(api, SIGNAL(recvMessageCallback(uint32_t, uint32_t, uint64_t, uint32_t, uint8_t, QString)), this, SLOT(test3(uint32_t, uint32_t, uint64_t, uint32_t, uint8_t, QString)));
    connect(api, SIGNAL(getFriendListCallback(QList<D_UserBasicInfo>)), this, SLOT(test4(QList<D_UserBasicInfo>)));
    connect(api, SIGNAL(getUserInfoCallback(D_UserBasicInfo)), this, SLOT(test10(D_UserBasicInfo)));
    connect(api, SIGNAL(onFriendAddCallback(uint8_t, uint32_t)), this, SLOT(test5(uint8_t, uint32_t)));
    connect(api, SIGNAL(onFriendDeleteCallback(uint8_t, uint32_t)), this, SLOT(test6(uint8_t, uint32_t)));
    connect(api, SIGNAL(onFriendAcceptCallback(uint8_t, uint32_t)), this, SLOT(test7(uint8_t, uint32_t)));
    connect(api, SIGNAL(onFriendRequestCallback(uint32_t, QString)), this, SLOT(test8(uint32_t, QString)));
    connect(api, SIGNAL(onFriendResultCallback(uint32_t, bool)), this, SLOT(test9(uint32_t, bool)));
}

MainWindow::~MainWindow() {
    delete ui;
}

#define USER_2

// DEMO
void MainWindow::on_pushButton_clicked() {
#ifdef USER_1
    // api->onLogin(111111, "123456&dsw!");
    api->onLogin(111111, "123456&dsw!");
#else
    // api->onLogin(3333333, "123456&dsw!");
    api->onLogin(222222, "123456&dsw!");
#endif
}
// DEMO
void MainWindow::on_pushButton_2_clicked() {
#ifdef USER_1
    api->onRegister(111111, "123456&dsw!", "lyh", 1u, 20u, 8u, 8u);
    // api->onRegister(3333333, "123456&dsw!", "lyh", 1u, 20u, 8u, 8u);
    // api->onRegister(11, "11", "lyh2", 1u, 20u, 8u, 8u);
#else
    api->onRegister(222222, "123456&dsw!", "GDDG08", 1u, 20u, 8u, 8u);
#endif
}
// DEMO
void MainWindow::on_pushButton_3_clicked() {
#ifdef USER_1
    api->sendMessage(222222, 0, 12344, 0, "abc123!@#");

#else
    api->sendMessage(111111, 0, 12344, 0, "abc123!@#");
#endif
}
void MainWindow::on_pushButton_4_clicked() {
    api->getFriendList();
}
void MainWindow::on_pushButton_5_clicked() {
#ifdef USER_1
    api->onFriendAdd(222222, "love from China");
    // api->onFriendAdd(222222, "love from China");
#else
    api->onFriendAdd(111111, "love from America");
#endif
}

void MainWindow::on_pushButton_6_clicked() {
#ifdef USER_1
    api->onFriendDelete(222222);
#else
    api->onFriendDelete(111111);
#endif
}

void MainWindow::on_pushButton_7_clicked() {
#ifdef USER_1
    api->onFriendAccept(222222, true);
#else
    api->onFriendAccept(111111, true);
#endif
}

// DEMO
void MainWindow::test0(uint8_t status) {
    qDebug() << "Login--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "Login--->" + TASK_STATUS_MSG[status]);
}
// DEMO
void MainWindow::test1(uint8_t status) {
    qDebug() << "Register--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "Register--->" + TASK_STATUS_MSG[status]);
}
// DEMO
void MainWindow::test2(uint8_t status, uint32_t msgID) {
    qDebug() << "SendMsg--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "SendMsg--->" + TASK_STATUS_MSG[status]);
}
void MainWindow::test3(uint32_t fromUserID, uint32_t sessionID, uint64_t time, uint32_t msgID, uint8_t msg_type, QString content) {
    qDebug() << "RecvMsg--->" << content;
    QMessageBox::information(this, "Api Result", "RecvMsg--->" + content);
}
void MainWindow::test4(QList<D_UserBasicInfo> friend_list) {
    qDebug() << "FriendList--->"
             << "size: " << friend_list.size();
    QMessageBox::information(this, "Api Result",
                             "FriendList--->"
                             "size: " +
                                 QString::number(friend_list.size()));
}
// DEMO
void MainWindow::test5(uint8_t status, uint32_t userID_client) {
    qDebug() << "FriendAdd--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "FriendAdd--->" + TASK_STATUS_MSG[status]);
}
// DEMO
void MainWindow::test6(uint8_t status, uint32_t userID_client) {
    qDebug() << "FriendDelete--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "FriendDelete--->" + TASK_STATUS_MSG[status]);
}
// DEMO
void MainWindow::test7(uint8_t status, uint32_t userID_client) {
    qDebug() << "FriendAccept--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "FriendAccept--->" + TASK_STATUS_MSG[status]);
}

void MainWindow::test8(uint32_t fromUserID, QString verify_msg) {
    qDebug() << "FriendRequest--->"
             << "fromUserID:" << fromUserID;
    QMessageBox::information(this, "Api Result",
                             "FriendRequest--->"
                             "fromUserID:" +
                                 QString::number(fromUserID) + ", verify_msg:" + verify_msg);
}

void MainWindow::test9(uint32_t userID_client, bool isAccepted) {
    qDebug() << "FriendResult--->"
             << "userID_client:" << userID_client << ", isAccepted:" << isAccepted;
    QMessageBox::information(this, "Api Result",
                             "FriendResult--->"
                             "userID_client:" +
                                 QString::number(userID_client) + ", isAccepted:" + QString::number(isAccepted));
}

void MainWindow::test10(D_UserBasicInfo info) {
    qDebug() << "UserInfo--->"
             << "userID: " << info.userID;
    QMessageBox::information(this, "Api Result",
                             "USER_INFO-->"
                             "userID:" +
                                 QString::number(info.userID) + ", nickname:" + QString(info.nickName) + ", avatarID:" + QString::number(info.avatarID));
}

void MainWindow::on_pushButton_8_clicked() {
#ifdef USER_1
    api->getUserInfo(111111);
#else
    api->getUserInfo(222222);
#endif
}

void MainWindow::on_pushButton_9_clicked() {
#ifdef USER_1
    api->getUserDetail(111111);
#else
    api->getUserDetail(222222);
#endif
}

void MainWindow::on_pushButton_11_clicked() {
    api->onGroupCreate("JB");
}

void MainWindow::on_pushButton_10_clicked() {
#ifdef USER_1
    api->onGroupAdd(1);
#else
    api->onGroupAdd(1, 111111);
#endif
}

void MainWindow::on_pushButton_12_clicked() {
#ifdef HTTP_ENABLE
    // api->onSendFile("C:/IM/mainwindow.h");
    api->onSendFile(111111, SESSION_TYPE::S_FRIEND, 0, "C:/IM/readme.txt");
    // api->onSendFile("D:/Download/Video/观看 Top Gun- Maverick 完整电影在线免费.mp4");
#endif
}

void MainWindow::on_pushButton_13_clicked() {
#ifdef HTTP_ENABLE
    api->onDownFile(5, "C:/down/");
#endif
}

void MainWindow::on_pushButton_14_clicked() {
    api->getGroupInfo(1);
}

void MainWindow::on_pushButton_15_clicked() {
    api->getGroupList();
}

void MainWindow::on_pushButton_19_clicked() {
    api->sendMessage(1, SESSION_TYPE::S_GROUP, 0, MSG_TYPE::M_TEXT, "HELLO!!!");
}
