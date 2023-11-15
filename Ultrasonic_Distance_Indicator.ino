#include <NewPing.h>

#define TRIGGER_PIN 10
#define ECHO_PIN 11

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define VIBRATOR_PIN 9

NewPing sonar(TRIGGER_PIN, ECHO_PIN);
int distance = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(VIBRATOR_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance: ");
  distance = sonar.ping_cm();
  Serial.println(distance);
  delay(100);

  if (distance == 0) {
    // Sensor reading error, do nothing
    return;
  }

  if ((distance <= 60) && (distance > 50)) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    analogWrite(VIBRATOR_PIN, 0); // No vibration
  } 
  else if ((distance <= 50) && (distance > 40)) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    analogWrite(VIBRATOR_PIN, 0); // No vibration
  } 
  else if ((distance <= 40) && (distance > 30)) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    analogWrite(VIBRATOR_PIN, 100); // Low intensity vibration
  } 
  else if ((distance <= 30) && (distance > 20)) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
    analogWrite(VIBRATOR_PIN, 200); // Medium intensity vibration
  } 
  else if (distance <= 20) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    analogWrite(VIBRATOR_PIN, 255); // Maximum intensity vibration
  }
  else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    analogWrite(VIBRATOR_PIN, 0); // No vibration
  }
}
