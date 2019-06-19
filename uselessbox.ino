
#include "Servo.h"
Servo servo;
int randnum = 0;
int ballistic = 1;
const int button = 2;
int buttonpushed = 0;
const int maxang = 105;
const int minang = 0;
int repeat = 0;
int repeat2 = 0;
int angle = 0;
//functions
void standardturnoff(int x) {
  if (x == 0) // normal turn off
  {
    delay(200);
    servo.write(maxang);
    delay(500);
    servo.write(minang);
  }
}
void slowmoturnoff(int x)
{
  if (x == 1) // slow motion turn off
  {
    delay(200);
    for (angle = 0; angle < maxang+5; angle += 1)
    {
      servo.write(angle);
      delay(50);
    }
    delay(50);
    servo.write(minang);
  }
}
void wavefirstturnoff(int x)
{
  if (randnum == 2)//works
  { // waves and then turns off
    for (repeat = 0; repeat < 5; repeat += 1)
    {
      delay(100);
      servo.write(75);
      delay(100);
      servo.write(20);
    }
    servo.write(maxang);
    delay(100);
    servo.write(minang);
  }
}
void slowmofaster (int x) {
  if (randnum == 3)
  {
    for (ballistic = 0; ballistic < 100; ballistic += 15)
    {
      servo.write(ballistic);
      delay(100);
    }
    servo.write(maxang);
    delay (100);
    servo.write(minang);
  }
}




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(9);  //servo attached to pin 9
  pinMode(button, INPUT_PULLUP);
  servo.write(minang);
  randomSeed(analogRead(A0));

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonpushed = digitalRead(button); //check if button has been pressed
  if (buttonpushed == LOW) {
    delay(500);
    randnum = random(0, 4); // initialize random value
    Serial.print("the random number is");
    Serial.print(randnum);// initialize random value
   standardturnoff(randnum);
   slowmoturnoff(randnum);
   wavefirstturnoff(randnum);
   slowmofaster(randnum);
  if (buttonpushed == HIGH)
  {
    servo.write(minang);
  }
}
}
