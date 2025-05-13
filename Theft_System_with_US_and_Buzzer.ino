const int trigPin = 6;
const int echoPin = 5;
const int buzzerPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo return time
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  float distance = duration * 0.034 / 2;

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check distance and activate buzzer
  if (distance <= 20) {
    digitalWrite(buzzerPin, HIGH);  // Turn buzzer ON
  } else {
    digitalWrite(buzzerPin, LOW);   // Turn buzzer OFF
  }

  delay(500);  // Small delay between readings
}


