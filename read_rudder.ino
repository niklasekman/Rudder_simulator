int readRudderPos(int pin) {
  int measurement = 0;
  for(int i = 0; i < 10; i++) {
    measurement += analogRead(pin);
  }
  measurement = measurement / 10;

  measurement = (measurement * 90/1024) - 45;
  
  return measurement;
}
