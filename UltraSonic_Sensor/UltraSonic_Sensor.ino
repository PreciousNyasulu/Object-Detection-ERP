int trigPin = 12;
int echoPin = 11;
int led = 7;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.println(distance);
//  Serial.println("CM");
  delay(3000);

  if ((distance <= 10))
  {
    digitalWrite(led, HIGH);
  }
  else if (distance > 10)
  {
    digitalWrite(led, LOW);
  }
}
