int tracking_sensor_pin =10;
void setup() {
  pinMode(tracking_sensor_pin , INPUT);
  SerialUSB.begin(9600);
}
void loop() {
  delay(200);
  int TrackingSensor = digitalRead(tracking_sensor_pin);
  if(TrackingSensor == 1){
   SerialUSB.println("Obstacle not detected ");  
  }
  else if(TrackingSensor == 0){
   SerialUSB.println("Obstacle detected "); 
  }
}

