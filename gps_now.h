#ifndef GPS_NOW_H
#define GPS_NOW_H
#include <Arduino.h>
#include <TinyGPS.h>
#include <SoftwareSerial.h>

  typedef struct date_time {
  uint8_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
};

typedef struct coordinate{
  float latitude;
  float longitude;
  unsigned long age;
  uint16_t altitude;
};

typedef struct gps_now{
  uint8_t sat;
  date_time dateTime;
  coordinate coord;
  int16_t speed;
  char course;
};
void gps_now_print(uint8_t RX, uint8_t TX,uint32_t baudRate, TinyGPS gps,uint32_t ms);
gps_now gps_now_get(uint8_t RX, uint8_t TX,uint32_t baudRate, TinyGPS gps,uint32_t ms);
void gps_now_print(gps_now gpsData, uint32_t baudRate);
#endif