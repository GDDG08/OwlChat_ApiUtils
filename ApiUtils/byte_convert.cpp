/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\byte_convert.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 15:48:31
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 16:02:02
 */
#include "byte_convert.h"

QString ByteConvert::byte2HexString(QByteArray byte) {
    QString strTmp;
    for (int n = 0; n < sizeof(byte); n++)
        strTmp += QString().sprintf("%x ", (unsigned char)byte[n]);
    return strTmp;
}

QString ByteConvert::byte2HexString(char byte[]) {
    QString strTmp;
    for (int n = 0; n < sizeof(byte); n++)
        strTmp += QString().sprintf("%x ", (unsigned char)byte[n]);
    return strTmp;
}
