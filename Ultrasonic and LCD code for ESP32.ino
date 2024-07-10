#include <NewPing.h>

// Define pins
#define TRIGGER_PIN 12
#define ECHO_PIN 14
#define MAX_DISTANCE 400  // Maximum distance to measure (in cm)

// Define LCD pins
#define RS_PIN 23
#define EN_PIN 22
#define D4_PIN 21
#define D5_PIN 19
#define D6_PIN 18
#define D7_PIN 5

// Initialize the ultrasonic sensor
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Function to send a command to the LCD
void lcdCommand(uint8_t command) {
  digitalWrite(RS_PIN, LOW);
  digitalWrite(D4_PIN, (command >> 4) & 0x01);
  digitalWrite(D5_PIN, (command >> 5) & 0x01);
  digitalWrite(D6_PIN, (command >> 6) & 0x01);
  digitalWrite(D7_PIN, (command >> 7) & 0x01);
  digitalWrite(EN_PIN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN_PIN, LOW);
  delayMicroseconds(100);
  digitalWrite(D4_PIN, command & 0x01);
  digitalWrite(D5_PIN, (command >> 1) & 0x01);
  digitalWrite(D6_PIN, (command >> 2) & 0x01);
  digitalWrite(D7_PIN, (command >> 3) & 0x01);
  digitalWrite(EN_PIN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN_PIN, LOW);
  delayMicroseconds(100);
}

// Function to send data to the LCD
void lcdData(uint8_t data) {
  digitalWrite(RS_PIN, HIGH);
  digitalWrite(D4_PIN, (data >> 4) & 0x01);
  digitalWrite(D5_PIN, (data >> 5) & 0x01);
  digitalWrite(D6_PIN, (data >> 6) & 0x01);
  digitalWrite(D7_PIN, (data >> 7) & 0x01);
  digitalWrite(EN_PIN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN_PIN, LOW);
  delayMicroseconds(100);
  digitalWrite(D4_PIN, data & 0x01);
  digitalWrite(D5_PIN, (data >> 1) & 0x01);
  digitalWrite(D6_PIN, (data >> 2) & 0x01);
  digitalWrite(D7_PIN, (data >> 3) & 0x01);
  digitalWrite(EN_PIN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN_PIN, LOW);
  delayMicroseconds(100);
}

// Function to initialize the LCD
void lcdInit() {
  pinMode(RS_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
  pinMode(D4_PIN, OUTPUT);
  pinMode(D5_PIN, OUTPUT);
  pinMode(D6_PIN, OUTPUT);
  pinMode(D7_PIN, OUTPUT);
  delay(50); // Wait for the LCD to power up
  lcdCommand(0x03);
  delay(5);
  lcdCommand(0x03);
  delayMicroseconds(100);
  lcdCommand(0x03);
  delayMicroseconds(100);
  lcdCommand(0x02); // Set to 4-bit mode
  delayMicroseconds(100);
  lcdCommand(0x28); // 4-bit mode, 2 lines, 5x8 dots
  delayMicroseconds(100);
  lcdCommand(0x0C); // Display on, cursor off
  delayMicroseconds(100);
  lcdCommand(0x06); // Increment cursor
  delayMicroseconds(100);
  lcdCommand(0x01); // Clear display
  delay(2);
}

// Function to print a string to the LCD
void lcdPrint(const char *str) {
  while (*str) {
    lcdData(*str++);
  }
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize the LCD
  lcdInit();
}

void loop() {
  // Get the distance in cm
  int distance = sonar.ping_cm();

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Clear the LCD and print the distance
  lcdCommand(0x01); // Clear display
  delay(2);
  lcdCommand(0x80); // Set cursor to first row
  lcdPrint("Distance: ");
  char buffer[16];
  snprintf(buffer, sizeof(buffer), "%d cm", distance);
  lcdPrint(buffer);

  // Small delay to stabilize readings
  delay(500);
}
