//ARDUINO LINE FOLLOWING CAR//
// YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
// GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //
 
//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define left A4
#define right A5

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);




void setup() {
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));

  //line detected by bot
  if(digitalRead(left)==0 && digitalRead(right)==0){
    //Forward
    motor1.run(FORWARD); 
    motor1.setSpeed(80);
    motor2.run(FORWARD);
    motor2.setSpeed(80);

  }
  //line detected by left sensor
  else if(digitalRead(left)==1 && !analogRead(right)==0){
    //turn left
    motor1.run(BACKWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
    motor2.setSpeed(70);

    
  }
  //line detected by right sensor
  else if(!analogRead(left)==0 && digitalRead(right)==1){
    //turn right
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(BACKWARD);
    motor2.setSpeed(70);
  
   
  }
  //line detected by none
  else if(!analogRead(left)==0 && !analogRead(right)==0){
    //stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
   
  }
  
}
