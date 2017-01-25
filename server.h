#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoHttpClient.h>

#define SERVER_IP "10.0.0.100"
#define SERVER_PORT 8080

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //MAC address DE:AD:BE:EF:FE:ED

EthernetClient ethernetClient;
HttpClient client = HttpClient(ethernetClient, SERVER_IP, SERVER_PORT);

void start_network() {
  if(Ethernet.begin(mac) == 0) {
    Serial.write("Failed to obtain IP via DHCP");
  } else {
    Serial.write("Network started");
    Serial.write(Ethernet.localIP());
  }
}

void saveWeatherData(WEATHER_DATA data) {
  String jsonData = weatherDataToJson(data);
  Serial.println("Data has been collected");
  Serial.println(jsonData);
  Serial.println("Saving data...");

  client.post("/weather", "application/json", jsonData);

  int status = client.responseStatusCode();

  if(status == 200) {
      Serial.println("Data has been saved");
  } else {
    Serial.write("Error ");
    Serial.println(status);
  }

}

