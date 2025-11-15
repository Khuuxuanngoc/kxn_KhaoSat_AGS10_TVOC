/*
  15/11/2025:
    Test đọc được giá trị, dạng ĐỊNH TÍNH, test trên UNO. 2 cb cho ra 2 giá trị, S1: ~390 (hàn dây), S2:~1300 (hàn rào).
        Arduino Library sử dụng: https://github.com/Khuuxuanngoc/AGS10_sensor/archive/refs/tags/v1.0.0.zip
        Arduino Library gốc: gina-seth/AGS10_sensor: AGS10 sensor Arduino Library

    Độ nhạy rất cao, cẩn trọng khi test, nếu để vật test có nồng độ quá cao sẽ làm hỏng cảm biến
        Giá trị tại các vị trí:
            - Quốc: >2900
            - Online: 256
            - Sân thượng: 270
            - Hshop: 1100
*/

#include <AGS10.h>
#include <Wire.h>
#include <Arduino.h>
// Add the library
#include <MKL_LiquidCrystal_I2C.h>

// declare sensor 
AGS10 sensor = AGS10();

// LCD config
MKL_LiquidCrystal_I2C lcd(0x27, 16, 2);


// declare data variable
int tvoc;

void lcdInit()
{
  // Initialize LCD
  lcd.init();
  lcd.backlight();
}

void setup() {
  // begin a serial monitor
  Serial.begin(115200);

  lcdInit();

  //  initialize sensor 
  sensor.begin();


}

void loop() {
  //  read TVOC sensor data every 1.6 seconds, according to datasheet max speed is 1.5 seconds/reading
  tvoc = sensor.readTVOC();
  Serial.println(tvoc);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(tvoc);

  delay(1600);

}
