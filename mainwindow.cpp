/*
 * @Project      :
 * @FilePath     : \IM-Network\mainwindow.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:50:46
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-21 01:50:44
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
    connect(api, SIGNAL(recvMessageCallback(uint32_t , uint32_t , uint64_t , uint8_t , QString )), this, SLOT(test3(uint32_t , uint32_t , uint64_t , uint8_t , QString)));
}

MainWindow::~MainWindow() {
    delete ui;
}

// DEMO
void MainWindow::on_pushButton_clicked() {
    api->onLogin(1234435, "123456&dsw!");
}
// DEMO
void MainWindow::on_pushButton_2_clicked() {
    api->onRegister(1234435, "123456&dsw!", "GDDG80", 1u, 20u, 8u, 8u);
}
// DEMO
void MainWindow::on_pushButton_3_clicked() {
    api->sendMessage(1234435, 12344, 0, "abc123!@#");
}
// DEMO
void MainWindow::test0(uint8_t status) {
    qDebug() << "Login--->" << TASK_STATUS_MSG[status];
}
// DEMO
void MainWindow::test1(uint8_t status) {
    qDebug() << "Register--->" << TASK_STATUS_MSG[status];
}
// DEMO
void MainWindow::test2(uint8_t status) {
    qDebug() << "SendMsg--->" << TASK_STATUS_MSG[status];
}
void MainWindow::test3(uint32_t fromUserID, uint32_t sessionID, uint64_t time, uint8_t msg_type ,QString content) {
    qDebug() << "RecvMsg--->" << content;
}
