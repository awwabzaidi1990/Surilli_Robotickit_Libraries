#define LDRpin A0    // pin where we connected the LDR and the resistor
int LDRValue = 0;     // result of reading the analog pin

void setup() 
{
    SerialUSB.begin(9600); // sets serial port for communication
}
void loop() 
{
  LDRValue = analogRead(LDRpin);   // read the value from the LDR
 // Serial.println(LDRValue);      // print the value to the serial port
  delay(1000);                     // wait a little
if(LDRValue<=450)
{
  SerialUSB.println("Mode: Night");
  }
else if(LDRValue>=451)
{
  SerialUSB.println("Mode: Day");
  } 
}

