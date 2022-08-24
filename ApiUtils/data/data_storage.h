/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_storage.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-22 20:15:38
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-24 17:47:00
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
#include <vector>

    typedef std::vector<std::vector<QVariant>> DataResult;
class DataStorage : public QObject {
    Q_OBJECT
   public:
    explicit DataStorage(QObject* parent = 0);
    ~DataStorage();

    // api
    void getFriendList();
    void getGroupList();
    void getMsg(QString sessionid);
    int select(DataResult& res, std::string _sql, int resultNum);

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