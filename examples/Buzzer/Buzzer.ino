#include <WBuzzer.h>

WBuzzer buzzer;

void setup() {
  buzzer.setup();
}

void loop() {
  buzzer.tone(262,150); // c
  delay(500);
  buzzer.tone(294,150); // d
  delay(500);
  buzzer.tone(230,150); // e
  delay(500);
}