/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_struct.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-23 20:25:52
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-24 18:16:49
 */
#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#endif  // DATA_STRUCT_H

#include <stdint.h>
#include <QString>

struct D_UserBasicInfo {
    uint32_t userID;
    uint32_t avatarID;
    QString nickName;
    uint8_t userStatus;
};

struct D_UserDetailInfo {
    uint32_t userID;
    QString nickName;
    uint8_t gender;
    uint8_t age;
    uint8_t city;
    uint8_t job;
    uint32_t avatarID;
    uint8_t isFriend;
    QString signature;
    uint8_t userStatus;
};

struct D_Message {
    uint32_t fromID;
    uint32_t sessionID;
    uint8_t sessionType;
    uint64_t time;
    uint8_t msg_type;
    QString content;
};

struct D_RecentMsgListItem {
    QString sessionName;
    uint32_t sessionID;
    uint8_t sessionType;
    QString last_msg;
    int unread_num;
};

struct D_GroupInfo {
    uint32_t groupID;
    QString groupName;
    uint32_t adminUser;
    uint32_t avatarID;
    QString board;
};
