//Inclusions
#include "Arman_Parameters.h"

//Function Prototypes
//Special
  void Bus_Header(void);    //Preps Serial to Arm
  void Arman_Sleep(void);   //Positions Arm for transport
  void Arman_Default(void);   //Positions are in a "Ready" position
  void Arman_Pickup(void);  //Routine to pick up object, rotate and drop
  void Arman_Align(void);  //Routine to point Arm verically to check aignment

//General
  void Arman_Move_1(int,int,int);   //Function to move 1 servo
  void Arman_Move_6(int,int,int,int,int,int,int);   //Function to move 6 servos
//End Funct. Prot.

class My_Servo{//Creates servo object unused:2/24/2019
  public:
    int ID;
    int angle;
};
void Arman_Align(){  
     Arman_Move_6(Align_Time,Align_Angle1,Align_Angle2,Align_Angle3,Align_Angle4,Align_Angle5,Align_Angle6);
     delay(Align_Time*1.5);//wait for success(150% Time to move)
}

void Arman_Default(){  
     Arman_Move_6(Default_Time,Default_Angle1,Default_Angle2,Default_Angle3,Default_Angle4,Default_Angle5,Default_Angle6);
     delay(Default_Time*1.5);//wait for success(150% Time to move)
}
void Arman_Sleep(){//needs re-calibration
  int time_move = 1000;
  
  //Positions 1-6//
  int pos_1 = 300;  //target angle of servo 1
  int pos_2 = 500;  //target angle of servo 2
  int pos_3 = 930;  //target angle of servo 3
  int pos_4 = 740;  //target angle of servo 4
  int pos_5 = 500;  //target angle of servo 5
  int pos_6 = 850;  //target angle of servo 6
    
  //Initializing Communication
    Bus_Header();         //Prepare the Bus
    
    Serial.write(23);     //writing serial length
                          // Inits(5 bytes) + 
                          // 6 servos * 8 commands
                          // = 23 bytes
    Serial.write(0x03);   //writing command "Move"
    Serial.write(6);      //writing to 6 servos (All)
    Serial.write(time_move & 0x00FF);  //Send lower time byte
    Serial.write(time_move >> 8);  //Send high time byte
  //Begin writing servos
    //Servo 1
    Serial.write(1);       //Send Servo ID byte
    Serial.write(pos_1 & 0x00FF); //Send lower angle byte
    Serial.write(pos_1 >> 8); //Send high angle byte

    //Servo 2
    Serial.write(2);       //Send Servo ID byte
    Serial.write(pos_2 & 0x00FF); //Send lower angle byte
    Serial.write(pos_2 >> 8); //Send high angle byte

    //Servo 3
    Serial.write(3);       //Send Servo ID byte
    Serial.write(pos_3 & 0x00FF); //Send lower angle byte
    Serial.write(pos_3 >> 8); //Send high angle byte

    //Servo 4
    Serial.write(4);       //Send Servo ID byte
    Serial.write(pos_4 & 0x00FF); //Send lower angle byte
    Serial.write(pos_4 >> 8); //Send high angle byte

    //Servo 5
    Serial.write(5);       //Send Servo ID byte
    Serial.write(pos_5 & 0x00FF); //Send lower angle byte
    Serial.write(pos_5 >> 8); //Send high angle byte

    //Servo 6
    Serial.write(6);       //Send Servo ID byte
    Serial.write(pos_6 & 0x00FF); //Send lower angle byte
    Serial.write(pos_6 >> 8); //Send high angle byte
}

void  Arman_Move_6(int time_move,int pos_1,int pos_2, int pos_3, int pos_4, int pos_5, int pos_6){
    
  //Initializing Communication
    Bus_Header();         //Prepare the Bus
    
    Serial.write(23);     //writing serial length
                          // Inits(5 bytes) + 
                          // 6 servos * 8 commands
                          // = 23 bytes
    Serial.write(0x03);   //writing command "Move"
    Serial.write(6);      //writing to 6 servos (All)
    Serial.write(time_move & 0x00FF);  //Send lower time byte
    Serial.write(time_move >> 8);  //Send high time byte
  //Begin writing servos
    //Servo 1
    Serial.write(1);       //Send Servo ID byte
    Serial.write(pos_1 & 0x00FF); //Send lower angle byte
    Serial.write(pos_1 >> 8); //Send high angle byte

    //Servo 2
    Serial.write(2);       //Send Servo ID byte
    Serial.write(pos_2 & 0x00FF); //Send lower angle byte
    Serial.write(pos_2 >> 8); //Send high angle byte

    //Servo 3
    Serial.write(3);       //Send Servo ID byte
    Serial.write(pos_3 & 0x00FF); //Send lower angle byte
    Serial.write(pos_3 >> 8); //Send high angle byte

    //Servo 4
    Serial.write(4);       //Send Servo ID byte
    Serial.write(pos_4 & 0x00FF); //Send lower angle byte
    Serial.write(pos_4 >> 8); //Send high angle byte

    //Servo 5
    Serial.write(5);       //Send Servo ID byte
    Serial.write(pos_5 & 0x00FF); //Send lower angle byte
    Serial.write(pos_5 >> 8); //Send high angle byte

    //Servo 6
    Serial.write(6);       //Send Servo ID byte
    Serial.write(pos_6 & 0x00FF); //Send lower angle byte
    Serial.write(pos_6 >> 8); //Send high angle byte
}


