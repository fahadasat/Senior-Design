/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/ 
 * Arduino Smart Car Tutorial Lesson 1
 * Tutorial URL http://osoyoo.com/2017/04/23/arduinosmartcarlesson1/
 * CopyRight www.osoyoo.com

 * After running the code, smart car will go forward 5 seconds, then go backward 5
 * seconds, then left turn for 5 seconds then right turn for 5 seconds then stop. 
 * 
 */
 
#include "configuration.h"  //Read for insite on drivetrain function
#include "xArm_Integrate.h" //All the Arm functions are loade through here

/*motor control*/
void go_Advance(void)  //Forward
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,HIGH);
  digitalWrite(dir2PinR,LOW);
}
void go_Left(void)  //Turn left
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,HIGH);
}
void go_Right(void)  //Turn right
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,HIGH);
  digitalWrite(dir1PinR,HIGH);
  digitalWrite(dir2PinR,LOW);
}
void go_Back(void)  //Reverse
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,HIGH);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,HIGH);
}
void stop_Stop()    //Stop
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,LOW);
}

/*set motor speed */
void set_Motorspeed(int speed_L,int speed_R)
{
  analogWrite(speedPinL,speed_L); 
  analogWrite(speedPinR,speed_R);   
}

//Pins initialize
void init_GPIO()
{
	pinMode(dir1PinL, OUTPUT); 
	pinMode(dir2PinL, OUTPUT); 
	pinMode(speedPinL, OUTPUT);  
 
	pinMode(dir1PinR, OUTPUT);
  pinMode(dir2PinR, OUTPUT); 
  pinMode(speedPinR, OUTPUT); 
	stop_Stop();
}

void setup()
{
  Serial.begin(9600); //Set up Serial Communication (Arman Uses tx and rx pins)


	init_GPIO();
	go_Advance();//Forward
  set_Motorspeed(255,255);
  delay(5000);
  
//  go_Back();//Reverse
//  set_Motorspeed(255,255);
//  delay(5000);
//  
//  go_Left();//Turn left
//  set_Motorspeed(255,255);
//  delay(5000);
//  
//  go_Right();//Turn right
//  set_Motorspeed(255,255);
//  delay(5000);
//  
  
//     Arman_Default(); //Get Arman prepped
//     delay (2000);    //Wait for task to complete (nessisary?)
//     Arman_Pickup();  //Perform pickup routine
  stop_Stop();//Stop

}

void loop(){

     
}
