
#include "Servo.h"
Servo servo;
int randnum = 0;
int ballistic = 1;
const int button = 2;
int buttonpushed = 0;
const int maxang= 100;
const int minang= 0;
int repeat = 0;
int repeat2 = 0;
int angle = 0;
void setup() {
  // put your setup code here, to run once:
servo.attach(9);  //servo attached to pin 9
pinMode(button, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonpushed = digitalRead(buttonpushed); //check if button has been pressed
  if (buttonpushed == LOW){
  randnum = random(0,5);// initialize random value
  if (randnum= 0) // normal turn off
  { 
    delay(200);
    servo.write(maxang);
    delay(50);
    servo.write(minang);
  }
  if (randnum==1)// slow motion turn off
    {
    delay(200);
    for(angle=0; angle<maxang; angle+=3)
      {
      servo.write(angle);
      delay(100);
      }
    delay(50);
    servo.write(minang);
    }
   if (randnum == 2) 
      {// waves and then turns off
       for (repeat=0; repeat < 5; repeat+=1)
       {
            delay(50);
            servo.write(75);
            delay(50);
            servo.write(20); 
       }
        servo.write(maxang);
        delay(50);
        servo.write(minang);
      }
   if (randnum == 3 )//erratic turn off
        {
            delay(50);
            for(ballistic; ballistic<maxang; ballistic = ballistic)
            {
              ballistic = random(0,maxang+1);
            }
              delay(50);
              servo.write(minang);
        }
   if (randnum == 4)  // turns off and then waves
      { 
        
        servo.write(maxang);
        delay(50);
        servo.write(minang);
    
        for (repeat2=0; repeat2 < 5; repeat2+=1)
        {
            delay(50);
            servo.write(75);
            delay(50);
            servo.write(20); 
        }
      }
   
}
servo.write(minang);
}
