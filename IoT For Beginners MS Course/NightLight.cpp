/*
This code is used to create an IoT night light
MCU: WIO
*/

#include <Arduino.h>

void setup()
{
    Serial.begin(9600);

    while (!Serial)
        ;
    delay(1000);

    pinMode(WIO_Light, input)   
}

void loop()
{
    int light = analogRead(WIO_Light);

    // Prints value returned from the sensor
    Serial.print("Light value ");
    Serial.print(light);

    //light up led
    if(light < 100)//Switch on LED at pit D0
        digitalWrite(D0, HIGH);
    else//Switch off LED
        digitalWrite(D0, LOW);

    delay(5000);
}