#include <Arduino.h>
#include <IoTUltrasound.h>
#include <IoTcomLib.h>

#define TRIG_PIN D1 // GPIO5 (D1)
#define ECHO_PIN D2 // GPIO4 (D2)

// functions declaration
void loadPines();
long calculateDistance();
void parkingAvaible();

// variables
long distanceObject;
boolean parkedObject = false;

// program
void setup()
{
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  ConectarRed("name_wifi", "******");
  InicializarThingSpeak(2567148, "7M9DZZ7W7A0OYF2U", "RGJWAVPVCWFOFZSR");
}

void loop()
{
  loadPines();
  parkingAvaible();
  delay(3000);
}

void loadPines()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}

void parkingAvaible()
{
  distanceObject = calculateDistance(pulseIn(ECHO_PIN, HIGH));
  parkedObject = parking(distanceObject);
  EnviarThingSpeakDatos(1, parkedObject);
}
