
//
// Created by ivica on 01/06/19.
//
#include <iostream>
#include <string.h>
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
    uint32_t id;
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
    char data[26];
};

payload makePayload(char& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 1;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(char16_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 2;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(char32_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 3;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(int8_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 4;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(int16_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 5;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(int32_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 6;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(int64_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 7;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(uint8_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 8;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(uint16_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 9;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(uint32_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 10;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(uint64_t& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 11;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(float& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 12;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(double& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 13;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}
payload makePayload(long double& data, uint32_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 14;
    memcpy(pload.data, &data, sizeof(data));
    return pload;
}

short ploadType(payload& pload)
{
    return pload.datatype;
}

char castTo_char(payload& pload)
{
    char rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

char16_t castTo_char16_t(payload& pload)
{
    char16_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

char32_t castTo_char32_t(payload& pload)
{
    char32_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

int8_t castTo_int8_t(payload& pload)
{
    int8_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}
uint8_t castTo_uint8_t(payload& pload)
{
    uint8_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

int16_t castTo_int16_t(payload& pload)
{
    int16_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}
uint16_t castTo_uint16_t(payload& pload)
{
    uint16_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

int32_t castTo_int32_t(payload& pload)
{
    int32_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

uint32_t castTo_uint32_t(payload& pload)
{
    uint32_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

int64_t castTo_int64_t(payload& pload)
{
    int64_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}
uint64_t castTo_uint64_t(payload& pload)
{
    uint64_t rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

float castTo_float(payload& pload)
{
    float rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

double castTo_double(payload& pload)
{
    double rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

long double castTo_long_double(payload& pload)
{
    long double rec;
    memcpy(&rec, pload.data, sizeof(rec));
    return rec;
}

std::string payloadDataToString(char data[26]){
    std::string a;
    for(int i = 0; i<sizeof(data)/sizeof(data[0]);i++){
        a+= data[i];
    }
    return a;
}



#endif //COMMTESTS_PAYLOADS_H

