/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\data\sql.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-24 15:22:36
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-24 21:39:26
 */
#define SQLCREATE_FRIEND \
    "CREATE TABLE user(\
    userid varchar(15) PRIMARY KEY,\
    nickname varchar(64) DEFAULT '',\
    gender INTEGER CHECK(gender IN (0, 1, 2))  DEFAULT 0,\
    age INTEGER default 0,\
    city int default 0,\
    job int default 0,\
    avatar int DEFAULT 0,\
    isfriend BOOLEAN CHECK(isfriend IN (0, 1))  DEFAULT 0,\
    signature TEXT DEFAULT '',\
    status int CHECK(status IN (0, 1, 2, 3)) DEFAULT 0,\
    lastreadtime TimeStamp DEFAULT (DATETIME('now', 'localtime')),\
    lastreadmsg text default ''\
);"

#define SQLCREATE_GP \
    "create table gp( \
    groupid int PRIMARY KEY,\
    groupname varchar(64) DEFAULT '',\
    createuser varchar(15) DEFAULT '0',\
    avatar int DEFAULT 0,\
    board varchar(1024) DEFAULT '',\
    lastreadtime TimeStamp DEFAULT(DATETIME('now', 'localtime')),\
    lastreadmsg text default ''\
);"

#define SQLCREATE_MSG \
    "create table msg( \
    id INTEGER PRIMARY KEY AUTOINCREMENT, \
    msgid INTEGER, \
    fromuserid varchar(15) NOT NULL, \
    sessionid varchar(15) NOT NULL, \
    sessiontype int CHECK(sessiontype in (0, 1)), \
    msgtype int CHECK (msgtype in (0, 1, 2)), \
    tm TimeStamp DEFAULT (DATETIME('now', 'localtime')), \
    content TEXT DEFAULT '', \
    guid INTEGER DEFAULT -1 \
);"

#define SQLCREATE_FR \
"create table fr( \
    fromuserid varchar(15) NOT NULL, \
    touserid varchar(15) NOT NULL, \
    content text DEFAULT '', \
    status int CHECK(status in (1, 2, 3, 4)) default 1, \
    tm TimeStamp DEFAULT (DATETIME('now', 'localtime')) \
);"

#define SQLCREATE_TRIGGER_MSG \
    "create trigger last_msg_user  \
        AFTER INSERT ON msg \
            FOR EACH ROW \
                WHEN new.sessiontype == 0  \
        BEGIN \
            update user set lastreadmsg = new.content where userid = new.sessionid \
        END;"

#define SQLCREATE_TRIGGER_GROUP \
    "create trigger last_msg_group  \
        AFTER INSERT ON msg \
            FOR EACH ROW \
                WHEN new.sessiontype == 1  \
        begin \
            update gp set lastreadmsg = new.content where groupid = cast(new.sessionid as int); \
        end;"
