#include <ESP32Servo.h>

Servo myservo;

// --- Definitions ---
#define SERVO_PIN 18
#define RXD2 16
#define TXD2 17

HardwareSerial SerialPi(2);

const int openAngle = 0;    // ✅ Rotate 45 degrees (was 90)
const int closeAngle = 90;

String incomingData = "";

void setup() {
  Serial.begin(115200);
  SerialPi.begin(115200, SERIAL_8N1, RXD2, TXD2);

  myservo.attach(SERVO_PIN);
  myservo.write(closeAngle);

  Serial.println("ESP32 Ready. Waiting for CODE RED signal...");
}

void loop() {
  while (SerialPi.available()) {
    char incomingChar = SerialPi.read();
    incomingData += incomingChar;

    if (incomingChar == '\n') {
      incomingData.trim();

      Serial.print("Received: ");
      Serial.println(incomingData);

      if (incomingData.indexOf("MCB_OFF") >= 0) {
        Serial.println(" CODE RED Received! Tripping MCB...");

        myservo.write(openAngle);   // 
        delay(3000);
        myservo.write(closeAngle);  // ➜ Return to 0°
        Serial.println(" MCB Reset to Normal Position.");
      }

      incomingData = "";
    }
  }
}
