/*
  Based on:
  Character LCD Smooth-Scrolling text
  Information: https://joeraut.com/posts/smooth-scrolling-text-on-character-lcds/
  Joseph Rautenbach, 2020
*/

// Adjust these to yout liking
#define GAP_BETWEEN_CHARS 1
#define WHITESPACE_PIXELS 0

#define SINGLE_CHAR_WIDTH (5 + GAP_BETWEEN_CHARS)

byte *canvas;
byte *custom_chars[8];
int frame_count = 0;

// Function to get a 5x7 character block from an ASCII character value
const byte *get_5x7_char(char c);

// Reshape memory for converting from canvas data to a custom character
void transpose(byte *dest, byte *src);

// Generate the canvas containing the pixel data from the message we want to display
byte *generate_text_canvas(String text);

void init_text_scroll();

void update_text(int pos_px);
