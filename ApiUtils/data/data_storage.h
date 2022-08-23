/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_storage.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-22 20:15:38
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-23 03:32:57
 */
#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

#include "sql.h"


class DataStorage : public QObject {
    Q_OBJECT
   public:
    explicit DataStorage(QObject* parent = 0);
    ~DataStorage();

    // api
    void getFriendList();
    void getGroupList();
    void getMsg(QString sessionid)

   private:
    QSqlDatabase db;
    void creatDb();
    bool openDb();
    void closeDb();
    void createTable();

   signals:
    
   public slots:
};

#endif  // DATA_STORAGE_H