void Arman_Move_1(int time_move,    //time(ms) to move
                    int SID,          //servo ID #
                    int angle_move){  //angle [0,1000]
                      
    Bus_Header();         //Prepare the Bus
    Serial.write(0x08);   //writing serial length - #bits
    Serial.write(0x03);   //writing command - 0x3 =move
    Serial.write(0x01);   //writing to one servo
    Serial.write(time_move & 0x00FF);  //Send lower time byte
    Serial.write(time_move >> 8);      //Send high time byte
    Serial.write(SID);                 //Send Servo ID byte
    Serial.write(angle_move & 0x00FF); //Send lower angle byte
    Serial.write(angle_move >> 8);     //Send high angle byte

  }
void Bus_Header(){         //Used to alert the xArm board to receive
    Serial.write(0x55); //alert data 1
    Serial.write(0x55); //alert data 2
  }

void Arman_Pickup(){

//     Arman_Reach
     Arman_Move_6(Reach_Time,Reach_Angle1,Reach_Angle2,Reach_Angle3,Reach_Angle4,Reach_Angle5,Reach_Angle6);
     delay (Reach_Time*1.5);//wait for success(150% Time to move)
     
//     Arman_Pinch
     Arman_Move_1(Pinch_Time,1,Pinch_Angle);
     delay (Pinch_Time*1.5);//wait for success(150% Time to move)

//     Arman_Retrieve
     Arman_Move_6(Reach_Time,Pinch_Angle,Default_Angle2,Default_Angle3,Default_Angle4,Default_Angle5,Reach_Angle6);
     delay(Default_Time*1.5);//wait for success(150% Time to move)

//    Arman_Rotate
     Arman_Move_1(Rotate_Time,6,Rotate_Angle);
     delay (Rotate_Time*1.5);//wait for success(150% Time to move)


//    Arman_Release
     Arman_Move_1(Release_Time,1,Release_Angle);
     delay (Release_Time*1.5);//wait for success(150% Time to move)

  Arman_Default();
     delay (4000);
  }     
  
////////////////////////////////////////////////////////
/////////////////////OLD LOOP///////////////////////////
////////////////////////////////////////////////////////
//void loop() {
//  //
//  int time_move;
//  int angle_move;
//  //Servos
//  My_Servo S1;
//  My_Servo S2;
//  My_Servo S3;
//  My_Servo S4;
//  My_Servo S5;
//  My_Servo S6;
////  //Pointers
////  int *S1 = &S1;
////  int *S2 = &S2;
////  int *S3 = &S3;
////  int *S4 = &S4;
////  int *S5 = &S5;
////  int *S6 = &S6;
//  
//  //Position 1: Open claw//  
//  time_move = 1000;   //time to move servo
//  angle_move = 200;  //angle to move servo (NEED UNITS)
//
//    int timeL = time_move & 0x00FF;       //time(ms) low 
//    int timeH = time_move >> 8;     //time(ms) high
//    int SID   = 0x01;       //servo ID #
//    int angleL= angle_move & 0x00FF;      //angle low
//    int angleH= angle_move >> 8;    //angle high
//      
////    Move_One_Servo(time_move, SID, angle_move);//apply position
//
//    
////    Read_1_Servo(*S2);
////    delay(5000); 
//     
//    
////    Arman_Default();
////    delay (1000);
//
////    Arman_Reach();
////    delay (3000);
////////////////Modify these for Testing/ Playing//////////////
//    int pos_1 = Pinch_Angle;  //position for servo 1
//    int pos_2 = 550;  //position for servo 2
//    int pos_3 = 800;  //position for servo 3
//    int pos_4 = 800;  //position for servo 4
//    int pos_5 = 400;  //position for servo 5
//    int pos_6 = 500;  //position for servo 6
//    int TM6 = 2000;   //time to make move changes;
//    
//
/////////////////////////////////////////////////////////////
//
//     Arman_Default();
//     delay (4000);
//     Arman_Pickup();
//     //delay (Pinch_Time+Ready_Time+Rotate_Time+Release_Time);
//
//}
    
