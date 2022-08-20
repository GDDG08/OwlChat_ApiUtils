/*
 * @Project      :
 * @FilePath     : \IM-Network\mainwindow.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:50:46
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 18:50:00
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
void MainWindow::test0(uint8_t status) {
    qDebug() << "Login--->" << TASK_STATUS_MSG[status];
}
// DEMO
void MainWindow::test1(uint8_t status) {
    qDebug() << "Register--->" << TASK_STATUS_MSG[status];
}
