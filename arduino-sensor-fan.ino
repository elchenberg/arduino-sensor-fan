#include "dht.h"
#define dht_apin A1 // Analog Pin sensor is connected to
// https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib

/*
How to connect a 3-pin DHT11 sensor to the arduino (see image):
http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
http://www.circuitbasics.com/wp-content/uploads/2015/12/DHT11-Pinout-for-three-pin-and-four-pin-types-2.jpg
*/

dht DHT;
void setup(){
    Serial.begin(9600);
    while(!Serial){}
    Serial.println("Arduino Mega 2560");
    Serial.println("DHT11 Humidity & Temperature Sensor");
    delay(1000);
}

void loop(){
    DHT.read11(dht_apin);
    Serial.print("Humidity: ");
    Serial.print(DHT.humidity);
    Serial.print("%");
    Serial.print(" ");
    Serial.print("Temperature: ");
    Serial.print(DHT.temperature);
    Serial.println("°C");
    // Minimum of two seconds between sensor readings according to sensor specification.
    delay(2000);
}// end loop()
