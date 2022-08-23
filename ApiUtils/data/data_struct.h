/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_struct.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-23 20:25:52
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-23 22:31:30
 */
#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#endif  // DATA_STRUCT_H

#include <stdint.h>

struct UserBasicInfo {
    uint32_t userID;
    uint32_t avatarID;
    char nickName[128];
};

struct MsgListItem {
    UserBasicInfo userInfo;
    
};