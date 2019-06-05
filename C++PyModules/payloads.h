
//
// Created by ivica on 01/06/19.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef COMMTESTS_PAYLOADS_H
#define COMMTESTS_PAYLOADS_H

#define is_char 1
#define is_char16_t 2
#define is_char32_t 3
#define is_int8_t 4
#define is_int16_t 5
#define is_int32_t 6
#define is_int64_t 7
#define is_uint8_t 8
#define is_uint16_t 9
#define is_uint32_t 10
#define is_uint64_t 11
#define is_float 12
#define is_double 13
#define is_long_double 14

struct payload {
    uint64_t id;
    short datatype;
    /*pload dataytpe varies from data that we want to send
     * 0 for raw data
     * 1 for char
     * 2 for char16_t
     * 3 for char32_t
     * 4 for int8_t
     * 5 for int16_t
     * 6 for int32_t
     * 7 for int64_t
     * 8 for uint8_t
     * 9 for uint16_t
     * 10 for uint32_t
     * 11 for uint64_t
     * 12 for float
     * 13 for double
     * 14 for long double
     */
    char data[22];
};

payload makePayload(char& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 1;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(char16_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 2;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(char32_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 3;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(int8_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 4;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(int16_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 5;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(int32_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 6;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(int64_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 7;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(uint8_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 8;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(uint16_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 9;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(uint32_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 10;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(uint64_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 11;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(float& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 12;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(double& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 13;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload makePayload(long double& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 14;
    std::string cache = std::to_string(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}

short ploadType(payload& pload)
{
    return pload.datatype;
}

char castTo_char(payload& pload)
{
    char rec = pload.data[0];
    return rec;
}

char16_t castTo_char16_t(payload& pload)
{
    char rec = pload.data[0];
    return rec;
}

char32_t castTo_char32_t(payload& pload)
{
    char rec = pload.data[0];
    return rec;
}

int8_t castTo_int8_t(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stoi(buff);
}
uint8_t castTo_uint8_t(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stoul(buff);
}

int16_t castTo_int16_t(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stol(buff);
}
uint16_t castTo_uint16_t(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stoul(buff);
}

int32_t castTo_int32_t(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stoll(buff);
}

uint32_t castTo_uint32_t(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stoull(buff);
}

int64_t castTo_int64_t(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stoll(buff);
}
uint64_t castTo_uint64_t(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stoull(buff);
}

float castTo_float(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stof(buff);
}

double castTo_double(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stod(buff);
}

long double castTo_long_double(payload& pload)
{
    string buff;
    unsigned int i = 0;
    while(pload.data[i] != '\0'){
        buff += pload.data[i];
        i++;
    }
    return std::stold(buff);
}




#endif //COMMTESTS_PAYLOADS_H

