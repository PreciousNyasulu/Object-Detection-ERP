int trigPin = 12;
int echoPin = 11;
int led = 7;
int relay = 2;
const int buzzer = 8; //buzzer to arduino pin 8
String motorcontrol = "";
int timer = 0;

void setup() {
  //setup code for relay
  pinMode(relay, OUTPUT);

  // setup code for the buzzer
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 8 as an output

  //  setup code fot the ultrasonic sensor
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {


//  while (true) {

    motorcontrol = Serial.readString();

    if (motorcontrol.indexOf("Start") >= 0) {
      Serial.println("Started");
      digitalWrite(relay, HIGH);
    }
    if (motorcontrol.indexOf("Stop") >= 0) {
      digitalWrite(relay, LOW);
      Serial.println("Stopped");
    } 
    
    long duration, distance;
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;

    Serial.println(String(distance));
    delay(300);

    if ((distance <= 10))
    {
      digitalWrite(led, HIGH);
      timer = 0;
      tone(buzzer, 100); // Send 1KHz sound signal... AKA the buzzer will go off
    }
    else
    {
      digitalWrite(led, LOW);

      noTone(buzzer);     // Stop sound... AKA the buzzer will stop
    }
      
//  }


    timer = timer + 1;

    if(timer == 20){
      digitalWrite(relay,LOW);
      timer = 0;
    }

}
