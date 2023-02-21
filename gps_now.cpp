#include <gps_now.h>
#include <Arduino.h>
#include <TinyGPS.h>
#include <SoftwareSerial.h>
void gps_now_print(uint8_t RX, uint8_t TX,uint32_t baudRate, TinyGPS gps,uint32_t ms){
  SoftwareSerial ss(RX,TX);
  ss.begin(baudRate);
  unsigned long start = millis();
  do {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
  Serial.println("--------------------------------");
   Serial.print("sat: "); Serial.println(gps.satellites());
   float flat, flon;
  unsigned long age;
  gps.f_get_position(&flat, &flon, &age);
  Serial.print("lat: "); Serial.println(flat, 6);
  Serial.print("lon: "); Serial.println(flon, 6);
  Serial.print("alt: "); Serial.println(gps.f_altitude());
  
  Serial.print("crs: "); Serial.println(gps.f_course());
  int year;
  byte month, day, hour, minute, second;
  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second );
  Serial.print("year: "); Serial.println(year);
  Serial.print("month: "); Serial.println(month);
  Serial.print("day: "); Serial.println(day);
  hour=(hour>21) ? hour - 21 : hour + 3;                                    //for gmt+3
  Serial.print("hour: "); Serial.println(hour);
  Serial.print("minute: "); Serial.println(minute);
  Serial.print("second: "); Serial.println(second);
}
gps_now gps_now_get(uint8_t RX, uint8_t TX,uint32_t baudRate, TinyGPS gps,uint32_t ms){
  SoftwareSerial ss(RX,TX);
  ss.begin(baudRate);
  unsigned long start = millis();
  do {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
  gps_now gpsData;
  gpsData.sat=gps.satellites();
  float flat, flon;
  unsigned long age;
  gps.f_get_position(&flat, &flon, &age);
  gpsData.coord.latitude=flat;
  gpsData.coord.longitude=flon;
  gpsData.coord.age=age;
  gpsData.coord.altitude = gps.f_altitude();
  gpsData.course = gps.f_course();
  gpsData.speed = gps.f_speed_kmph();
  int year;
  byte month, day, hour, minute, second;
  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second );
  gpsData.dateTime.year=year;
  gpsData.dateTime.month=month;
  gpsData.dateTime.day=day;
  gpsData.dateTime.hour=(hour>21) ? hour - 18 : hour + 3;                //for gmt+3
  gpsData.dateTime.minute=minute;
  gpsData.dateTime.second=second;

  return gpsData;
}