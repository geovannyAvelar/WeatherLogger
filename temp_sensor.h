#include <DHT.h>

#define DHT_PIN A1
#define DHT_TYPE DHT11

DHT sensor(A1, DHT11);

void start_temp_sensor() {
  sensor.begin();
  delay(2000);
}

WEATHER_DATA collectWeatherData() {
  WEATHER_DATA data;
  float temperature = sensor.readTemperature();
  float humidity = sensor.readHumidity();

  if (!(isnan(temperature) || isnan(humidity))) {
    data.temperature = temperature;
    data.relative_humidity = humidity;
    data.dew_point = calculateDewPoint(data);
  }

  return data;

}
