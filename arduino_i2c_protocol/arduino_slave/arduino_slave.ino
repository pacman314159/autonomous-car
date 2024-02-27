#include <Wire.h>

const int PRO_MINI_I2C_ADDR = 0x31;

void send_float_i2c(float data){
  uint32_t same_binary = *(uint32_t*)&data;
  Wire.write((same_binary & 0xFF000000) >> 24);
  Wire.write((same_binary & 0xFF0000) >> 16);
  Wire.write((same_binary & 0xFF00) >> 8);
  Wire.write(same_binary & 0xFF);
}

float pi = 3.141592653;
bool pinState = true;

void setup() {
  Wire.begin(PRO_MINI_I2C_ADDR);
  Wire.onRequest(requestEvent);
  TWBR = 12;

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
}

void requestEvent() {
  digitalWrite(13, pinState);
  pinState = !pinState;
  send_float_i2c(pi);
}
