int angle = 0;

#include "Servo.h"
Servo servo;
int randnum = 0;
int ballistic = 1;
const int button = 2;
int buttonpushed = 0;
const int maxang= 100;
const int minang= 0;
int repeat = 0;
void setup() {
  // put your setup code here, to run once:
servo.attach(9);  //servo attached to pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonpushed = digitalRead(buttonpushed); //check if button has been pressed
  if (buttonpushed == HIGH){
  randnum = random(0,4);// initialize random value
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
   if (randnum == 2)  // waving turn off
      { for (repeat; repeat < 5; repeat+=1)// note: don't know why i initialized it earlier, but I was getting an error if i dont
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
}
}