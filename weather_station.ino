#include "weather_data.h"
#include "temp_sensor.h"
#include "server.h"
#include "utils.h"

#define DATA_COLLECT_INTERVAL 600000
#define LED 2

void setup() {
  Serial.begin(9600);
  start_temp_sensor();
  start_network();
}

void loop() {
  WEATHER_DATA data = collectWeatherData();
  saveWeatherData(data);
  blinkLed(LED, 500);
  delay(DATA_COLLECT_INTERVAL);
}

