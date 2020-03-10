#include <Pixy2.h>
#include "configuration.h"

/*motor control*/
void forward (void)  //Forward
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,HIGH);
  digitalWrite(dir2PinR,LOW);
}
void spinLeft (void)  //Turn left
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,HIGH);
}
void spinRight (void)  //Turn right
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,HIGH);
  digitalWrite(dir1PinR,HIGH);
  digitalWrite(dir2PinR,LOW);
}
void backward (void)  //Reverse
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,HIGH);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,HIGH);
}
void stop ()    //Stop
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
	stop();
}

// This is the main Pixy object 
Pixy2 pixy;

void setup()
{
  Serial.begin(115200);
  Serial.print("Commencing find heart...\n");
	init_GPIO();

  pixy.init();
}

void loop()
{ 
//  int i; 

  // grab blocks!
  pixy.ccc.getBlocks();


  spinRight();
  set_Motorspeed(255,255);
  
  // If there are detect blocks stop and check if its the ball
  if (pixy.ccc.numBlocks)
  {
    stop();//Stop
    Serial.print("Detected an object... ");
    delay(1000);
//    Serial.println(pixy.ccc.numBlocks);
    for (int i=0; i<pixy.ccc.numBlocks; i++)
    {
      if (pixy.ccc.blocks[i].m_signature == 1) 
      {
        Serial.println("Dectected the red ball and will start to drive to it.");
        forward();
        set_Motorspeed(255,255);
        delay(2000);
        stop();
      }
      else 
      {
        Serial.println("False Alarm");
      }
      delay(1000);
    }
  }  
}
