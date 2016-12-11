#include <SD.h>

//The CS pin can be different, on ethernet shiled and arduino uno is 4. If this don't work, try 10
#define SD_CS_PIN 4

void start_sd_card() {
  if(SD.begin(SD_CS_PIN)) {
    Serial.write("SD card intialized\n");
  } else {
    Serial.write("SD CARD ERROR");
  }
}

void sd_log_write(String filename, String line) {
  File file = SD.open(filename, FILE_WRITE);
  file.println(line);
  file.close();
}

