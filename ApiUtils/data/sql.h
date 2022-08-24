#define SQLCREATE_FRIEND "CREATE TABLE user( \
    userid varchar(15) PRIMARY KEY, \
    nickname varchar(64) NOT NULL, \
    gender INTEGER CHECK(gender IN (0, 1, 2))  DEFAULT 0, \
    age INTEGER, \
    city int, \
    job int, \
    avatar varchar(256) DEFAULT '', \
    isfriend BOOLEAN CHECK(isfriend IN (0, 1))  DEFAULT 0, \
    signature TEXT DEFAULT '', \
    status int CHECK(status IN (0, 1, 2, 3)) \
);"

#define SQLCREATE_GP "create table gp( \
    groupid int PRIMARY KEY, \
    groupname varchar(64) NOT NULL, \
    createuser varchar(15) NOT NULL, \
    avatar varchar(256) DEFAULT '', \
    board varchar(1024) DEFAULT '', \
    FOREIGN KEY(createuser) REFERENCES user(userid) ON DELETE CASCADE \
);"

#define SQLCREATE_MSG "create table msg( \
    msgid INTEGER PRIMARY KEY AUTOINCREMENT, \
    fromuserid varchar(15) NOT NULL, \
    sessionid varchar(15) NOT NULL, \
    sessiontype int CHECK(sessiontype in (0, 1)), \
    msgtype int CHECK (msgtype in (0, 1, 2)), \
    tm TimeStamp DEFAULT (DATETIME('now', 'localtime')), \
    content TEXT DEFAULT '', \
    FOREIGN key (fromuserid) REFERENCES friend (userid) ON DELETE CASCADE, \
    FOREIGN KEY (touserid) REFERENCES friend(userid) ON DELETE CASCADE \
);"

#define SQLCREATE_FR "create table fr( \
    fromuserid varchar(15) NOT NULL, \
    touserid varchar(15) NOT NULL, \
    content text DEFAULT '', \
    status int CHECK(status in (1, 2, 3, 4)), \
    tm TimeStamp DEFAULT (DATETIME('now', 'localtime')), \
    FOREIGN key (fromuserid) REFERENCES friend (userid) ON DELETE CASCADE, \
    FOREIGN KEY (touserid) REFERENCES friend(userid) ON DELETE CASCADE \
);"
