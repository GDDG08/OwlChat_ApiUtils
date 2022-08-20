/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\packet.cpp
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:52:10
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 17:26:05
 */
#include "packet.h"

Pak_Login::Pak_Login(uint32_t _guid, uint32_t _id, char _pwd[])
    : ID(_id) {
    strcpy(this->PWD, _pwd);
    this->GUID = _guid;
    this->len = PACKET_SIZE(this);
    this->type = PACKET_TYPE::LOGIN;
};

Pak_Register::Pak_Register(uint32_t _guid, uint32_t _id, char _pwd[], char _nickname[], uint8_t _gender, uint8_t _age, uint8_t _city, uint8_t _job)
    : ID(_id), gender(_gender), age(_age), city(_city), job(_job) {
    strcpy(this->PWD, _pwd);
    strcpy(this->nickname, _nickname);
    this->GUID = _guid;
    this->len = PACKET_SIZE(this);
    this->type = PACKET_TYPE::REGISTER;
};
