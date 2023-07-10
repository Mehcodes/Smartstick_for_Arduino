// defines pins numbers
const int trigPin = 9; // Assigns pin 9 as the trigger pin for the ultrasonic sensor
const int echoPin = 10; // Assigns pin 10 as the echo pin for the ultrasonic sensor
const int buzzer = 11; // Assigns pin 11 as the output pin for the buzzer
const int ledPin = 13; // Assigns pin 13 as the output pin for the LED

// defines variables
long duration; // Variable to store the duration of the sound wave travel time
int distance; // Variable to store the calculated distance from the ultrasonic sensor
int safetyDistance; // Variable to store the safety distance threshold

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT); // Sets the buzzer pin as an Output
  pinMode(ledPin, OUTPUT); // Sets the LED pin as an Output
  Serial.begin(9600); // Starts the serial communication at a baud rate of 9600
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
distance = duration * 0.034 * 0.3 / 2;

  safetyDistance = distance;
  if (safetyDistance <= 5) {
    digitalWrite(buzzer, HIGH); // Turns on the buzzer if the distance is less than or equal to 5
    digitalWrite(ledPin, HIGH); // Turns on the LED if the distance is less than or equal to 5
  } else {
    digitalWrite(buzzer, LOW); // Turns off the buzzer if the distance is greater than 5
    digitalWrite(ledPin, LOW); // Turns off the LED if the distance is greater than 5
  }

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}

// this code is commented and prepared by Mohamed Abdirazak Adam