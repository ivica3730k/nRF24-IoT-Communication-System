#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <payloads.h>
#include <nRF24CommSystem.h>


RF24 radio(7,8);   
nRF24CommSystem comm(radio);
const uint32_t uplink_pipe = 0xABCDABCD;
unsigned int channel = 100;
void setup() {

  Serial.begin(115200);

  radio.begin();                           // Setup and configure rf radio
  radio.setPALevel(RF24_PA_MAX);           // If you want to save power use "RF24_PA_MIN" but keep in mind that reduces the module's range
  comm.setup(uplink_pipe,channel);
  radio.powerUp();                         //Power up the radio

}

void loop() {
  payload pload;
  uint32_t numberToSend = INT32_MAX;
  pload = makePayload(numberToSend,0xA22DABEC);

  if (!radio.write( &pload, sizeof(pload) )){
       Serial.println(F("failed"));
     }
  
  delay(1000);
}