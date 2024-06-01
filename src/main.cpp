#include <Arduino.h>
#include <IoTUltrasound.h>


#define TRIG_PIN D1 // GPIO5 (D1)
#define ECHO_PIN D2 // GPIO4 (D2)


//functions declaration
void loadPines();
long calculateDistance();

//variables
long distanceObject;
boolean parkedObject=false;

//program
void setup()
{
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop()
{
  loadPines();
  distanceObject=calculateDistance(pulseIn(ECHO_PIN,HIGH));
  parkedObject=parking(distanceObject);
    Serial.print("puede parquear?: ");
    Serial.print(parkedObject);
  delay(1000);
}

void loadPines()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}
