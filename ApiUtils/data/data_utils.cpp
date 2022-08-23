/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_utils.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-23 18:20:00
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-23 19:43:42
 */
#include "data_utils.h"

DataUtils::DataUtils(QObject* parent)
    : QObject(parent) {
    dataStorage = new DataStorage(this);
}

//DataUtils::addMessage(){

//}

