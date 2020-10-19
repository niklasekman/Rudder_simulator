#include "lcd_render.h"
#include "wave_motion.h"

#include <LiquidCrystal.h>
// Setup the LCD - modify for your configuration
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long lastTime;
const long interval = 20; // 20ms refresh rate
int rudderPin = A0;

unsigned int frame = 0; // frame counter

void setup() {
  init_wave_motion();
  initShip(90);
}

void loop() {
  unsigned long timeNow = millis();
  if(timeNow-lastTime >= interval) {
    lastTime = timeNow;
    
    int rudderPos = readRudderPos(rudderPin);
    int heading = simulateShip(rudderPos);
    renderFrame(heading, frame);

    frame++;
  }
}
