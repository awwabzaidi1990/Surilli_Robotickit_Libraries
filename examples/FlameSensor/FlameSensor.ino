int flame_sensor_pin =10;
void setup() {
  pinMode(flame_sensor_pin, INPUT);
  SerialUSB.begin(9600);
}
void loop() {
  delay(500);
  int FlameSensor = digitalRead(flame_sensor_pin );
  if(FlameSensor == 1){
   SerialUSB.println("Flame not detected ");  
  }
  else if(FlameSensor == 0){
   SerialUSB.println("Flame detected "); 
  }
}
