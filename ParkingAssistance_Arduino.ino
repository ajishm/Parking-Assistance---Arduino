const int trigPin = 4; // Sensor trigger set to Pin 4
const int echoPin = 2; // Sensor echo set to pin 2
int Buzzer = 8; // Buzzer set to pin 8

void setup() 
{
  Serial.begin(9600); // Initialize serial communication
  pinMode (Buzzer, OUTPUT); // Set Buzzer as output
}

void loop()
{
  // declare variables for duration of the ping, the distance result in centimeters and also for the calculated speed
  long totaltime, currentdistance, time1, time2, distance1, distance2;
  float d,t,speed;
  
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  totaltime = pulseIn(echoPin, HIGH); // Read the signal from the sensor: a HIGH pulse whose duration is the time (in microseconds) from the sending of the ping to the reception of its echo off of an object.
    
  currentdistance = timetodistance(totaltime); // convert the time into a distance using the function declared at the end of program
  Serial.print("Distance from Obstruction: ");
  Serial.print(currentdistance);
  Serial.print(" cm");
  Serial.println();

  distance1=currentdistance;
  time1=totaltime;
  
  delay(100);
  
  digitalWrite (trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite (trigPin, LOW);
  time2 = pulseIn (echoPin, HIGH);
  distance2 = timetodistance(time2);

  //long progtime = micros(); // Returns the time since the board started the program

  d=distance1-distance2;
  t=time1-time2;
  speed = d/t;
  speed = speed*3600; // Convert cm/microseconds to km/hr
  Serial.print("Speed of Auto: ");
  Serial.print(speed);
  Serial.print(" km/hr");
  Serial.println();

  if (currentdistance >= 70 && currentdistance < 100 && speed >= 65)
  {
    Serial.println("-------------------------------------");
    Serial.println("Reduce Auto Speed!!");
    Serial.println("-------------------------------------");
    Serial.println();
    tone(Buzzer, 5000); // Plays 5000 Hz tone
    delay(200);
    noTone(Buzzer); // Stops generating the tone
  }
  else if (currentdistance >= 70 && currentdistance < 100 && speed < 65)
  {
    Serial.println("-------------------------------------");
    Serial.println("Auto is in SAFE state!!");
    Serial.println("-------------------------------------");
    Serial.println();
  }
  else if (currentdistance >= 100)
  {
  Serial.println("-------------------------------------");
  Serial.println("Distance is OK");
  Serial.println("-------------------------------------");
  Serial.println();
  digitalWrite(Buzzer, LOW); // Buzzer is quiet, no sound
  }
  else 
  {
  Serial.println("----------------------------------------------");
  Serial.println("Obstruction near. STOP THE AUTO!!");
  Serial.println("----------------------------------------------");
  Serial.println();
  tone(Buzzer, 8000/currentdistance); // Plays (8000/currentdistance) Hz tone based on distance
  //tone(Buzzer, 800 * (1 + (speed-65)/35)); // Plays tone based on speed
  delay(2 * currentdistance);
  noTone(Buzzer); // Stops generating the tone
  }

}

long timetodistance(long microseconds)
{
  // The speed of sound is 340 m/s or 1/29 cm/microseconds.
  // The ping travels to and fro, so to find the distance of the object we take half of the distance travelled.
  return microseconds / 29 / 2;
}



