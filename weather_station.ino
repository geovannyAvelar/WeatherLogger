#include "weather_data.h"
#include "temp_sensor.h"
#include "SD_logger.h"
#include "utils.h"

#define DATA_COLLECT_INTERVAL 300000
#define LED 2

void setup() {
  Serial.begin(9600);
  start_temp_sensor();
  start_sd_card();
}

void loop() {
  WEATHER_DATA data = collectWeatherData();
  
  String jsonData = weatherDataToJson(data);
  Serial.print(jsonData);

  sd_log_write("weather_log.csv", weatherDataToCsv(data));
    
  blinkLed(LED, 500);
  delay(DATA_COLLECT_INTERVAL);
}

