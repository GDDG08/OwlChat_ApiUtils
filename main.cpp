/*
 * @Project      :
 * @FilePath     : \IM-Network\main.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:50:46
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-23 01:05:34
 */
#include "mainwindow.h"
#include <QApplication>
#include <ApiUtils/tools/logger.h>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    // qInstallMessageHandler(myMessageHandle);
    MainWindow w;
    w.show();

    return a.exec();
}
