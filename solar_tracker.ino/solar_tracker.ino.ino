// -----------------------------------------------------------
// Project: Dual LDR Sun-Tracking Solar Panel
// Architecture: Microcontroller (Arduino Uno)
// -----------------------------------------------------------

#include <Servo.h>

Servo sg90;
int servoAngle = 90;      // Tracks current angle (starts centered)
int LDR1_PIN = A0;        // LDR 1 Analog Input
int LDR2_PIN = A1;        // LDR 2 Analog Input
int errorTolerance = 15;  // Deadband threshold to prevent servo twitching
int servoPin = 4;         // PWM output pin for Servo

void setup() {
  Serial.begin(9600);       // CRITICAL: Initialize serial communication
  sg90.attach(servoPin);
  
  pinMode(LDR1_PIN, INPUT);
  pinMode(LDR2_PIN, INPUT);
  
  sg90.write(servoAngle);   // Center the servo on startup
  delay(1000);              // Give servo time to reach center
}

void loop() {
  int val1 = analogRead(LDR1_PIN);
  int val2 = analogRead(LDR2_PIN);

  // Clean, single-line serial debug printing
  Serial.print("LDR1: ");
  Serial.print(val1);
  Serial.print(" | LDR2: ");
  Serial.println(val2);

  // Calculate the absolute difference in light levels
  int diff = abs(val1 - val2);

  // Only move if the light difference is greater than our tolerance
  if (diff > errorTolerance) {
    if (val1 > val2) {
      servoAngle--; // Move towards LDR1
    } else if (val1 < val2) {
      servoAngle++; // Move towards LDR2
    }
  }

  // CRITICAL FIX: Software limits to prevent hardware damage
  if (servoAngle > 180) {
    servoAngle = 180;
  }
  if (servoAngle < 0) {
    servoAngle = 0;
  }

  sg90.write(servoAngle);
  delay(50); // Fast refresh rate for smooth sweeping
}