void init_sinlut() {
  for(int i = 0; i < 628; i++) {
    sinlut[i] = round(sin((float)i/100.0)*32767.0);
  }
}

void init_wave_motion() {
  init_sinlut();
}

int get_yaw(int offset, int magnitude, int phase) {
  return offset + sinlut[phase] / (32767 / magnitude);
}
