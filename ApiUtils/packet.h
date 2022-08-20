/*
 * @Project      :
 * @FilePath     : \IM-Network\ApiUtils\packet.h
 * @Descripttion :
 * @Author       : GDDG08
 * @Date         : 2022-08-20 10:52:10
 * @LastEditors  : GDDG08
 * @LastEditTime : 2022-08-20 18:09:14
 */
#ifndef PACKAGE_H
#define PACKAGE_H

#define PACKET_SIZE(x) sizeof(*(x)) - sizeof(Packet)

#include <string.h>
#include <stdint.h>
#include "socket_utils.h"

#pragma pack(1)

enum PACKET_TYPE {
    LOGIN = 1u,
    REGISTER
};
class Packet {
   public:
    uint8_t PACKET_HEADR_0 = SOCKET_PACKET_HEADR_0;
    uint8_t PACKET_HEADR_1 = SOCKET_PACKET_HEADR_1;
    uint8_t type = 0;
    uint16_t len = 0;
    uint32_t GUID = 0;
};

class PacketRTN : public Packet {
   public:
    uint8_t msg;
};

class Pak_Login : public Packet {
   private:
    uint32_t ID;
    char PWD[17];

   public:
    Pak_Login(uint32_t _guid, uint32_t _id, char _pwd[]);
};

class Pak_Register : public Packet {
   private:
    uint32_t ID;
    char PWD[17];
    char nickname[128];

    uint8_t gender;
    uint8_t age;

    uint8_t city;
    uint8_t job;

   public:
    Pak_Register(uint32_t _guid, uint32_t _id, char _pwd[], char _nickname[], uint8_t _gender, uint8_t _age, uint8_t _city, uint8_t _job);
};

class Pak_LoginRTN : public PacketRTN {
   public:
    char token[17];
};

#endif  // PACKAGE_H
