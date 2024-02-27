#include <Wire.h>
#include <VL53L0X.h>

VL53L0X tof;

void setup(){
  Serial.begin(9600);
  Wire.begin();

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  tof.init();
  tof.setTimeout(500);
  tof.startContinuous();
}

void loop(){
  int distance_mm = tof.readRangeContinuousMillimeters();
  Serial.println(distance_mm);
  if (tof.timeoutOccurred()) Serial.println("TIMEOUT");
}
