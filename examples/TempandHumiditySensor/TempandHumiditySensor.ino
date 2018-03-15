#include <dht.h>
#define dht_apin A0 // Analog Pin sensor is connected to A0
 
dht DHT;
void setup(){ 
  SerialUSB.begin(9600);
  delay(500);//Delay to let system boot
  SerialUSB.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}
void loop(){
    DHT.read11(dht_apin);    
    SerialUSB.print("Current humidity = ");
    SerialUSB.print(DHT.humidity);
    SerialUSB.print("%  ");
    SerialUSB.print("temperature = ");
    SerialUSB.print(DHT.temperature); 
    SerialUSB.println("C  ");
    delay(5000);//Wait 5 seconds before accessing sensor again.    
}
