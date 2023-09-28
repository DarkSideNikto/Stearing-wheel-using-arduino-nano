#include <AltSoftSerial.h> 

AltSoftSerial vJoySerial; 

const int potentiometerPin = A0;
int potentiometerValue = 0; 
int angle = 0; // Variable to store the angle

void setup() {
  Serial.begin(9600);  // Initialize the Serial Monitor for debugging
  vJoySerial.begin(9600);
} 

void loop() {
  potentiometerValue = analogRead(potentiometerPin);

  // Map the potentiometer value to the desired angle range (e.g., 0 to 360 degrees)
  angle = map(potentiometerValue, 0, 1023, 0, 360);

  // Print the angle to the Serial Monitor for debugging
  Serial.println("Angle: " + String(angle) + " degrees");

  sendToVJoy(angle);
  delay(50); 
} 

void sendToVJoy(int value) {
  vJoySerial.println(String(value));
}