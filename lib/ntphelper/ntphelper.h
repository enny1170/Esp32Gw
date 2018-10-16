
#ifndef NTPHELPER_H
    #define NTPHELPER_H
#endif

#define NTP_SERVER "pool.ntp.org"
#define TZ_INFO "WEST-1DWEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00" // Western European Time
#include <Arduino.h>
//Variable to store in ESP32 RTC RAM
RTC_DATA_ATTR int counter=0;

void syncRTC()
{
    struct tm local;
    configTzTime(TZ_INFO,NTP_SERVER);
    getLocalTime(&local,10000);
    Serial.println(&local,"Date: %d.%m.%y Time: %H:%M:%S");
}

char getDateTime()
{
    struct tm local;
    char output[100];
    getLocalTime(&local);
    strftime(output,sizeof(output),"%d.%m.%y %H:%M:%S",&local);
    return *output;
}