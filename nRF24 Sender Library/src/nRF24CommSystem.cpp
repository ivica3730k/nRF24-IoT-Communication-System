//
// Created by ivica on 01/06/19.
//

#include <Arduino.h>
#include <nRF24CommSystem.h>

nRF24CommSystem::nRF24CommSystem(RF24 &_device){
    nRF24 = &_device;
}

void nRF24CommSystem::setup(const uint64_t &_uplinkPipe,unsigned int &_channel){
    uplinkPipe = _uplinkPipe;
    channel = _channel;

    nRF24->setChannel(channel);
    nRF24->setDataRate(RF24_250KBPS);
    nRF24->setAutoAck(1);                     // Ensure autoACK is enabled
    nRF24->setRetries(2,15);                  // Optionally, increase the delay between retries & # of retries
    nRF24->setCRCLength(RF24_CRC_8);          // Use 8-bit CRC for performance
    nRF24->openWritingPipe(uplinkPipe);


}

payload nRF24CommSystem::makePayload(char& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 1;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload nRF24CommSystem::makePayload(char16_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 2;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload nRF24CommSystem::makePayload(char32_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 3;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload nRF24CommSystem::makePayload(int8_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 4;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload nRF24CommSystem::makePayload(int16_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 5;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload nRF24CommSystem::makePayload(int32_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 6;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
/*
payload nRF24CommSystem::makePayload(int64_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 7;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}*/
payload nRF24CommSystem::makePayload(uint8_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 8;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload nRF24CommSystem::makePayload(uint16_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 9;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload nRF24CommSystem::makePayload(uint32_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 10;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
/*
payload nRF24CommSystem::makePayload(uint64_t& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 11;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}*/

payload nRF24CommSystem::makePayload(float& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 12;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}
payload nRF24CommSystem::makePayload(double& data, uint64_t id)
{
    payload pload;
    pload.id = id;
    pload.datatype = 13;
    String cache = String(data);
    strcpy(pload.data, cache.c_str());
    return pload;
}