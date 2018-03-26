#include <Arduino.h>   // required before wiring_private.h
#include "wiring_private.h" // pinPeripheral() function

int flag=0;
int state;
int stateStop=0;

int motor1Pin1 = 12; // pin 12 on L293D IC
int motor1Pin2 = 9;  // pin 9 on L293D IC
int enable1Pin = 0;  // pin 0 on L293D IC

int motor2Pin1 = 5;  // pin 5 on L293D IC
int motor2Pin2 = 6;  // pin 6 on L293D IC
int enable2Pin = 1; // pin 1 on L293D IC

Uart Serial2 (&sercom1, 11, 10, SERCOM_RX_PAD_0, UART_TX_PAD_2);
void SERCOM1_Handler()
{
  Serial2.IrqHandler();
}
 
void setup() {
  SerialUSB.begin(9600); 
  Serial2.begin(9600);
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    // sets enable1Pin and enable2Pin high so that motor can turn on:
    analogWrite(enable1Pin, 255);
    analogWrite(enable2Pin, 255);
    // Assign pins 10 & 11 SERCOM functionality
    pinPeripheral(10, PIO_SERCOM);
    pinPeripheral(11, PIO_SERCOM);
}
 
void loop() {
   
       if(Serial2.available()){     
        state = Serial2.read();   
      flag=0;
    }   
    // if the state is 'F' the DC motor will go forward
    if (state == 'F') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          SerialUSB.println("Go Forward!");
          flag=1;
        }
    }    
    // if the state is 'L' the motor will turn left
    else if (state == 'L') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          SerialUSB.println("Turn LEFT");
          flag=1;
        }
    }
    // if the state is 'S' the motor will Stop
    else if (state == 'S' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          SerialUSB.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
    // if the state is 'R' the motor will turn right
    else if (state == 'R') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          SerialUSB.println("Turn RIGHT");
          flag=1;
        }
    }
    // if the state is 'B' the motor will Reverse
    else if (state == 'B') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          SerialUSB.println("Reverse!");
          flag=1;
        }
    }
}
