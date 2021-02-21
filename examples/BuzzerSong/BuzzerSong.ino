#include <WBuzzer.h>

WBuzzer buzzer;

const char notes[] = "cdfda ag cdfdg gf ";
const int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};

void setup() {
  buzzer.setup();

  buzzer.play(notes,beats);
}

void loop() {
  buzzer.loop();
}