#include <Wire.h>
#include <Arduino.h>

void receiveEvent(int howMany) {
  while (0 <Wire.available()) {
     char c = Wire.read();     
     Serial.print(c);           
   }
  Serial.println();            
 }
 

 void requestEvent() {
  Wire.write("Hello NodeMCU");  /*send string on request */
 }
void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial for debug */
}

void loop() {
 delay(100);
}

// function that executes whenever data is received from master
