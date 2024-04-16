#include "dht.h"

#define fanPin 3         // PWM-capable pin for controlling the fan
#define dht_aPin A0      // Analog pin DHT sensor is connected to Arduino
#define ir_Pin 2         // Digital pin IR sensor is connected to Arduino
#define ldr_Pin A1       // Analog pin LDR sensor connected to Arduino
#define led_pin 6        // Digital pin LED connected
#define FAN_THRESHOLD 20 // Temperature threshold to turn on the fan (adjust as needed)
#define LIGHT_THRESHOLD 300 // Threshold value for LDR sensor

dht DHT;

void setup() {
  Serial.begin(9600);
  pinMode(ir_Pin, INPUT);    // Set IR pin as input
  pinMode(dht_aPin, INPUT);  // Set DHT pin as input
  pinMode(ldr_Pin, INPUT);   // Set LDR pin as input
  pinMode(fanPin, OUTPUT);   // Set Fan Pin as output
  pinMode(led_pin, OUTPUT);  // Set LED pin as output
}

void loop() {
  int irValue = digitalRead(ir_Pin);       // Read IR sensor
  int lightValue = analogRead(ldr_Pin);    // Read LDR sensor
  DHT.read11(dht_aPin);

  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
  Serial.println(" C ");
  Serial.print("Light intensity:");
  Serial.println(lightValue);

  if (irValue == LOW) {
    // IR sensor detects motion
    if (DHT.temperature > FAN_THRESHOLD && lightValue < LIGHT_THRESHOLD) {
      // Both conditions are met, turn on fan and LED
      digitalWrite(fanPin, HIGH);
      digitalWrite(led_pin, HIGH);
      Serial.println("Motion detected! Temperature above threeshold! Fan turned on!\nLight intensity below threshold! LED turned on!");
    } 
    else if (DHT.temperature > FAN_THRESHOLD && lightValue > LIGHT_THRESHOLD ) {
      // Only temperature condition is met, turn on fan
      digitalWrite(fanPin, HIGH);
      digitalWrite(led_pin, LOW);
      Serial.println("Motion detected! Temperature above threshold! Fan turned on!\nLight intensity above threshold! LED turned off!");
    } 
      else if (DHT.temperature > FAN_THRESHOLD && lightValue > LIGHT_THRESHOLD) {
      // Only light intensity condition is met, turn on LED
      digitalWrite(led_pin, LOW);
      digitalWrite(fanPin, LOW);
      Serial.println("Motion detected! Temperature above threshold! Fan turned off!\nLight intensity below threshold! LED turned off!");
    } 
      else if (DHT.temperature < FAN_THRESHOLD && lightValue > LIGHT_THRESHOLD) {
      // Only light intensity condition is met, turn on LED
      digitalWrite(led_pin, LOW);
      digitalWrite(fanPin, LOW);
      Serial.println("Motion detected! Temperature below threshold! Fan turned off!\nLight intensity below threshold! LED turned off!");
    } 
   
  } else {
    // IR sensor does not detect motion, turn off fan and LED
    digitalWrite(fanPin, LOW);
    digitalWrite(led_pin, LOW);
    Serial.println("No motion detected! Fan and LED turned off!");
  }

  delay(5000); // Adjust delay as needed
}
