#define OFF 0
#define ON 1

void setDigitalPinState(const int pin, const int mode) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, mode);
}

void blinkLed(const int pin, const int interval) {
  setDigitalPinState(pin, ON);
  delay(interval);
  setDigitalPinState(pin, OFF);
  delay(interval);
}
