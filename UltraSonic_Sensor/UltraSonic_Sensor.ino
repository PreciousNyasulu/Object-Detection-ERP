int trigPin = 12;
int echoPin = 11;
int led = 7;
const int buzzer = 8; //buzzer to arduino pin 8

void setup() {
// setup code for the buzzer
 pinMode(buzzer, OUTPUT); // Set buzzer - pin 8 as an output
 
//  setup code fot the ultrasonic sensor 
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.println(String(distance));
  delay(600);

  if ((distance <= 10))
  {
    digitalWrite(led, HIGH);
    
    tone(buzzer, 1000); // Send 1KHz sound signal... AKA the buzzer will go off
  }
  else
  {
    digitalWrite(led, LOW);
    
    noTone(buzzer);     // Stop sound... AKA the buzzer will stop
  }
}
