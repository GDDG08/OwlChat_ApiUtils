/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\byte_convert.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 15:48:12
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 18:44:45
 */
#ifndef BYTE_CONVERT_H
#define BYTE_CONVERT_H

#include <QByteArray>
#include <QString>

class ByteConvert {
   public:
    static QString byte2HexString(QByteArray);
    static QString byte2HexString(char*, int);
};

#endif  // BYTE_CONVERT_H