/*
 * @Project      :
 * @FilePath     : \IM-Network\mainwindow.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:50:46
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 18:35:43
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ApiUtils/api_utils.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

   private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void test0(uint8_t);
    void test1(uint8_t);

   private:
    Ui::MainWindow* ui;
    ApiUtils* api;
};

#endif  // MAINWINDOW_H
