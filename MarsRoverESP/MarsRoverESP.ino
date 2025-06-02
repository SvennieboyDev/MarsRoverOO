#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ASG";
const char* password = "436426";

WebServer server(80);  // HTTP-server op poort 80

void handleCommand() {
  String cmd = server.arg("cmd");
  cmd.trim();
  
  if (cmd == "FreePath" || cmd == "Obstacle") {
    Serial.println(cmd);  // Stuur door naar Arduino via TX (pin 1)
    server.send(200, "text/plain", "OK");
  } else {
    server.send(400, "text/plain", "Invalid command");
  }
}

void setup() {
  Serial.begin(9600);  // Let op: dit is via TX0 (pin 1)
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  server.on("/control", handleCommand);
  server.begin();
}

void loop() {
  server.handleClient();
}
