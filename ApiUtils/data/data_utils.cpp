/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\data_utils.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-23 18:20:00
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-24 18:18:35
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
    QSqlQuery query;

    QString sql = QString(
                      "INSERT INTO msg(fromuserid, sessionid, sessiontype, msgtype, content)"
                      "VALUES('%1', '%2', %3, %4, %5)")
                      .arg(QString(msg.fromID), QString(msg.sessionType == 0 ? msg.fromID : msg.sessionID), QString(msg.sessionType), QString(msg.msg_type), QString(msg.content));
    query.exec(sql);
    return 0;
}

int DataUtils::getMessages(uint32_t sessionID, uint8_t sessionType, QList<D_Message>& list) {
    QSqlQuery query;
    QString sql = QString("SELECT * FROM msg WHERE sessionid = '%1' and sessionType = %2").arg(QString(sessionID), QString(sessionType));
    query.exec(sql);
    while (query.next())
        ;
    return 0;
}

int DataUtils::getRecentMessageList(QList<D_RecentMsgListItem>& list) {
    QSqlQuery query;
    QString sql = QString("SELECT sessionid, sessiontype from msg GROUP BY sessionid");
    while (query.next()) {
        QString sessionid = query.value(0).toString();
        int sessiontype = query.value(1).toInt();
        QSqlQuery query2;
        QString sql2 = sessiontype == 0 ? QString("select avatar, nickname, lastreadtime, lastreadmsg from user where userid = '%1'").arg(QString(sessionid)) : QString("select avtar, grouponame, lastreadtime, lastreadmsg from gp where groupid = %1").arg(QString(sessionid));
        query2.exec();

        QString avatar, nickname, lastreadtime, lastreadmsg;
        if (query2.next()) {
            avatar = query2.value(0).toString();
            nickname = query2.value(1).toString();
            lastreadtime = query2.value(2).toString();
            lastreadmsg = query2.value(3).toString();
        }

        QSqlQuery query3;
        QString sql3 = QString("select count(*) from msg where lastreadtime > '%1'").arg(lastreadtime);
        query3.exec();
        int noreadnum = 0;
        if (query3.next()) {
            noreadnum = query3.value(0).toInt();
        }

        D_RecentMsgListItem drml;
        drml.sessionID = sessionid.toInt();
        drml.sessionType = sessiontype;
        drml.unread_num = noreadnum;
        drml.sessionName = nickname;
        drml.last_msg = lastreadmsg;
        list.append(drml);
    }
    return 1;
}

// FRIEND
int DataUtils::addFriendRequest(uint32_t fromID, uint32_t toID, QString verify_msg) {
}
int DataUtils::changeFriendRequestStatus(uint32_t fromID, uint32_t toID, uint8_t status) {
}
int DataUtils::addFriend(uint32_t userID) {
    // �?能已经有了但还不是friend
}
int DataUtils::deleteFriend(uint32_t userID) {
    // 仅仅取消标识
}

// update 的时候可能已经有�?
int DataUtils::updateUserInfo(D_UserBasicInfo info) {
}

int DataUtils::getUserInfo(uint32_t userID, D_UserBasicInfo& info) {
}

int DataUtils::updateUserDetail(D_UserDetailInfo info) {
}

int DataUtils::getUserDetail(uint32_t userID, D_UserDetailInfo& info) {
    DataResult res;
    dataStorage->select(res, "SELECT * FROM user", 10);

    DataRow row = res[0];
    info.userID = row[0].toUInt();
    info.nickName = row[1].toString();
    info.gender = row[2].toUInt();
    info.age = row[3].toUInt();
    info.city = row[4].toUInt();
    info.job = row[5].toUInt();
    info.avatarID = row[6].toUInt();
    info.isFriend = row[7].toUInt();
    info.signature = row[8].toString();
    info.userStatus = row[9].toUInt();
}

int DataUtils::updateFriendList(QList<D_UserBasicInfo> list) {
}

int DataUtils::getFriendList(QList<D_UserBasicInfo>& list) {
}

// GROUP
int DataUtils::updateGroupList(QList<D_GroupInfo> list) {
}

int DataUtils::getGroupList(QList<D_GroupInfo>& list) {
    DataResult res;
    dataStorage->select(res, "SELECT * FROM gp", 5);
    for (int i = 0; i < res.size(); i++) {
        DataRow row;
        D_GroupInfo info;
        for (int j = 0; j < row.size(); j++) {
            info.groupID = row[0].toUInt();
            info.groupName = row[1].toString();
            info.adminUser = row[2].toUInt();
            info.avatarID = row[3].toUInt();
            info.board = row[4].toString();
        }
        list.push_back(info);
    }
}

int DataUtils::updateGroupInfo(D_GroupInfo info) {
}

int DataUtils::getGroupInfo(uint32_t groupID, D_GroupInfo& info) {
    QSqlQuery query;
    QString sql = QString("SELECT * FROM gp WHERE groupid = '%1'").arg(QString(groupID));
    query.exec(sql);
}

int DataUtils::addGroup(uint32_t groupID) {
    QSqlQuery query;
    QString sql = QString("INSERT INTO gp (groupid) VALUES('%1')")
                      .arg(QString(groupID));
    query.exec(sql);
}

int DataUtils::deleteGroup(uint32_t groupID) {
    QSqlQuery query;
    QString sql = QString("DELETE FROM gp WHERE groupid = '%1'")
                      .arg(QString(groupID));
    query.exec(sql);
    query.value(0);
}
