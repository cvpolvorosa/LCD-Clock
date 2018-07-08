#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

DS3231  rtc(SDA, SCL);
LiquidCrystal_I2C lcd(0x27, 16, 2);

Time  t;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  rtc.begin();

  //rtc.setDOW(FRIDAY);
  //rtc.setTime(10, 49, 0);
  //rtc.setDate(14, 7, 2017);
}

void loop()
{
  lcd.clear();
  t = rtc.getTime();
  lcd.setCursor(0, 0);
  lcd.print(rtc.getMonthStr());
  lcd.print(" ");
  lcd.print(t.date, DEC);
  lcd.print(" ");
  lcd.print(t.year, DEC);
  //lcd.print(", ");

  // Print time
  //Serial.print(t.dow, DEC);
  lcd.setCursor(0, 1);
  lcd.print(t.hour, DEC);
  lcd.print(":");
  lcd.print(t.min, DEC);
  lcd.print(":");
  lcd.print(t.sec, DEC);
  delay (1000);
}

