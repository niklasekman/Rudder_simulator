

void setup_text() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // Generate the canvas
  canvas = generate_canvas(message_text);

  // Allocate memory for the eight custom characters
  for (int i = 0; i < NUMCHARS; i++) {
    custom_chars[i] = (byte *) malloc(8);
  }

  for (int i = 0; i < NUMCHARS; i++) {
    lcd.setCursor(i+5, 0);
    lcd.write((byte) i); // Print ASCII values 0 to 7, which will be our custom characters
  }
}

void update_text() {
  for (int i = 0; i < NUMCHARS; i++) { // For each custom character
    int offset = (i*SINGLE_CHAR_WIDTH + frame_count); // Generate offset for current frame
    offset = offset % (message_text.length()*SINGLE_CHAR_WIDTH + WHITESPACE_PIXELS);
    transpose(custom_chars[i], &canvas[offset]); // Copy data from canvas into custom character
    lcd.createChar(i, custom_chars[i]); // Push custom character to the display
  }
  frame_count++; // Shift text left by one pixel
}

// Function to get a 5x7 character block from an ASCII character value
const byte *get_5x7_char(char c) {
  if (c == 0x20) {
    return &num5x7[0];
  } else {
    return &num5x7[5 * (c-0x2f)];
  }
}

// Reshape memory for converting from canvas data to a custom character
void transpose(byte *dest, byte *src) {
  for (byte y = 0; y < 8; y++) {
    dest[y] = 0;
    for (byte x = 0; x < 5; x++) {
      dest[y] |= ((src[4 - x] >> y) & 1) << x;
    }
  }
}

// Generate the canvas containing the pixel data from the message we want to display
byte *generate_canvas(String text) {
  // Allocate memory for the canvas, with each byte representing one column (7 pixels)
  byte *canvas = (byte*) calloc(text.length()*SINGLE_CHAR_WIDTH + WHITESPACE_PIXELS*2, sizeof(byte));

  // Copy each character from the string of text onto the canvas
  for (int i = 0; i < text.length(); i++) {
    memcpy(canvas + i*SINGLE_CHAR_WIDTH + WHITESPACE_PIXELS, get_5x7_char(text.charAt(i)), 5);
  }

  return canvas;
}
