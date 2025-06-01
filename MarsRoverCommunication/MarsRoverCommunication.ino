#include <Servo.h>

Servo esc;

void setup() {
  esc.attach(9);
  esc.writeMicroseconds(1000); // throttle laagste stand
  delay(2000);

  Serial.begin(9600);
  //pinMode(13, OUTPUT);  // voorbeeld: LED of relais/motortrigger
}

void loop() {  
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "Obstacle") {
      esc.writeMicroseconds(1500); // stoppen     
      Serial.print("Obstakel gedetecteerd");
    } else if (cmd == "FreePath") {
      esc.writeMicroseconds(1700); // vooruit
      Serial.print("Vrij pad, gaan met die banaan");
    }
  }
}
