#include <Wire.h>
#include <VL53L0X.h>

const int PRO_MINI_I2C_ADDR = 0x31;
const int TCA9548A_I2C_ADDR = 0x70;

VL53L0X tofs[5];
int distances_mm[5];
int channel_of_tof[5] = {2, 3, 4, 5, 6};


void requestEvent() {
  for(int i =0; i < 5; i++)
    send_float_i2c(distances_mm[i]); 
}

void send_float_i2c(float data){
  uint32_t same_binary = *(uint32_t*)&data;
  Wire.write((same_binary & 0xFF000000) >> 24);
  Wire.write((same_binary & 0xFF0000) >> 16);
  Wire.write((same_binary & 0xFF00) >> 8);
  Wire.write(same_binary & 0xFF);
}

void multiplexer_channel_select(int channel){
  Wire.beginTransmission(TCA9548A_I2C_ADDR);
  Wire.write(1 << channel);
  Wire.endTransmission();
}

void setup(){
  Serial.begin(9600);
  Wire.begin(PRO_MINI_I2C_ADDR);
  Wire.onRequest(requestEvent);
  TWBR = 12;

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  for(VL53L0X &tof : tofs){
    tof.init();
    tof.setTimeout(500);
    tof.startContinuous();
  }
}

void loop(){
  for(int i = 0; i < 5; i++)
    multiplexer_channel_select(channel_of_tof[i]);
    distances_mm[i] = tofs[i].readRangeContinuousMillimeters();
}
