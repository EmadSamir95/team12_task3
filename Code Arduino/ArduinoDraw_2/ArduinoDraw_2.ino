
#include <AFMotor.h>
#include <Servo.h> 
AF_Stepper StepperX(48, 1); // A 48-step-per-revolution motor on channels 1 & 2
AF_Stepper StepperY(48, 2); // A 48-step-per-revolution motor on channels 3 & a
Servo ServoZ ; 

void initiate();

void setup() {
  StepperX.setSpeed(255);
  StepperY.setSpeed(255);
  ServoZ.attach (10)    ;  
initiate () ;
   DrawLine_H (5)       ;

}
 

void loop() 
{

  
   
   //DrawLine_V (5)       ;
   //DrawSquare (5 , 3)   ;
}

void initiate()
{
  ServoZ.write (-10);
  StepperX.step(400,FORWARD,MICROSTEP);
  StepperY.step(400,FORWARD,MICROSTEP);
}

void DrawLine_H (int Length)
{
   StepperX.step((Length*30), BACKWARD,MICROSTEP);
   delay (100);
   StepperX.step((Length*30),FORWARD,MICROSTEP);   
 }
 
void DrawLine_V (int Length)
{
   StepperY.step((Length*30), FORWARD,MICROSTEP);
   delay (100);
   StepperY.step((Length*30),BACKWARD,MICROSTEP);   
 }
 
  void draw_square (int Length , int Width)
  {
     StepperX.step((Length*30), FORWARD,MICROSTEP);
     delay (1000);
     StepperY.step((Length*30), FORWARD,MICROSTEP);
     delay (1000);
     StepperX.step((Width*30), BACKWARD,MICROSTEP);
     delay (1000);
     StepperY.step((Width*30),BACKWARD,MICROSTEP);
     delay (1000);
    }
