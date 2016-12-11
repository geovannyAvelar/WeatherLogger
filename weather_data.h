struct WEATHER_DATA {
  float temperature;
  float relative_humidity;
  float dew_point;
  float pressure;
};

float calculateDewPoint(WEATHER_DATA data) {
  float temp = data.temperature;
  float humidity = data.relative_humidity;
  float dew_point = (temp - (14.55 + 0.114 * temp) * 
                            (1 - (0.01 * humidity)) - 
                            pow(((2.5 + 0.007 * temp) * 
                            (1 - (0.01 * humidity))),3) 
                            - (15.9 + 0.117 * temp) * 
                            pow((1 - (0.01 * humidity)), 14));
  data.dew_point = dew_point;
  return dew_point;
}

String weatherDataToJson(const WEATHER_DATA data) {
 String jsonString = "";
 jsonString.concat("{\"temperature\": ");
 jsonString.concat(data.temperature);
 jsonString.concat(", \"relativeHumidity\": ");
 jsonString.concat(data.relative_humidity);
 jsonString.concat(", \"dewPoint\": ");
 jsonString.concat(data.dew_point);
 jsonString.concat(", \"temperatureUnit\": ");
 jsonString.concat("\"CELSIUS\"");
 jsonString.concat("}\n");
 return jsonString;
}

String weatherDataToCsv(const WEATHER_DATA data) {
  String csvLine = "";
  csvLine.concat(data.temperature);
  csvLine.concat(",");
  csvLine.concat(data.relative_humidity);
  csvLine.concat(",");
  csvLine.concat(data.dew_point);
  csvLine.concat(",CELSIUS");
  return csvLine;
}

