// Define the pins for ultrasonic sensors
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;

// Define the pins for vibration motors
const int motorPin1 = 6;
const int motorPin2 = 7;

void setup() {
  // Set ultrasonic sensor pins as input and motor pins as output
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Function to measure distance using ultrasonic sensor
  int distance1 = getDistance(trigPin1, echoPin1);
  int distance2 = getDistance(trigPin2, echoPin2);
  
  // Check if an object is within the range of ultrasonic sensor 1
  if (distance1 <= 50) {
    // Activate vibration motor 1
    digitalWrite(motorPin1, HIGH);
  } else {
    // Deactivate vibration motor 1
    digitalWrite(motorPin1, LOW);
  }
  
  // Check if an object is within the range of ultrasonic sensor 2
  if (distance2 <= 50) {
    // Activate vibration motor 2
    digitalWrite(motorPin2, HIGH);
  } else {
    // Deactivate vibration motor 2
    digitalWrite(motorPin2, LOW);
  }
  
  // Print distances to serial monitor
  Serial.print("Distance Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm | Distance Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  
  // Delay for stable readings
  delay(100);
}

// Function to measure distance using ultrasonic sensor
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;
  return distance;
}
