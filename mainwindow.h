/*
 * @Project      :
 * @FilePath     : \IM-Network\mainwindow.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:50:46
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-23 02:36:55
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void test0(uint8_t);
    void test1(uint8_t);
    void test2(uint8_t, uint32_t);
    void test3(uint32_t fromUserID, uint32_t sessionID, uint64_t time, uint32_t msgID, uint8_t msg_type, QString content);
    void test4(QList<D_UserBasicInfo> friend_list);
    void test5(uint8_t, uint32_t);
    void test6(uint8_t, uint32_t);
    void test7(uint8_t, uint32_t);
    void test8(uint32_t, QString);
    void test9(uint32_t userID_client, bool isAccepted);
    void test10(D_UserBasicInfo info);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::MainWindow* ui;
    ApiUtils* api;
};

#endif  // MAINWINDOW_H
