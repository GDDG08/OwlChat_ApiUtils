/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_utils.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-23 18:20:00
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-24 02:51:34
 */
#include "data_utils.h"

DataUtils::DataUtils(QObject* parent)
    : QObject(parent) {
    dataStorage = new DataStorage(this);
}

// init database
int DataUtils::onLogin(uint32_t userID) {
}

int DataUtils::addMessage(D_Message msg) {
}

int DataUtils::getMessages(uint32_t sessionID, uint8_t sessionType, QList<D_Message>& list) {
}

int DataUtils::getRecentMessageList(QList<D_RecentMsgListItem>& list) {
}

// FRIEND
int DataUtils::addFriendRequest(uint32_t fromID, uint32_t toID, QString verify_msg) {
}
int DataUtils::changeFriendRequestStatus(uint32_t fromID, uint32_t toID, uint8_t status) {
}
int DataUtils::addFriend(uint32_t userID) {
    // 可能已经有了但还不是friend
}
int DataUtils::deleteFriend(uint32_t userID) {
    // 仅仅取消标识
}

// update 的时候可能已经有了
int DataUtils::updateUserInfo(D_UserBasicInfo info) {
}

int DataUtils::getUserInfo(uint32_t userID, D_UserBasicInfo& info) {
}

int DataUtils::updateUserDetail(D_UserDetailInfo info) {
}

int DataUtils::getUserDetail(uint32_t userID, D_UserDetailInfo& info) {
}

int DataUtils::updateFriendList(QList<D_UserBasicInfo> list) {
}

int DataUtils::getFriendList(QList<D_UserBasicInfo>& list) {
}

// GROUP
int DataUtils::updateGroupList(QList<D_GroupInfo> list) {
}

int DataUtils::getGroupList(QList<D_GroupInfo>& list) {
}

int DataUtils::updateGroupInfo(D_GroupInfo info) {
}

int DataUtils::getGroupInfo(uint32_t groupID, D_GroupInfo& info) {
}

int DataUtils::addGroup(uint32_t groupID) {
}

int DataUtils::deleteGroup(uint32_t groupID) {
}