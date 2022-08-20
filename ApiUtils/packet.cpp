/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\packet.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:52:10
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-21 01:28:18
 */
#include "packet.h"

Pak_Login::Pak_Login(uint32_t _id, char _pwd[])
    : ID(_id) {
    strcpy(this->PWD, _pwd);
    this->len = PACKET_SIZE(this);
    this->type = PACKET_TYPE::LOGIN;
};

Pak_Register::Pak_Register(uint32_t _id, char _pwd[], char _nickname[], uint8_t _gender, uint8_t _age, uint8_t _city, uint8_t _job)
    : ID(_id), gender(_gender), age(_age), city(_city), job(_job) {
    strcpy(this->PWD, _pwd);
    strcpy(this->nickname, _nickname);
    this->len = PACKET_SIZE(this);
    this->type = PACKET_TYPE::REGISTER;
};

Pak_Message::Pak_Message(uint32_t _userID, uint32_t _sessionID, uint64_t _time, uint8_t _msg_type, uint32_t _msg_len, QString _content)
    : userID(_userID), sessionID(_sessionID), time(_time), msg_type(_msg_type), msg_len(_msg_len) {
    this->content = (char*)malloc(sizeof(char) * _msg_len);
    strcpy(this->content, _content.toLocal8Bit().data());
    this->len = PACKET_SIZE(this) - sizeof(char*) + sizeof(char)*_msg_len;
    this->type = PACKET_TYPE::SEND_MESSAGE;
};

Pak_Message::~Pak_Message() {
    free(this->content);
};
