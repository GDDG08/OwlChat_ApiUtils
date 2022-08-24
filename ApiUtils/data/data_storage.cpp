/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_storage.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-22 20:15:38
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-24 19:19:18
 */
#include "data_storage.h"

DataStorage::DataStorage(QObject* parent)
    : QObject(parent) {
    qDebug() << QSqlDatabase::drivers();
    creatDb();
    if (!openDb())
        return;
    createTable();
    // QSqlQuery query;
    // query.exec("select * from test");

    // while (query.next()) {
    //     QString userID = query.value("username").toString();
    //     qDebug() << userID;
    // }

    // struct UserInfo{
    //     int char
    // }
    // QList<UserInfo>
    // DataResult r;
    // select(r, "select * from user", 10);
    // qDebug() << "select";
}

DataStorage::~DataStorage() {
    closeDb();
}

void DataStorage::creatDb() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        qDebug() << "QSqlDatabase::"
                 << "Database connected";
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        qDebug() << "QSqlDatabase::"
                 << "Database added";
        db = QSqlDatabase::addDatabase("QSQLITE");
        // system("IF NOT EXIST \"C:/OwlChat\" MD  \"C:/OwlChat\" ");
        db.setDatabaseName("C:/IM/test.db");
        // mklink /J C:\IM D:\@Projects\Qt\IM-Network
        db.setUserName("admin");
        db.setPassword("admin");
    }
}

bool DataStorage::openDb() {
    if (!db.open()) {
        qDebug() << "QSqlDatabase::"
                 << "Error: Failed to connect database." << db.lastError();
        return false;
    }
    qDebug() << "QSqlDatabase::"
             << "Database opened";
    return true;
}
void DataStorage::closeDb() {
    qDebug() << "QSqlDatabase::"
             << "Database closed";
    db.close();
}

void DataStorage::createTable() {
    QSqlQuery query;
    query.exec(SQLCREATE_FRIEND);
    query.exec(SQLCREATE_GP);
    query.exec(SQLCREATE_MSG);
    query.exec(SQLCREATE_FR);
    qDebug() << "create table OK" << endl;
}

int DataStorage::select(DataResult& res, std::string _sql, int resultNum) {
    QSqlQuery query;
    query.setForwardOnly(true);
    QString sql = QString::fromStdString(_sql);
    execute(query, sql);

    if (!query.isActive()) {
        return 1;
    } else {
        while (query.next()) {
            std::vector<QVariant> resRow;
            for (int i = 0; i < resultNum; i++) {
                resRow.push_back(query.value(i));
            }
            res.push_back(resRow);
        }
        return 0;
    }
}

int DataStorage::execute(QString sql) {
    QSqlQuery query;
    return execute(query, sql);
}

int DataStorage::execute(QSqlQuery& query, QString sql) {
    QSqlQuery query;
    bool status = query.exec(sql);

    if (status) {
        return true;
    } else {
        QSqlError err = query.lastError();
        qDebug() << "DataStorage::excute Error:" << err.databaseText() << "; " << err.driverText();
    }
}