const int trigPin = 9; // Trig pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor
const int buzzerPin = 8; // Buzzer pin
const int maxDistance = 60;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read echo pulse duration
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  long distance = duration * 0.034 / 2;
  
  // Output distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check distance and generate tone on buzzer
   if (distance >=  maxDistance) {
    tone(buzzerPin, 1000); // Play a tone with frequency 1000Hz
  } else {
    noTone(buzzerPin); // Turn off the buzzer if distance is greater than or equal to 60cm
  }
  
  delay(100); // Delay between readings
}

