#include <Arduino.h>
#include <nRF24CommSystem.h>
#include <RF24.h>

RF24 module(7,9);
nRF24CommSystem comm(module);

void setup() {
  module.begin();
  comm.setup(0xA3ACADEA,110);
}

void loop() {
  // put your main code here, to run repeatedly:
}