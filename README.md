# WeatherLogger [![MIT Licence](https://badges.frapsoft.com/os/mit/mit.svg?v=103)](https://opensource.org/licenses/mit-license.php) [![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.svg?v=102)](https://github.com/ellerbrock/open-source-badge/)  

Weather station project with Arduino

## Summary
* 1 Pre-requisites
  * 1.1 Hardware
  * 1.2 Software
* 2 Pinout
  * 2.2 DHT11
  * 2.3 LED (optional)
* 3 License

### 1 Pre-requisites
#### 1.1 Hardware
- Arduino UNO
- DHT11 temperature and humidity sensor
- Ethernet shield
- LED (Optional)

#### 1.2 Software
- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)
- [ArduinoHttpClient](https://github.com/arduino-libraries/ArduinoHttpClient)

### 2 Pinout
#### 2.2 DHT11
![DHT11 pinout](https://camo.githubusercontent.com/59d77436cec1feebad798c7b1cf83d323143cc0e/687474703a2f2f6c6561726e696e672e67726f626f74726f6e6963732e636f6d2f696d616765732f5475746f7269616c732f44485431315f50696e732e706e67)
Credits: [mkschreder](https://github.com/mkschreder/example-dht-11)

![DHT11 pinout](http://blog.filipeflop.com/wp-content/uploads/2013/08/Circuito_DHT111.jpg)
Credits: [FilipeFlop](http://blog.filipeflop.com/sensores/monitorando-temperatura-e-umidade-com-o-sensor-dht11.html) and [Arduino&Cia](http://www.arduinoecia.com.br/)

#### 2.3 LED (optional)
The digital pin #2 is the LED pin by default, but you can change it in **weather_station.ino** file, line **#define LED 2**.

### 3 License
This project is under The MIT License (MIT) terms.
