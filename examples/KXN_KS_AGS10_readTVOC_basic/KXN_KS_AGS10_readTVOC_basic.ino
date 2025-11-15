/*
  15/11/2025:
    Test đọc được giá trị, dạng ĐỊNH TÍNH. 2 cb cho ra 2 giá trị, S1: ~390 (hàn dây), S2:~1300 (hàn rào).
      Arduino Library sử dụng: https://github.com/Khuuxuanngoc/AGS10_sensor/archive/refs/tags/v1.0.0.zip
      Arduino Library gốc: gina-seth/AGS10_sensor: AGS10 sensor Arduino Library

    Độ nhạy rất cao, cẩn trọng khi test, nếu để vật test có nồng độ quá cao sẽ làm hỏng cảm biến
*/

#include <AGS10.h>
#include <Wire.h>
#include <Arduino.h>

// declare sensor 
AGS10 sensor = AGS10();

// declare data variable
int tvoc;

void setup() {
  // begin a serial monitor
  Serial.begin(115200);

  //  initialize sensor 
  sensor.begin();


}

void loop() {
  //  read TVOC sensor data every 1.6 seconds, according to datasheet max speed is 1.5 seconds/reading
  tvoc = sensor.readTVOC();
  Serial.println(tvoc);
  delay(1600);

}
