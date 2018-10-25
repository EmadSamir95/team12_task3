#include <AFMotor.h>
#include <Servo.h>
AF_Stepper StepperX(48, 1); // A 48-step-per-revolution motor on channels 1 & 2
AF_Stepper StepperY(48, 2); // A 48-step-per-revolution motor on channels 4 & 3
Servo ServoZ ; 

void setup() {
  StepperX.setSpeed(255);
  StepperY.setSpeed(255);
  ServoZ.attach (10)    ;  
}

void loop() 
{

  //StepperX.step(200, FORWARD,DOUBLE);
  //StepperY.step(200, FORWARD,DOUBLE);
  ServoZ.write (90);
  delay(1000);

  //StepperX.step(250,BACKWARD,DOUBLE);
  //StepperY.step(200,BACKWARD,DOUBLE);
  ServoZ.write (-90);
  delay(1000);

}
