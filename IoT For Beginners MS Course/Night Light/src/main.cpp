// Header
//------------------------------
#include <Arduino.h>
// Const
//------------------------------
const int in_iLight = D4;
const int out_iLed = D6;
// Setup
//------------------------------
void setup() 
{
  Serial.begin(9600);

    while (!Serial)
        ;
    delay(1000);

    pinMode(in_iLight, INPUT);   
    pinMode(out_iLed, OUTPUT);
}
// Main Loop
//------------------------------
void loop() 
{
  int in_iLightLvl = analogRead(D4);

  // Prints value returned from the sensor
  Serial.print("Light value ");
  Serial.println(in_iLightLvl);

  //light up led
  
  if(in_iLightLvl < 100)//Switch on LED at pit D0
  {
    digitalWrite(out_iLed, HIGH);
    Serial.println("LED On");
  }
  else
  { 
    digitalWrite(out_iLed, LOW);
    Serial.println("LED Off");
  }
      
  delay(2000);
}

// Function Code
//------------------------------