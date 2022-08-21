/*
 * @Project      :
 * @FilePath     : \IM-Network\mainwindow.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:50:46
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-22 03:06:48
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // DEMO
    api = new ApiUtils();
    connect(api, SIGNAL(onLoginCallback(uint8_t)), this, SLOT(test0(uint8_t)));
    connect(api, SIGNAL(onRegisterCallback(uint8_t)), this, SLOT(test1(uint8_t)));
    connect(api, SIGNAL(sendMessageCallback(uint8_t)), this, SLOT(test2(uint8_t)));
    connect(api, SIGNAL(recvMessageCallback(uint32_t, uint32_t, uint64_t, uint8_t, QString)), this, SLOT(test3(uint32_t, uint32_t, uint64_t, uint8_t, QString)));
    connect(api, SIGNAL(getFriendListCallback(QList<Pak_FriendBasicInfo>)), this, SLOT(test4(QList<Pak_FriendBasicInfo>)));
    connect(api, SIGNAL(onFriendAddCallback(uint8_t)), this, SLOT(test5(uint8_t)));
    connect(api, SIGNAL(onFriendDeleteCallback(uint8_t)), this, SLOT(test6(uint8_t)));
    connect(api, SIGNAL(onFriendAcceptCallback(uint8_t)), this, SLOT(test7(uint8_t)));
    connect(api, SIGNAL(onFriendRequestCallback(uint32_t, QString)), this, SLOT(test8(uint32_t, QString)));
}

MainWindow::~MainWindow() {
    delete ui;
}

#define USER_2
// DEMO
void MainWindow::on_pushButton_clicked() {
#ifdef USER_1
    api->onLogin(11111, "123456&dsw!");
#else
    api->onLogin(222222001, "123456&dsw!");
#endif
}
// DEMO
void MainWindow::on_pushButton_2_clicked() {
#ifdef USER_1
    api->onRegister(11111, "123456&dsw!", "lyh", 1u, 20u, 8u, 8u);
#else
    api->onRegister(222222001, "123456&dsw!", "GDDG08", 1u, 20u, 8u, 8u);
#endif
}
// DEMO
void MainWindow::on_pushButton_3_clicked() {
#ifdef USER_1
    api->sendMessage(22222, 12344, 0, "abc123!@#");
#else
    api->sendMessage(11111, 12344, 0, "abc123!@#");
#endif
}
void MainWindow::on_pushButton_4_clicked() {
    api->getFriendList();
}
void MainWindow::on_pushButton_5_clicked() {
    api->onFriendAdd(123, "love from China");
}

void MainWindow::on_pushButton_6_clicked() {
    api->onFriendDelete(123);
}

void MainWindow::on_pushButton_7_clicked() {
    api->onFriendAccept(1234, true);
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
void MainWindow::test2(uint8_t status) {
    qDebug() << "SendMsg--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "SendMsg--->" + TASK_STATUS_MSG[status]);
}
void MainWindow::test3(uint32_t fromUserID, uint32_t sessionID, uint64_t time, uint8_t msg_type, QString content) {
    qDebug() << "RecvMsg--->" << content;
    QMessageBox::information(this, "Api Result", "RecvMsg--->" + content);
}
void MainWindow::test4(QList<Pak_FriendBasicInfo> friend_list) {
    qDebug() << "FriendList--->"
             << "size: " << friend_list.size();
    QMessageBox::information(this, "Api Result",
                             "FriendList--->"
                             "size: " +
                                 QString::number(friend_list.size()));
}
// DEMO
void MainWindow::test5(uint8_t status) {
    qDebug() << "FriendAdd--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "FriendAdd--->" + TASK_STATUS_MSG[status]);
}
// DEMO
void MainWindow::test6(uint8_t status) {
    qDebug() << "FriendDelete--->" << TASK_STATUS_MSG[status];
    QMessageBox::information(this, "Api Result", "FriendDelete--->" + TASK_STATUS_MSG[status]);
}
// DEMO
void MainWindow::test7(uint8_t status) {
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
