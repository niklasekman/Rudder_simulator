#include "num5x7.h"
#include "lcd_smooth_scroll_text.h"

#include <LiquidCrystal.h>
// Setup the LCD - modify for your configuration
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup() {
  setup_text();
  
}

void loop() {
  update_text();
  delay(80);
}
