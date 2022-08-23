/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_utils.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-23 18:20:00
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-23 19:43:12
 */
#ifndef DATA_UTILS_H
#define DATA_UTILS_H

#include <QObject>
#include <ApiUtils/data/data_storage.h>

class DataUtils : public QObject {
    Q_OBJECT
   public:
    explicit DataUtils(QObject* parent = 0);

   private:
    DataStorage* dataStorage;

   signals:

   public slots:
};

#endif  // DATA_UTILS_H