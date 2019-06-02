#include <Arduino.h>
#include <nRF24CommSystem.h>

nRF24CommSystem::nRF24CommSystem(RF24 &_device){
    nRF24 = &_device;
}

void nRF24CommSystem::setup(const uint32_t &_uplinkPipe,unsigned int &_channel){
    uplinkPipe = _uplinkPipe;
    channel = _channel;

    nRF24->setChannel(channel);
    nRF24->setDataRate(RF24_250KBPS);
    nRF24->setAutoAck(1);                     // Ensure autoACK is enabled
    nRF24->setRetries(2,15);                  // Optionally, increase the delay between retries & # of retries
    nRF24->setCRCLength(RF24_CRC_8);          // Use 8-bit CRC for performance
    nRF24->openWritingPipe(uplinkPipe);


}