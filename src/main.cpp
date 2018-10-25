// This in an servo controler that opens servo once per timeout. 
// PWR pin is used to control transistor and thus disable power on servo.

#include <Arduino.h>
#include <Servo.h> 


int SERVO_PIN = 9; 
int PWR_PIN = 8;

int T_CLOSED = 2000;
int T_OPEN = 1000;
int T_CHANGE = 1000;

Servo servo; 
void setup() { 
   // We need to attach the servo to the used pin number 
   servo.attach(SERVO_PIN); 
   pinMode(PWR_PIN, OUTPUT);
}
void loop(){ 


    digitalWrite(PWR_PIN, HIGH);
    delay(1000);
    servo.write(255);
    delay(T_OPEN);
    servo.write(0);
    delay(T_CHANGE);
    digitalWrite(PWR_PIN, LOW);
    delay(T_CLOSED);
}