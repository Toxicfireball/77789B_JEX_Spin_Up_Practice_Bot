/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */ 
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// cata_rotate          rotation      4               
// inertial_sensor      inertial      7               
// back_X_rotation      rotation      5               
// DigitalOutA          digital_out   A               
// DigitalOutB          digital_out   B               
// DigitalOutC          digital_out   C               
// DigitalOutD          digital_out   D               
// DigitalOutE          digital_out   E               
// DigitalOutF          digital_out   F               
// Expansion_out        digital_out   G               
// Limitswitch_cata     limit         H               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
motor frontleft = motor(PORT1,vex::gearSetting::ratio6_1,true);
motor midleft = motor(PORT2, vex::gearSetting::ratio6_1, true);
motor backleft = motor(PORT3,vex::gearSetting::ratio6_1,true);
motor frontright = motor(PORT11,vex::gearSetting::ratio6_1,false);
motor midright = motor(PORT12, vex::gearSetting::ratio6_1,false);
motor backright = motor(PORT13,vex::gearSetting::ratio6_1,false);
motor cat_test = motor(PORT8, vex::gearSetting::ratio36_1,false);
motor intake = motor(PORT20, vex::gearSetting::ratio18_1,false);
controller H =  controller(primary);
controller V = controller(partner);
competition Competition;



const double pi = M_PI;
const float dia = 3.25;
const double auto_correction  = 1;
double Ro_auto_correction = 1.108;
double inch_to_rev(double input){

  double val;
  val  = input*dia*pi*auto_correction;
  return val;
}

double X_rotate_inch_to_rev(double input){

  double val;
  val  = input*dia*pi*Ro_auto_correction;
  return val;


}


double degree_to_radian(double degree){

    double radian;
    radian = degree * (pi/180);
    return radian;

}
void move_base(float speed){
 
  frontleft.spin(forward,speed*0.6,vex::voltageUnits::volt);
  midleft.spin(forward,speed*0.6,vex::voltageUnits::volt);
  backleft.spin(forward,speed*0.6,vex::voltageUnits::volt);
  frontright.spin(forward,speed*0.6,vex::voltageUnits::volt);
  midright.spin(forward,speed*0.6,vex::voltageUnits::volt);
  backright.spin(forward,speed*0.6,vex::voltageUnits::volt);

  

   
}

void true_move_base(float speed){
 
  frontleft.spin(forward,speed,vex::voltageUnits::volt);
  midleft.spin(forward,speed,vex::voltageUnits::volt);
  backleft.spin(forward,speed,vex::voltageUnits::volt);
  frontright.spin(forward,speed,vex::voltageUnits::volt);
  midright.spin(forward,speed,vex::voltageUnits::volt);
  backright.spin(forward,speed,vex::voltageUnits::volt);

  

   
}

void hold_base(){


  frontleft.stop(hold);
  midleft.stop(hold);
  backleft.stop(hold);
  frontright.stop(hold);
  midright.stop(hold);
  backright.stop(hold);

}
void tank_left(float speed){

  frontleft.spin(forward,-speed*0.6,vex::voltageUnits::volt);
  midleft.spin(forward,-speed*0.6,vex::voltageUnits::volt);
  backleft.spin(forward,-speed*0.6,vex::voltageUnits::volt);
  frontright.spin(forward,speed*0.6,vex::voltageUnits::volt);
  midright.spin(forward,speed*0.6,vex::voltageUnits::volt);
  backright.spin(forward,speed*0.6,vex::voltageUnits::volt);
   
}

void tank_right(float speed ){
  frontleft.spin(forward,speed*0.6,vex::voltageUnits::volt);
  midleft.spin(forward,speed*0.6,vex::voltageUnits::volt);
  backleft.spin(forward,speed*0.6,vex::voltageUnits::volt);
  frontright.spin(forward,-speed*0.6,vex::voltageUnits::volt);
  midright.spin(forward,-speed*0.6,vex::voltageUnits::volt);
  backright.spin(forward,-speed*0.6,vex::voltageUnits::volt);

}

void chasis_move(float Lspeed, float Rspeed){

  frontleft.spin(forward,Lspeed*0.6,vex::voltageUnits::volt);
  midleft.spin(forward,Lspeed*0.6,vex::voltageUnits::volt);
  backleft.spin(forward,Lspeed*0.6,vex::voltageUnits::volt);
  frontright.spin(forward,Rspeed*0.6,vex::voltageUnits::volt);
  midright.spin(forward,Rspeed*0.6,vex::voltageUnits::volt);
  backright.spin(forward,Rspeed*0.6,vex::voltageUnits::volt);

  

   
}


void pure_chasis_move(float Lspeed, float Rspeed){

  frontleft.spin(forward,Lspeed,vex::voltageUnits::volt);
  midleft.spin(forward,Lspeed,vex::voltageUnits::volt);
  backleft.spin(forward,Lspeed ,vex::voltageUnits::volt);
  frontright.spin(forward,Rspeed,vex::voltageUnits::volt);
  midright.spin(forward,Rspeed,vex::voltageUnits::volt);
  backright.spin(forward,Rspeed,vex::voltageUnits::volt);

  

   
}
void base_left(float speed){
  frontleft.spin(forward,speed*0.6,vex::voltageUnits::volt);
  midleft.spin(forward,speed*0.6,vex::voltageUnits::volt);
  backleft.spin(forward,speed*0.6,vex::voltageUnits::volt);

}

void base_right(float speed){

  frontright.spin(forward,speed*0.6,vex::voltageUnits::volt);
  midright.spin(forward,speed*0.6,vex::voltageUnits::volt);
  backright.spin(forward,speed*0.6,vex::voltageUnits::volt);


}

double rad_to_deg(double rad){
  return rad *(180.0 / M_PI);

}

void pneumatics_thing(){

   if(H.ButtonX.pressing()==1){

      DigitalOutA.set(false);
      DigitalOutB.set(false);
   }
   else{
     DigitalOutA.set(true);
     DigitalOutB.set(false);
   }


}


void encoder_fwd(float target, float speed){
  midleft.resetRotation();
  float sensor_val = midleft.rotation(rev);
  while (sensor_val < target){
    sensor_val = midleft.rotation(rev);
    move_base(speed);

  }
  move_base(0);

}
void advfwd(float target, float speed, float slowspeed, float slowzone){
   double error;
   frontleft.resetRotation();
   frontright.resetPosition();
   midleft.resetPosition();
   midright.resetPosition();
   backleft.resetPosition();
   backright.resetPosition();
   double joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;

   double joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev)))/3;
   double joint_sensor = (joint_right + joint_left)/2;
   error = target - joint_sensor;
   double slowdist;
   slowdist =  target/slowzone;
   bool reached=  false; 
   while(reached == false){
        joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
        joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev)))/3;
        joint_sensor = (joint_right + joint_left)/2;
        error = target - joint_sensor;
        if (error > slowdist ){ 
           move_base(speed);

        }
        else if(error< slowdist && error > 0){
          move_base(slowspeed);

        }
        else if(error < 0 ){
          move_base(-slowspeed);
        }
        else if(error == 0){
          reached = true;
        } 
   }
   hold_base();
   vex::task::sleep(20);
   move_base(0);



}

// A global instance of competition


// define your global instances of motors and other devices here


void cata_run(float spd_pct){
  float speed_change_zone = 146.15;
  float rotate_val = cata_rotate.angle(degrees);
  int Ax3 = (H.Axis3.value()/(127/12))*spd_pct;
  int Ax2 = (H.Axis2.value()/(127/12))*spd_pct;
  if(H.ButtonL1.pressing() == 1){
  timer ti;
  rotate_val =  cata_rotate.angle(degrees);
   while (rotate_val < speed_change_zone){
       Ax3 = (H.Axis3.value()/(127/12))*spd_pct;
      Ax2 = (H.Axis2.value()/(127/12))*spd_pct;

    pure_chasis_move(Ax3,Ax2);
  
    cat_test.spin(reverse,12 , vex::voltageUnits::volt);
    
     if (ti > 450){

       break;
     }
     
      }  
      cat_test.stop();
    
      rotate_val =  cata_rotate.angle(degrees);
   while(rotate_val  >= speed_change_zone){
      Ax3 = (H.Axis3.value()/(127/12))*spd_pct;
      Ax2 = (H.Axis2.value()/(127/12))*spd_pct;
      rotate_val =  cata_rotate.angle(degrees);
       Brain.Screen.clearLine();
       Brain.Screen.print(rotate_val);

       pure_chasis_move(Ax3,Ax2);
       cat_test.spin(reverse,12 , vex::voltageUnits::volt);
           if(H.ButtonB.pressing() == 1){

     Expansion_out.set(true);


    }
    else{

      Expansion_out.set(false);
    }
      }

      V.rumble(".");
   
       cat_test.stop();

  }
}


void dog_cata_run(float spd_pct){
  float speed_change_zone = 146.15;
  float rotate_val = cata_rotate.angle(degrees);
    float Ch3 = H.Axis3.value() * spd_pct;

    float Ch1 = H.Axis1.value()* spd_pct;
  if(H.ButtonL1.pressing() == 1){
  timer ti;
  rotate_val =  cata_rotate.angle(degrees);
   while (rotate_val < speed_change_zone){
    Ch3 = H.Axis3.value() * spd_pct;

    Ch1 = H.Axis1.value()* spd_pct;
      if(H.ButtonR1.pressing()== 1){

      intake.spin(forward, 12, vex::voltageUnits::volt);
    }
    else if (H.ButtonR2.pressing() == 1){
      intake.spin(reverse, 12 ,vex::voltageUnits::volt);
    }
    else{
      intake.stop();
    }
 

    if(fabs(Ch3) > 10 ){
      chasis_move(Ch3 , Ch3 );
    }else if(fabs(Ch1) > 15){
       chasis_move(Ch1 * 0.5, -Ch1 *0.5);
    }else {
      move_base(0);
    }
  
    cat_test.spin(reverse,12 , vex::voltageUnits::volt);
    
     if (ti > 450){

       break;
     }
     
      }  
      cat_test.stop();
    
      rotate_val =  cata_rotate.angle(degrees);
   while(rotate_val  >= speed_change_zone){
         Ch3 = H.Axis3.value() * spd_pct;

    Ch1 = H.Axis1.value()* spd_pct;
      rotate_val =  cata_rotate.angle(degrees);
       Brain.Screen.clearLine();
       Brain.Screen.print(rotate_val);
  
    if(fabs(Ch3) > 10 ){
      chasis_move(Ch3 , Ch3);
    }else if(fabs(Ch1) > 15){
       chasis_move(Ch1 * 0.5, -Ch1 *0.5);
    }else {
      move_base(0);
    }
             if(H.ButtonR1.pressing()== 1){

      intake.spin(forward, 12, vex::voltageUnits::volt);
    }
    else if (H.ButtonR2.pressing() == 1){
      intake.spin(reverse, 12 ,vex::voltageUnits::volt);
    }
    else{
      intake.stop();
    }
       intake.spin(reverse,(V.Axis2.value())/(127/12), vex::voltageUnits::volt);  
       cat_test.spin(reverse,12 , vex::voltageUnits::volt);
           if(H.ButtonB.pressing() == 1){

     Expansion_out.set(true);


    }
    else{

      Expansion_out.set(false);
    }
      }

      V.rumble(".");
   
       cat_test.stop();

  }
}

void cata_runV(float spd_pct){
  float speed_change_zone = 146.15;
  float rotate_val = cata_rotate.angle(degrees);
  int Ax3 = (H.Axis3.value()/(127/12))*spd_pct;
  int Ax2 = (H.Axis2.value()/(127/12))*spd_pct;
  if(H.ButtonL1.pressing() == 1){
  timer ti;
  rotate_val =  cata_rotate.angle(degrees);
   while (rotate_val < speed_change_zone){
           Ax3 = (H.Axis3.value()/(127/12))*spd_pct;
      Ax2 = (H.Axis2.value()/(127/12))*spd_pct;
     pure_chasis_move(Ax3,Ax2);



        if(H.ButtonR1.pressing()== 1){

      intake.spin(forward, 12, vex::voltageUnits::volt);
    }
    else if (H.ButtonR2.pressing() == 1){
      intake.spin(reverse, 12 ,vex::voltageUnits::volt);
    }
    else{
      intake.stop();
    }
    cat_test.spin(reverse,12 , vex::voltageUnits::volt);
    
     if (ti > 450){

       break;
     }
     
      }  
      cat_test.stop();
    
      rotate_val =  cata_rotate.angle(degrees);
   while(rotate_val  >= speed_change_zone){
           Ax3 = (H.Axis3.value()/(127/12))*spd_pct;
      Ax2 = (H.Axis2.value()/(127/12))*spd_pct;
      rotate_val =  cata_rotate.angle(degrees);
       Brain.Screen.clearLine();
       Brain.Screen.print(rotate_val);
      pure_chasis_move(Ax3,Ax2);
     if(H.ButtonR1.pressing()== 1){

      intake.spin(forward, 12, vex::voltageUnits::volt);
    }
    else if (H.ButtonR2.pressing() == 1){
      intake.spin(reverse, 12 ,vex::voltageUnits::volt);
    }
    else{
      intake.stop();
    }
       cat_test.spin(reverse,12 , vex::voltageUnits::volt);
           if(H.ButtonB.pressing() == 1){

     Expansion_out.set(true);


    }
    else{

      Expansion_out.set(false);
    }
      }

      V.rumble(".");
   
       cat_test.stop();

  }
}
void print_to_controller(){

    H.Screen.setCursor(3, 1);

    H.Screen.print("Base Temp %f",(frontleft.temperature(vex::percentUnits::pct)+midleft.temperature(vex::percentUnits::pct)+midright.temperature(vex::percentUnits::pct)+frontright.temperature(vex::percentUnits::pct))/4);
    H.Screen.setCursor(4,1);
    H.Screen.print("Cat Temp %f", cat_test.temperature(vex::percentUnits::pct));
    

}


void solo_driver_control(float spd_pct){

    H.Screen.clearLine();
    H.Screen.setCursor(3, 1);
    

    
    H.Screen.print("Base Temp %f",(frontleft.temperature(vex::percentUnits::pct)+midleft.temperature(vex::percentUnits::pct)+midright.temperature(vex::percentUnits::pct)+frontright.temperature(vex::percentUnits::pct))/4);

    cata_run(spd_pct);
    
    
   

    int Ax3 = (H.Axis3.value()/(127/12))*spd_pct;
    int Ax2 = (H.Axis2.value()/(127/12))*spd_pct;
    pure_chasis_move(Ax3,Ax2);
    if(H.ButtonR1.pressing()== 1){

      intake.spin(forward, 12, vex::voltageUnits::volt);
    }
    else if (H.ButtonR2.pressing() == 1){
      intake.spin(reverse, 12 ,vex::voltageUnits::volt);
    }
    else{
      intake.stop();
    }
    

    if(H.ButtonB.pressing() == 1){

     Expansion_out.set(true);


    }
    else{

      Expansion_out.set(false);
    }

    if(H.ButtonA.pressing()==1){


          DigitalOutB.set(true);


    }
    else{
      DigitalOutB.set(false);
    }
    if(H.ButtonX.pressing() == 1){

     DigitalOutE.set(true);
     DigitalOutF.set(false);
    }
    else{
     DigitalOutE.set(false);
     DigitalOutF.set(false);
    }
    if(H.ButtonY.pressing() == 1 ){
     cat_test.spin(reverse, 12 , vex::voltageUnits::volt);
     vex::task::sleep(65);
     cat_test.spin(reverse , 0 , vex::voltageUnits::volt);

    }

    else{
     cat_test.spin(forward,0,vex::voltageUnits::volt);

    }

  }




void iner_turn(float target, float speed){
 
   float headin = inertial_sensor.heading(degrees);
   while (headin < target){
     Brain.Screen.clearScreen();
     tank_right(speed);
     headin = inertial_sensor.heading(degrees);
     Brain.Screen.print(headin);
     vex::task::sleep(20);


   }
   hold_base();
   task::sleep(0);
   move_base(0);



}


void advturnright(float degr, int speed, int slwspeed){
 Brain.Screen.clearScreen();
 Brain.Screen.setCursor(1,1);
  float val = 0;
float slwdist =  degr/6.5;
int run = 1;




while (run == 1){

Brain.Screen.clearScreen();
 val = 360 - inertial_sensor.heading(degrees);
Brain.Screen.print(val);
vex::task::sleep(20);

 if(val< degr - slwdist  ){
       
       tank_left(speed);
       
     
      

 }

   else if(val >  degr - slwdist && val < degr ){


   
      tank_left(slwspeed);
     
    
     

 }

 else if(val > degr){

      tank_left(-slwspeed);
    
       
    
 }
 else if(val == degr){

   run = 0;
   Brain.Screen.print("Exit");

  
 }

}
  Brain.Screen.clearScreen();
  move_base(0);
  


  Brain.Screen.print("5");


}


void turnrightmk2(float target, float speed, float slwspeed){


 
 float sens_val = inertial_sensor.heading(degrees);
 float Mtarget = target;
 float slwdist = target/6.5;

 while ( Mtarget > inertial_sensor.heading(degrees)){
    sens_val = inertial_sensor.heading(degrees);

      tank_right(speed);

  

 }

 move_base(0);


}


void turnleftmk2(float target, float speed, float slwspeed){


 
 float sens_val = inertial_sensor.heading(degrees);
 float Mtarget = 360 - target;
 float slwdist = target/6.5;

 while ( 360 - Mtarget > inertial_sensor.heading(degrees)){
    sens_val = inertial_sensor.heading(degrees);

      tank_right(speed);

  

 }

 move_base(0);


}


void inertia_turn_2(float dist, int speed){
   float sens_val =  inertial_sensor.heading(degrees);
   float terror =  dist - sens_val;
   if (terror > 0){
     while(terror < 0){
       sens_val =  inertial_sensor.heading(degrees);
        tank_left(speed);

     }
    move_base(0);
   }
   else if (terror < 0){
     while(terror > 0){
       sens_val =  inertial_sensor.heading(degrees);

       tank_right(speed);
     }
    move_base(0);

   }

}

void advturnleftmk2(float target, float speed, float slwspeed){


 
 float sens_val = inertial_sensor.heading(degrees);
 float Mtarget = target;
 float slwdist = target/6.5;

 while ( Mtarget < inertial_sensor.heading(degrees)){
    sens_val = inertial_sensor.heading(degrees);

      tank_right(speed);

  

 }

 move_base(0);


}


void move_intake(int duration, float speed){
  intake.spin(forward, speed,vex::voltageUnits::volt);
  vex::task::sleep(duration);
  intake.spin(forward,0,vex::voltageUnits::volt);


}

void start_program(){
  
   inertial_sensor.calibrate();
   back_X_rotation.resetPosition();
   while (inertial_sensor.isCalibrating()){
     vex::task::sleep(5);

     Brain.Screen.print("calibrating");
   }
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();
   
   vex::task::sleep(20);

 
    float speed_change_zone = 150.75;

  
     float rotate_val = cata_rotate.angle(degrees);
      while(rotate_val  < speed_change_zone){
      
      rotate_val =  cata_rotate.angle(degrees);
      cat_test.spin(reverse, 12, vex::voltageUnits::volt);
      


      }
   
       cat_test.spin(forward, 0, vex::voltageUnits::volt);
       intake.spin(reverse, 12, vex::voltageUnits::volt);
       base_left(-5);
       vex::task::sleep(470);

       intake.stop();
       
      

  

}

void reset(int duration, float speed){

  move_base(-speed);
  vex::task::sleep(duration);
  move_base(0);



}





void adv_turn_left(float target, float speed, float slwspeed){

  inertial_sensor.resetHeading();
  double error = 0;
  
  bool run = true;
  float slwdist =  target/5;
  while(run == true){
    Brain.Screen.clearLine();
    Brain.Screen.print(inertial_sensor.heading(degrees));
    error = target - (360 - inertial_sensor.heading(degrees));
    Brain.Screen.setCursor(4,1);
    Brain.Screen.print(error);
    
    if(target-slwdist >= error ) 
    {
     tank_left(speed);
     error = target - (360 - inertial_sensor.heading(degrees));

    }
    else if(target >= error && target-slwdist <= error ){

      tank_left(slwspeed);
      error = target - (360 - inertial_sensor.heading(degrees));
    }
    else if(target < error){
      tank_left(-slwspeed);
       error = target - (360 - inertial_sensor.heading(degrees));

    }
    else if(target == error ){
      move_base(0);
      run = false;
    }

  }
  hold_base();
  task::sleep(40);
  move_base(0);


}

void PID_base_fwd( float target, int max_speed){
   Brain.Screen.clearLine();
   double Kp =  2.5;
   double Ki  = 0.01;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;
   float speed;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();

   double joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;

   double joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev)))/3;
   double joint_sensor = (joint_right + joint_left)/2;
  
   
 
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);
    


     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }    
     derivative =error - previous_error;
     previous_error = error;
     joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
     joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev)))/3;
     joint_sensor = (joint_right + joint_left)/2;
     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;
     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 1.5){
       speed = 1.5;

     }

     move_base(speed);
     
     vex::task::sleep(40);
     
     

   }
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();
move_base(0);

  
}


void adv_PID_base_fwd( float target, int max_speed){
   Brain.Screen.clearLine();
   double Kp =  2.5;
   double Ki  = 0.01;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double decrease_spd_correction_constant = 0.25;
   double correctional_spd;
   float speed;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();

   double joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   double joint_sensor = (joint_right + joint_left)/2;
  
  
   
 
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     previous_error = error;
     joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
     joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev)))/3;
     joint_sensor = (joint_right + joint_left)/2;
     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 1.5){
       speed = 1.5;

     }
    

     if(joint_right > joint_left){

          
          correctional_spd = speed - (decrease_spd_correction_constant * (joint_right - joint_left));   
          
          chasis_move(speed,correctional_spd);
          Brain.Screen.setCursor(14,1);
          Brain.Screen.print("HERE1");


     }
     else if (joint_left> joint_right){

          correctional_spd = speed - (decrease_spd_correction_constant * (joint_left - joint_right));  
          
          chasis_move(correctional_spd,speed);
          Brain.Screen.setCursor(14,1);
          Brain.Screen.print("HERE2");
        


     }
     else if(joint_right == joint_left){
       move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Fwd");
     }
     else{

          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Here1");  
     }
     vex::task::sleep(40);
     
     

   }
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();
   move_base(0);

  
}


void shoot(){
     float speed_change_zone = 144.15;

  
     float rotate_val = cata_rotate.angle(degrees);
     cat_test.spin(reverse, 6.75, vex::voltageUnits::volt);
     vex::task::sleep(450);
     cat_test.spin(reverse, 0, vex::voltageUnits::volt);
     vex::task::sleep(50);
     rotate_val = cata_rotate.angle(degrees);
     while(rotate_val  >= speed_change_zone){
      
       rotate_val =  cata_rotate.angle(degrees);
       cat_test.spin(reverse, 12, vex::voltageUnits::volt);
      


      }
   
       cat_test.spin(forward, 0, vex::voltageUnits::volt);

}


void limitswitch_shoot(float spd_pct){
  if(H.ButtonL1.pressing() ==  1){
  cat_test.spin(reverse, 5.95, vex::voltageUnits::volt);
  vex::task::sleep(420);
  cat_test.spin(reverse, 0, vex::voltageUnits::volt);
  vex::task::sleep(100);
  while(Limitswitch_cata.pressing() == 0){
        frontleft.spin(forward,(H.Axis3.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    midleft.spin(forward,(H.Axis3.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    backleft.spin(forward,(H.Axis3.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    frontright.spin(forward,(H.Axis2.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    midright.spin(forward,(H.Axis2.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    backright.spin(forward,(H.Axis2.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
       intake.spin(reverse,(V.Axis2.value())*(127/12), vex::voltageUnits::volt);  
    cat_test.spin(reverse, 12, vex::voltageUnits::volt);
    
  }

  cat_test.stop(hold);
  }


}


void limitswitch_boostedshoot(float spd_pct){
  if(H.ButtonL2.pressing() ==  1){
     cat_test.spin(reverse, 5.95, vex::voltageUnits::volt);
     vex::task::sleep(210);
     DigitalOutA.set(true);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(true);
     vex::task::sleep(190);
     cat_test.stop(hold);
     DigitalOutA.set(false);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(false);
  while(Limitswitch_cata.pressing() == 0){
        frontleft.spin(forward,(H.Axis3.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    midleft.spin(forward,(H.Axis3.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    backleft.spin(forward,(H.Axis3.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    frontright.spin(forward,(H.Axis2.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    midright.spin(forward,(H.Axis2.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
    backright.spin(forward,(H.Axis2.value()/(127/12))*spd_pct,vex::voltageUnits::volt);
       intake.spin(reverse,(V.Axis2.value())*(127/12), vex::voltageUnits::volt);  
    cat_test.spin(reverse, 12, vex::voltageUnits::volt);
    
  }

  cat_test.stop(hold);
  }


}


void boosted_shoot(float fwdspd, int waitime){
       float speed_change_zone = 145.89;
  
     float rotate_val = cata_rotate.angle(degrees);


    cat_test.spin(reverse, 0, vex::voltageUnits::volt);
     DigitalOutA.set(false);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(false);

  
     rotate_val = cata_rotate.angle(degrees);
     timer breaker;
     cat_test.spin(reverse, 12, vex::voltageUnits::volt);
     vex::task::sleep(waitime);
     true_move_base(fwdspd);
     DigitalOutA.set(true);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(true);
     vex::task::sleep(160);
     cat_test.stop(hold);
     DigitalOutA.set(false);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(false);
     move_base(0);
     hold_base();
     move_base(0);
     vex::task::sleep(200);
     Brain.Screen.print(rotate_val);
     rotate_val = cata_rotate.angle(degrees);
   while(rotate_val  >= speed_change_zone){
      rotate_val =  cata_rotate.angle(degrees);
       Brain.Screen.clearLine();
       Brain.Screen.print(rotate_val);
       intake.spin(reverse,(V.Axis2.value())*(127/12), vex::voltageUnits::volt);  
       cat_test.spin(reverse,12 , vex::voltageUnits::volt);
      }
   
       cat_test.stop();


  
}


void boosted_shoot_illegal(float fwdspd){
     DigitalOutA.set(false);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(false);
     float speed_change_zone = 145.75;
  
     float rotate_val = cata_rotate.angle(degrees);
     timer breaker;


     cat_test.spin(reverse, 5.95, vex::voltageUnits::volt);
     vex::task::sleep(215);
     true_move_base(fwdspd);
     DigitalOutA.set(true);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(true);
     vex::task::sleep(200);

     cat_test.spin(forward,0,volt);
     DigitalOutA.set(false);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(false);
     move_base(0);
     hold_base();
     move_base(0);
     vex::task::sleep(300);
     
     
    while(rotate_val >=  speed_change_zone){
      cat_test.spin(reverse, 12, vex::voltageUnits::volt);

    }
    cat_test.spin(reverse, 0, vex::voltageUnits::volt);

  
}



void boosted_shoot_illegal2(float fwdspd){
     DigitalOutA.set(false);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(false);
     float speed_change_zone = 146.75;
  
     float rotate_val = cata_rotate.angle(degrees);
     timer breaker;
     cat_test.spin(reverse, 6.35, vex::voltageUnits::volt);
     vex::task::sleep(180);
     true_move_base(fwdspd);
     DigitalOutA.set(true);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(true);
     vex::task::sleep(200);

     cat_test.spin(forward,0,volt);
     DigitalOutA.set(false);
     DigitalOutB.set(false);
     DigitalOutC.set(false);
     DigitalOutD.set(false);
     move_base(0);
     hold_base();
     move_base(0);
     vex::task::sleep(300);
     rotate_val = cata_rotate.angle(degrees);
    while(rotate_val >=  speed_change_zone){
      cat_test.spin(reverse, 12, vex::voltageUnits::volt);

    }
    cat_test.spin(reverse, 0, vex::voltageUnits::volt);
      cat_test.stop(hold);
      cat_test.spin(forward, 0, vex::voltageUnits::volt);

    cat_test.spin(reverse, 0, vex::voltageUnits::volt);
  
}

void shootfwd(){
     float speed_change_zone = 152;

  
     float rotate_val = cata_rotate.angle(degrees);
     cat_test.spin(reverse, 6.75, vex::voltageUnits::volt);
     move_base(5.8);
     vex::task::sleep(450);
     move_base(0);
     cat_test.spin(reverse, 0, vex::voltageUnits::volt);
     vex::task::sleep(70);
     rotate_val = cata_rotate.angle(degrees);
     
     while(rotate_val  < speed_change_zone){
      
       rotate_val =  cata_rotate.angle(degrees);
       cat_test.spin(reverse, 12, vex::voltageUnits::volt);
      


      }
   
       cat_test.spin(forward, 0, vex::voltageUnits::volt);




}





void PID_Match_load(float target,float max_speed){

  Brain.Screen.clearLine();

   double Kp =  2.5;
   double Ki  = 0.61;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;

   double correctional_spd;

   float speed;
   double joint_left;
   double joint_right;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();

   double Cjoint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double Cjoint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   double joint_sensor = (Cjoint_right + Cjoint_left)/2;
   double joint_base = joint_sensor;
   double joint_val = joint_sensor - joint_base;
   double slw_speed;

  
  
   
 
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     
     previous_error = error;
     joint_right = (inch_to_rev(midright.rotation(rev) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev))))/3 - Cjoint_right;
     joint_left = ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev))))/3 - Cjoint_left;
     joint_sensor = (joint_right - joint_left)/2;
     if(joint_sensor <0 ){
       joint_sensor = -joint_sensor;
     }

     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;
     slw_speed =  speed * 0.45;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 1.5){
       speed = 1.5;

     }
     chasis_move( speed,-slw_speed);
    
     

     vex::task::sleep(40);
     
     

   }

   move_base(0);


}

void PID_Match_load_CB(float target,float max_speed){

  Brain.Screen.clearLine();

   double Kp =  2.5;
   double Ki  = 0.61;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;

   double correctional_spd;

   float speed;
   double joint_left;
   double joint_right;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();

   double Cjoint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double Cjoint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   double joint_sensor = (Cjoint_right + Cjoint_left)/2;
   double joint_base = joint_sensor;
   double joint_val = joint_sensor - joint_base;
   double slw_speed;

  
  
  
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     
     previous_error = error;
     joint_right = (inch_to_rev(midright.rotation(rev) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev))))/3 - Cjoint_right;
     joint_left = ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev))))/3 - Cjoint_left;
     joint_sensor = (joint_right - joint_left)/2;
     if(joint_sensor <0 ){
       joint_sensor = -joint_sensor;
     }

     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;
     slw_speed =  speed * 0.45;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 2){
       speed = 2;

     }

     chasis_move( -speed, slw_speed);
    
     

     vex::task::sleep(40);
     
     

   }

   move_base(0);


}

void PID_roller(float target,float max_speed){

  Brain.Screen.clearLine();

   double Kp =  2.5;
   double Ki  = 0.61;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;

   double correctional_spd;

   float speed;
   double joint_left;
   double joint_right;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();

   double Cjoint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double Cjoint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   double joint_sensor = (Cjoint_right + Cjoint_left)/2;
   double joint_base = joint_sensor;
   double joint_val = joint_sensor - joint_base;
   double slw_speed;

  
  
  
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     
     previous_error = error;
     joint_right = (inch_to_rev(midright.rotation(rev) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev))))/3 - Cjoint_right;
     joint_left = ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev))))/3 - Cjoint_left;
     joint_sensor = (joint_right - joint_left)/2;
     if(joint_sensor <0 ){
       joint_sensor = -joint_sensor;
     }

     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;
     slw_speed =  speed * 0.15;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 2 && speed > 0){
       speed = 2;

     }

     chasis_move( slw_speed, -speed);
    
     

     vex::task::sleep(40);
     
     

   }

   move_base(0);


}


void adv_PID_base_rev(float target, int max_speed)
{
  Brain.Screen.clearLine();
   double allowance = 0.1;
   double Kp =  2.5;
   double Ki  = 0.01;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double prev_turn_error;
   double decrease_spd_correction_constant = 0.07;
   double correctional_error = 0;
   double turn_derivative;
   double turn_integral;
   double correctional_spd;
   double Tkd = 1.2;
   double Tki = 0.85;
   float speed;
   double joint_left;
   double joint_right;
   float rotate_val;
   float speed_change_zone = 1.15;


   double Cjoint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double Cjoint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   joint_left = ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3) - Cjoint_left;
   joint_right = ((inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3) - Cjoint_left;
   double joint_sensor =  (joint_left + joint_right)/2;
  
  
   
 
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("REV");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);
     rotate_val = cata_rotate.angle(degrees);


     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     
     previous_error = error;
     joint_left = ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3) - Cjoint_left;
     joint_right = ((inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3) - Cjoint_left;
     joint_sensor = (joint_right + joint_left)/2;
     if (joint_sensor < 0){
       joint_sensor = -joint_sensor;
     }

     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;
     

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 1.5){
       speed = 1.5;

     }
     move_base(-speed);
   
    
     

     vex::task::sleep(40);
     
     

   }

   move_base(0);





}
//Use this
void adv_PID_base_fwdMk1( float target, int max_speed){
   Brain.Screen.clearLine();
   double allowance = 0.01;
   double Kp =  2.5;
   double Ki  = 0.01;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double prev_turn_error;
   double decrease_spd_correction_constant = 0.01;
   double correctional_error = 0;
   double turn_derivative;
   double turn_integral;
   double correctional_spd;
   double Tkd = 0.04;
   double Tki = 0.1;
   float speed;
   double joint_left;
   double joint_right;
   bool reached = false;
   double Nerror;




   double Cjoint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double Cjoint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();
   joint_left =  ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3) - Cjoint_left;
   joint_right = ((inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3) - Cjoint_right;
   double joint_sensor = (Cjoint_right + Cjoint_left)/2;


  
  
   
 
   error = target - joint_sensor;
   if (error == 0){
     reached = true;
   }
   
   
   while (reached == false ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     //Calculate derivative
     derivative =error - previous_error;
     
     
     previous_error = error;
    joint_left =  ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3) - Cjoint_left;
    joint_right = ((inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3) - Cjoint_right;
     joint_sensor = (joint_right + joint_left)/2;
     //Update Error
     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;

     if (speed >= max_speed){
       speed = max_speed;
     }
     //Temporary bugfix were bot will get stucked moving too slowly. Can remove if no longer needed.
     else if(speed < 1.5 && speed > 0){
       speed = 1.5;

     }
    
     //Allowance to allow some level of "wrongness" so it dosen't try and auto correct everything
     //Checks if right side if faster or left side is faster
     if(joint_right > joint_left + allowance){
       //PID logic here
          prev_turn_error = correctional_error;
          correctional_error =  joint_right - joint_left;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
       //Speed calculations to slow down proportionally. Can be improved
          correctional_spd = speed * (1 -(0.01 *(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral))));   
          if(correctional_spd < 0){
            correctional_spd = speed * 0.8;
          } 
          chasis_move(speed,correctional_spd);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));


     }
     else if (joint_left > joint_right + allowance){

          prev_turn_error = correctional_error;
          correctional_error =  joint_left - joint_right;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed * (1 - (0.01  * (decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral))));
          if(correctional_spd < 0){
            correctional_spd = speed * 0.8;
          }     
          
          chasis_move(correctional_spd,speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));
      
     }
     else if(joint_left < joint_right + allowance && joint_right < joint_left + allowance ){
       //If both sides + allowance is equal.
          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Fwd");
     }
     else{

          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Here1");  
     }
     Nerror = target - joint_sensor;
     if (Nerror == 0){
       reached = true;
     }
     vex::task::sleep(20);
     
     
     

   }

   move_base(0);

  
}

void adv_PID_base_fwdMk2( float target, int max_speed){
   Brain.Screen.clearLine();
   double allowance = 0.1;
   double Kp =  2.5;
   double Ki  = 0.01;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double prev_turn_error;
   double decrease_spd_correction_constant = 0.07;
   double correctional_error = 0;
   double turn_derivative;
   double turn_integral;
   double correctional_spd;
   double Tkd = 1.2;
   double Tki = 0.85;
   float speed;
   double joint_left;
   double joint_right;


   double Cjoint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double Cjoint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   joint_left =  ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3) - Cjoint_left;
   joint_right = ((inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3) - Cjoint_right;
   double joint_sensor = (Cjoint_right + Cjoint_left)/2;


  
  
   
 
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     
     previous_error = error;
    joint_left =  ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3) - Cjoint_left;
    joint_right = ((inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3) - Cjoint_right;
     joint_sensor = (joint_right + joint_left)/2;

     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 1.5 && speed > 0){
       speed = 1.5;

     }
    
     
     if(joint_right > joint_left + allowance){
          prev_turn_error = correctional_error;
          correctional_error =  joint_right - joint_left;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed * (1 -(0.01 *(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral))));   
          if(correctional_spd < 0){
            correctional_spd = speed * 0.8;
          } 
          chasis_move(speed,correctional_spd);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));


     }
     else if (joint_left > joint_right + allowance){

          prev_turn_error = correctional_error;
          correctional_error =  joint_left - joint_right;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed * (1 - (0.01  * (decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral))));
          if(correctional_spd < 0){
            correctional_spd = speed * 0.8;
          }     
          
          chasis_move(correctional_spd,speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));
      
     }
     else if(joint_left < joint_right + allowance && joint_right < joint_left + allowance ){
          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Fwd");
     }
     else{

          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Here1");  
     }
     vex::task::sleep(40);
     
       }
   move_base(0);

  
}


void adv_PID_base_fwd_heading_correction( double target, float max_speed, float selected_heading, float heading_speed){
   Brain.Screen.clearLine();
   double allowance = 0.1;
   double Kp =  2.5;
   double Ki  = 0.01;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double prev_turn_error;
   double decrease_spd_correction_constant = 0.07;
   double correctional_error = 0;
   double turn_derivative;
   double turn_integral;
   double correctional_spd;
   double Tkd = 1.2;
   double Tki = 0.7;
   float speed;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();

   double joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   double joint_sensor = (joint_right + joint_left)/2;
  
  
   
 
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     
     previous_error = error;
     joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
     joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev)))/3;
     joint_sensor = (joint_right + joint_left)/2;
     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 1.5 && speed > 0){
       speed = 1.5;

     }
    
     
     if(joint_right > joint_left + allowance){
          prev_turn_error = correctional_error;
          correctional_error =  joint_right - joint_left;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed * (1 -(0.01 *(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral))));   
          if(correctional_spd < 0){
            correctional_spd = speed * 0.8;
          } 
          chasis_move(speed,correctional_spd);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));


     }
     else if (joint_left > joint_right + allowance){

          prev_turn_error = correctional_error;
          correctional_error =  joint_left - joint_right;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed * (1 - (0.01  * (decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral))));
          if(correctional_spd < 0){
            correctional_spd = speed * 0.8;
          }     
          
          chasis_move(correctional_spd,speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));
      
     }
     else if(joint_left < joint_right + allowance && joint_right < joint_left + allowance ){
          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Fwd");
     }
     else{

          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Here1");  
     }
     vex::task::sleep(40);
     
   }
     int iner_sens =  inertial_sensor.heading(degrees);
     int tur_error = selected_heading - iner_sens;
     if(0 > tur_error ){
       while(tur_error < 0 )
       {
         iner_sens =  inertial_sensor.heading(degrees);
         tur_error = selected_heading - iner_sens;
         tank_left(heading_speed);
       }
       move_base(0);


     }
     else if(0 < tur_error){
       while(tur_error > 0){
        iner_sens =  inertial_sensor.heading(degrees);
         tur_error = selected_heading - iner_sens;
         tank_right(heading_speed);
       }
       move_base(0);

     }
     else{

     }




   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();
   move_base(0);

  
}


void pure_disc_dogshit(float target, float max_speed){

  
  Brain.Screen.clearLine();

   double Kp =  2.5;
   double Ki  = 0.61;
   double Kd = 2.1;
   double error;
   double integral;
   double derivative;
   double previous_error;

   double correctional_spd;

   float speed;
   double joint_left;
   double joint_right;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();

   double Cjoint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double Cjoint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   double joint_sensor = (Cjoint_right + Cjoint_left)/2;
   double joint_base = joint_sensor;
   double joint_val = joint_sensor - joint_base;
   double slw_speed;

  
  
  
   error = target - joint_sensor;
   
   
   while (error > 0 ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     
     previous_error = error;
     joint_right = (inch_to_rev(midright.rotation(rev) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev))))/3 - Cjoint_right;
     joint_left = ((inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev))))/3 - Cjoint_left;
     joint_sensor = (joint_right - joint_left)/2;
     if(joint_sensor <0 ){
       joint_sensor = -joint_sensor;
     }

     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;
     slw_speed =  speed * 0.25;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 2 && speed > 0){
       speed = 2;

     }

     chasis_move( -slw_speed, speed);
    
     

     vex::task::sleep(40);
     
     

   }

   move_base(0);


  
}
void PID_turn(float selected_heading, float heading_speed){
   Brain.Screen.clearLine();

   float robot_heading;
   double ftkp = 0.5;
   double ftkd = 0.14;
   double ftki = 0.9;
   float Tspeed;
   float Tprev_error;
   double Fturn_derivative;
   double Fturn_integral;
   bool left;
   int ange2 = 0;
    
     
     robot_heading = inertial_sensor.heading(degrees);


            if(selected_heading > robot_heading){
              ange2 = selected_heading - robot_heading;
              left = false;


            }
            else if(selected_heading < robot_heading){
              ange2=  robot_heading - selected_heading;
              left = true;
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              left = !left;

            }
           
          
          while(ange2 > 0){
               robot_heading = inertial_sensor.heading(degrees);
                           if(selected_heading > robot_heading){
              ange2 = selected_heading - robot_heading;
              

            }
            else if(selected_heading < robot_heading){
              ange2=  robot_heading - selected_heading;
              
            }
               
               Brain.Screen.setCursor(1,1);
               Brain.Screen.print("Ange2:");
               Brain.Screen.setCursor(1,4);
               Brain.Screen.print(ange2);
               Brain.Screen.setCursor(3,1);
               Brain.Screen.print("Speed");
               Brain.Screen.setCursor(3,5);
               Brain.Screen.print(Tspeed);
 
              //adjust to heading

        if (left == true){
                   Tprev_error = ange2;
             
           
            if(selected_heading > robot_heading){
              ange2 = selected_heading - robot_heading;
              


            }
            else if(selected_heading < robot_heading){
              ange2=  robot_heading - selected_heading;
            
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              

            }

           if (ange2 < 0){
                    ange2 =  360 + ange2;
                }
                Fturn_derivative = ange2 - Tprev_error;              
                Fturn_integral = Fturn_integral + ange2;
                Tspeed = ftkp*ange2 + ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >heading_speed){
                     Tspeed = heading_speed;
                   }
                   else if(Tspeed < 2 && Tspeed > 0 ){
                     Tspeed = 2;
                   }
                   tank_left(Tspeed);     

            }
         else if(left == false){
                   Tprev_error = ange2;
  

            if(selected_heading > robot_heading){
              ange2 = selected_heading - robot_heading;
              


            }
            else if(selected_heading < robot_heading){
              ange2=  robot_heading - selected_heading;
            
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              

            }

            
             if (ange2 < 0){
                     ange2 =  360 + ange2;
                   }
            Fturn_derivative =ange2 - Tprev_error;              
             Fturn_integral = Fturn_integral + ange2;
             Tspeed = ftkp*ange2 + ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >heading_speed){
                     Tspeed = heading_speed;
                   }
                   else if(Tspeed < 2 && Tspeed > 0){
                     Tspeed = 2;
                   }
                   tank_right(Tspeed);
               }


       }
    move_base(0);

}

void PID_movement_W_heading(double target, float max_speed, float selected_heading, float heading_speed){
  //Moves to target then turns to angle 
  
   Brain.Screen.clearLine();
   double allowance = 0.35;
   double Kp =  2.5;
   double Ki  = 0.01;
   double Kd = 2.1;
   double Nerror;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double prev_turn_error;
   double decrease_spd_correction_constant = 0.0002;
   double correctional_error = 0;
   double turn_derivative;
   double turn_integral;
   double correctional_spd;
   double Tkd = 1.2;
   double Tki = 0.7;
   float robot_heading;
   double ftkp = 0.3;
   double ftkd = 0.08;
   double ftki = 0.2;
   float Tspeed;
   float Tprev_error;
   double Fturn_derivative;
   double Fturn_integral;
   bool left = true;
   float speed;
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();

   double joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
   double joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev) + inch_to_rev(backleft.rotation(rev))))/3;
   double joint_sensor = (joint_right + joint_left)/2;
  
  
   
 
   error = target - joint_sensor;
   
   bool reached = false;
   if (error == 0 ){
     reached = true;
   }
   
   timer end;
   int maxtime = target*10*max_speed;
   while (reached == false || end < maxtime ){
     correctional_spd = speed;
     Brain.Screen.clearScreen();
     Brain.Screen.setCursor(1, 1); 
     Brain.Screen.print("error");
     Brain.Screen.setCursor(1,5);
     Brain.Screen.print(error);
     Brain.Screen.setCursor(2,1); 
     Brain.Screen.print("int");
     Brain.Screen.setCursor(2,5);
     Brain.Screen.print(integral);
     Brain.Screen.setCursor(4,1); 
     Brain.Screen.print("der");
     Brain.Screen.setCursor(4,5);
     Brain.Screen.print(derivative);   
     Brain.Screen.setCursor(6,1); 
     Brain.Screen.print("Speed");
     Brain.Screen.setCursor(6,5);
     Brain.Screen.print(speed);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);

     
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     derivative =error - previous_error;
     
     previous_error = error;
     joint_right = (inch_to_rev(midright.rotation(rev)) + inch_to_rev(frontright.rotation(rev)) + inch_to_rev(backright.rotation(rev)))/3;
     joint_left = (inch_to_rev(midleft.rotation(rev)) + inch_to_rev(frontleft.rotation(rev)) + inch_to_rev(backleft.rotation(rev)))/3;
     joint_sensor = (joint_right + joint_left)/2;
     error =  target - joint_sensor;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 2 && speed > 0){
       speed = 3;

     }
    
     
     if(joint_right > joint_left + allowance){
          prev_turn_error = correctional_error;
          correctional_error =  joint_right - joint_left;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed * (1 -(0.01 *(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral))));   
          if(correctional_spd < 0){
            correctional_spd = speed * 0.8;
          } 
          chasis_move(speed,correctional_spd);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));


     }
     else if (joint_left > joint_right + allowance){

          prev_turn_error = correctional_error;
          correctional_error =  joint_left - joint_right;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed * (1 - (0.01  * (decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral))));
          if(correctional_spd < 0){
            correctional_spd = speed * 0.8;
          }     
          
          chasis_move(correctional_spd,speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));
      
     }
     else if(joint_left < joint_right + allowance && joint_right < joint_left + allowance ){
          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Fwd");
     }
     else{

          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Here1");  
     }
     
     
     Nerror = target - joint_sensor;
     if(error == 0){
       reached = true;
     }

     vex::task::sleep(10);
     
   }
   move_base(0);
   vex::task::sleep(30);
     int ange2 = 0;
     //Final turning part
     robot_heading = inertial_sensor.heading(degrees);

     if(selected_heading != robot_heading){
       

  //Calculations to see if right or left is faster relative to it's angle atm         
            if(selected_heading > robot_heading){
              ange2 = selected_heading - robot_heading;
              left = false;


            }
            else if(selected_heading < robot_heading){
              ange2=  robot_heading - selected_heading;
              left = true;
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              left = !left;

            }
           
          
          while(ange2 > 0){
               robot_heading = inertial_sensor.heading(degrees);
                ange2 = selected_heading - robot_heading;
               Brain.Screen.setCursor(1,1);
               Brain.Screen.print("Ange2:");
               Brain.Screen.setCursor(1,4);
               Brain.Screen.print(ange2);
               Brain.Screen.setCursor(3,1);
               Brain.Screen.print("Speed");
               Brain.Screen.setCursor(3,5);
               Brain.Screen.print(Tspeed);
 
              //adjust to heading

        if (left == true){
                   Tprev_error = ange2;
             
           //Continous calculations inside while loop to update information
            if(selected_heading > robot_heading){
              ange2 = selected_heading - robot_heading;
              


            }
            else if(selected_heading < robot_heading){
              ange2=  robot_heading - selected_heading;
            
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              

            }

           if (ange2 < 0){
                    ange2 =  360 + ange2;
                }
          //PID speed calc
                Fturn_derivative = ange2 - Tprev_error;              
                Fturn_integral = Fturn_integral + ange2;
                Tspeed = ftkp*ange2 + ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >heading_speed){
                     Tspeed = heading_speed;
                   }
                   else if(Tspeed < 2 && Tspeed > 0){
                     Tspeed = 2;
                   }
                   tank_left(Tspeed);     

            }
         else if(left == false){
                   Tprev_error = ange2;
  

            if(selected_heading > robot_heading){
              ange2 = selected_heading - robot_heading;
              


            }
            else if(selected_heading < robot_heading){
              ange2=  robot_heading - selected_heading;
            
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              

            }

            
             if (ange2 < 0){
                     ange2 =  360 + ange2;
                   }
                   Fturn_derivative =ange2 - Tprev_error;              
                   Fturn_integral = Fturn_integral + ange2;
                   Tspeed = ftkp*ange2 + ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >heading_speed){
                     Tspeed = heading_speed;
                   }
                   else if(Tspeed < 2  && Tspeed > 0){
                     Tspeed = 2;
                   }
                   tank_right(Tspeed);
               }
            }
     }
   

   move_base(0);
   frontleft.resetRotation();
   frontright.resetRotation();
   midleft.resetRotation();
   midright.resetRotation();
   backleft.resetRotation();
   backright.resetRotation();
   

     

}

int odomerty_positioning_system_X_Y(){
  double X_cor;
  double Y_cor;
  float center_to_left_track_wheel = 7.5;
  float center_to_right_track_wheel = 7.5;
  float center_to_back_track_wheel = 7.5;
  double center_to_inner_track_wheel;
  double center_to_outer_track_wheel;
  float global_prev_vector;
  float global_prev_orientation;
  float global_orientation_bef_reset;
  float radius;
  float deltaL;
  float theta;

  double joint_left = inch_to_rev(midleft.position(rev));
  double joint_right = inch_to_rev(midright.position(rev));
  double back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev));
  double joint_sensor = (joint_right + joint_left)/2;
  double inner_sensor;
  double outer_sensor;
  Brain.Screen.clearScreen();
  if (joint_left > joint_right){
    outer_sensor =  joint_left;
    inner_sensor =  joint_right;
    center_to_inner_track_wheel =center_to_left_track_wheel;
    center_to_outer_track_wheel = center_to_right_track_wheel;

  }
  else if (joint_right > joint_left ){

    inner_sensor = joint_left;
    outer_sensor =  joint_right;
    center_to_inner_track_wheel =center_to_right_track_wheel;
    center_to_outer_track_wheel = center_to_left_track_wheel;
  }
    else{
    inner_sensor = joint_left;
    outer_sensor =  joint_right;
    center_to_inner_track_wheel =center_to_right_track_wheel;
    center_to_outer_track_wheel = center_to_left_track_wheel;

  }


  
 
  theta = (outer_sensor - inner_sensor)/(center_to_outer_track_wheel + center_to_inner_track_wheel);
  Y_cor = 2*((inner_sensor/theta) + center_to_inner_track_wheel) * sin(theta/2);
  X_cor = 2*((outer_sensor/theta) + center_to_back_track_wheel)  *  sin(theta/2);
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Y:");
  Brain.Screen.setCursor(1,4);
  Brain.Screen.print(Y_cor);
  Brain.Screen.setCursor(3,1);
  Brain.Screen.print("X:");
  Brain.Screen.setCursor(3,4);
  Brain.Screen.print(X_cor);
  return 0;
  
  
}

//LAPS
void linear_advance_positoning_system(float X_target, float Y_target, int head, float max_speed, float turn_speed){
  //assumes Robot has no obstacles betwen it's current location and its target
  //Single straight line linear movement 
  
  double X_cor;
  double Y_cor;
  float center_to_left_track_wheel = 3;
  float center_to_right_track_wheel = 3;
  float center_to_back_track_wheel = 5.5;
  double center_to_inner_track_wheel;
  double center_to_outer_track_wheel;
  float theta;
  int X_diff;
  int Y_diff;
  double allowance = 0.05;
   double Kp =  0.7;
   double Ki  = 0.01;
   double Kd = 1.4;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double prev_turn_error;
   double decrease_spd_correction_constant = 0.04;
   double correctional_error = 0;
   double turn_derivative;
   double turn_integral;
   double correctional_spd;
   double Tkd = 1.2;
   double Tki = 0.4;
   double ftkp = 0.5;
   double ftkd = 0.14;
   double ftki = 0.9;
   double Fturn_derivative;
   double Fturn_integral;
   float dist_to_cover;
  double Cjoint_left = inch_to_rev(midleft.position(rev));
  double Cjoint_right = inch_to_rev(midright.position(rev));
  double joint_left = Cjoint_left - inch_to_rev(midleft.position(rev));
  double joint_right = Cjoint_right - inch_to_rev(midright.position(rev));
  double back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev));
  double Cjoint =  (Cjoint_right + Cjoint_left)/2;
  double joint_sensor = (joint_right + joint_left)/2;
  double inner_sensor;
  double outer_sensor;
  float speed;
  int target_heading;
  int angle_to_cover;
  float Tspeed;
  
  float Tprev_error;
  
  Brain.Screen.clearScreen();
  if (Cjoint_left > Cjoint_right){
    outer_sensor =  Cjoint_left;
    inner_sensor =  Cjoint_right;
    center_to_inner_track_wheel =center_to_left_track_wheel;
    center_to_outer_track_wheel = center_to_right_track_wheel;

  }
  else if (Cjoint_right > Cjoint_left ){

    inner_sensor = Cjoint_left;
    outer_sensor =  Cjoint_right;
    center_to_inner_track_wheel =center_to_right_track_wheel;
    center_to_outer_track_wheel = center_to_left_track_wheel;
  }
  else{
    inner_sensor = Cjoint_left;
    outer_sensor =  Cjoint_right;
    center_to_inner_track_wheel =center_to_right_track_wheel;
    center_to_outer_track_wheel = center_to_left_track_wheel;

  }
   int robot_heading = inertial_sensor.heading(degrees);
   float Tjoint_left;
   float Tjoint_right;

   theta = (outer_sensor - inner_sensor)/(center_to_outer_track_wheel + center_to_inner_track_wheel);
   Y_cor = 2*((inner_sensor/theta) + center_to_inner_track_wheel) * sin(theta/2);
   X_cor = 2*((outer_sensor/theta) + center_to_back_track_wheel)  *  sin(theta/2);
   //Y_cor = Cjoint*cos(robot_heading);
   //X_cor = Cjoint*sin(robot_heading);
 

  if (X_cor != X_target || Y_target != Y_cor || robot_heading != head){
     
     
       Brain.Screen.clearScreen();
         Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Y:");
         Brain.Screen.setCursor(1,4);
         Brain.Screen.print(Y_cor);
        Brain.Screen.setCursor(3,1);
        Brain.Screen.print("X:");
        Brain.Screen.setCursor(3,4);
        Brain.Screen.print(X_cor);
        Brain.Screen.setCursor(5,1);
        Brain.Screen.print("Heading");
        Brain.Screen.setCursor(5,4);
        Brain.Screen.print(robot_heading);
        vex::task::sleep(2);
        

        joint_left = Cjoint_left;
        joint_right = Cjoint_right;
         
         back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev));
         

          Brain.Screen.clearScreen();
          if (joint_left > joint_right){
               outer_sensor =  joint_left;
               inner_sensor =  joint_right;
               center_to_inner_track_wheel =center_to_left_track_wheel;
               center_to_outer_track_wheel = center_to_right_track_wheel;

                } 
          else if (joint_right > joint_left ){

                 inner_sensor = joint_left;
                 outer_sensor =  joint_right;
                 center_to_inner_track_wheel =center_to_right_track_wheel;
                center_to_outer_track_wheel = center_to_left_track_wheel;
               }
           else{
                   inner_sensor = (joint_left + joint_right)/2;
                   outer_sensor =  (joint_right + joint_left)/2;
                   center_to_inner_track_wheel =center_to_right_track_wheel;
                   center_to_outer_track_wheel = center_to_left_track_wheel;

               }

           theta = (outer_sensor - inner_sensor)/(center_to_outer_track_wheel + center_to_inner_track_wheel);
           if (theta == 0){
             Y_cor = inner_sensor;
             X_cor = back_sen;
           }
           else{
           Y_cor = 2*((inner_sensor/theta) + center_to_inner_track_wheel) * sin(theta/2);
           X_cor = 2*((outer_sensor/theta) + center_to_back_track_wheel)  *  sin(theta/2);
           }
           robot_heading = inertial_sensor.heading(degrees);
            //Cjoint = midleft.rotation(rev) + midright.rotation(rev);
            //Y_cor = Cjoint*cos(robot_heading);
            //X_cor = Cjoint*sin(robot_heading);
            
            bool left = false;
            

            X_diff = X_target - X_cor;
            Y_diff = Y_target - Y_cor;

            Brain.Screen.clearScreen();
            Brain.Screen.setCursor(5,5);
            bool need_turn = true;
            
           
            //This assumes robot is at 0 degree, which is impossible to determin
            //use inertial sensor to factor in robot angle?
            if (Y_diff == 0 || X_diff == 0){

              target_heading = 0;
            }
            else{
            target_heading = atan(Y_diff/X_diff);
            
            }
            int c = 1;
            if (target_heading < 0 ){
              target_heading = -target_heading;
              c = 0;
              
            }


            if (robot_heading > target_heading){
              angle_to_cover = robot_heading - target_heading;
              left = true;
            }
            else if(target_heading > robot_heading){
              angle_to_cover = target_heading - robot_heading;
              left = false;
            }
            else if (target_heading == robot_heading){
              need_turn = false;
              
            }
            if (angle_to_cover > 180){
              angle_to_cover  = 360 - angle_to_cover;
              left = !left;
            }



            if (X_diff < 0){
              X_diff = -X_diff;
            }
            else if (Y_diff < 0 ){
              Y_diff = -Y_diff;
            }
            


            

            
            //pythagoras therom for PID dist
           joint_left = inch_to_rev(midleft.position(rev)) - Cjoint_left;
           joint_right =  inch_to_rev(midright.position(rev)) - Cjoint_right;

           joint_sensor = (joint_right + joint_left)/2;
            dist_to_cover =  sqrt(pow(X_diff,2) + pow(Y_diff,2));
            Brain.Screen.print(dist_to_cover);
            //turn to target 
           
            
            
          if (need_turn !=  false){
            
            while(angle_to_cover > 0){
              robot_heading = inertial_sensor.heading(degrees);
             
              Brain.Screen.setCursor(1,1);
              Brain.Screen.print(angle_to_cover);
              vex::task::sleep(15);
                if (robot_heading >= target_heading){
                    angle_to_cover = robot_heading - target_heading;
                   
                 }
                   else if(target_heading > robot_heading){
                      angle_to_cover = target_heading - robot_heading;
                     
                    }
                 if (angle_to_cover > 180){
                       angle_to_cover  = 360 - angle_to_cover;
                        
                   }

              if (left == true){
                   Tprev_error = angle_to_cover;

   
                          
                        
                   Fturn_derivative =angle_to_cover - Tprev_error;              
                   Fturn_integral = Fturn_integral + angle_to_cover;
                   Tspeed = ftkp*angle_to_cover+ ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >turn_speed){
                     Tspeed = turn_speed;
                   }
                   else if(Tspeed < 1.5){
                     Tspeed = 1.5;
                   }
                   tank_left(Tspeed);     

            }
              else if(left == false){
                   Tprev_error = angle_to_cover;


                    

                   Fturn_derivative =angle_to_cover - Tprev_error;              
                   Fturn_integral = Fturn_integral + angle_to_cover;
                   Tspeed = ftkp*angle_to_cover+ ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >turn_speed){
                     Tspeed = turn_speed;
                   }
                   else if(Tspeed < 1.5){
                     Tspeed = 1.5;
                   }
                   tank_right(Tspeed);
               }
               else{
                 break;
               }
            }
            move_base(0);
            vex::task::sleep(300);
      }

    joint_sensor = 0;   
    error = dist_to_cover - joint_sensor;
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     
     
    while(error > 0){
   
       Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Y:");
        Brain.Screen.setCursor(1,4);
         Brain.Screen.print(Y_cor);
        Brain.Screen.setCursor(3,1);
        Brain.Screen.print("X:");
        Brain.Screen.setCursor(3,4);
        Brain.Screen.print(X_cor);
        Brain.Screen.setCursor(5,1);
        Brain.Screen.print("Heading");
        Brain.Screen.setCursor(5,4);
        Brain.Screen.print(robot_heading);
        vex::task::sleep(40);
        Tjoint_left = Cjoint_left + joint_left;
        Tjoint_right = Cjoint_right  + joint_right;
        back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev));

   
          Brain.Screen.clearScreen();
          if (Tjoint_left > Tjoint_right){
               outer_sensor =  Tjoint_left;
               inner_sensor =  Tjoint_right;
               center_to_inner_track_wheel =center_to_left_track_wheel;
               center_to_outer_track_wheel = center_to_right_track_wheel;

                } 
          else if (Tjoint_right > Tjoint_left ){

                 inner_sensor = Tjoint_left;
                 outer_sensor =  Tjoint_right;
                 center_to_inner_track_wheel =center_to_right_track_wheel;
                center_to_outer_track_wheel = center_to_left_track_wheel;
               }
           else{
                   inner_sensor = (Tjoint_left + Tjoint_right)/2;
                   outer_sensor =  (Tjoint_right + Tjoint_left)/2;
                   center_to_inner_track_wheel =center_to_right_track_wheel;
                   center_to_outer_track_wheel = center_to_left_track_wheel;

               }

           theta = (outer_sensor - inner_sensor)/(center_to_outer_track_wheel + center_to_inner_track_wheel);
           Y_cor = 2*((inner_sensor/theta) + center_to_inner_track_wheel) * sin(theta/2);
           X_cor = 2*((outer_sensor/theta) + center_to_back_track_wheel)  *  sin(theta/2);
            robot_heading = inertial_sensor.heading(degrees);
     Brain.Screen.setCursor(8,1); 
     Brain.Screen.print("Left");
     Brain.Screen.setCursor(8,5);
     Brain.Screen.print(joint_left);
     Brain.Screen.setCursor(10,1); 
     Brain.Screen.print("Right");
     Brain.Screen.setCursor(10,5);
     Brain.Screen.print(joint_right);
     vex::task::sleep(5);
     //Y_cor = (Cjoint_left + joint_left)*cos(robot_heading);
     //X_cor = (Cjoint_right + joint_right)*sin(robot_heading);
  
       //Uses AdvPID to target

     
     
     previous_error = error;
     joint_left =  inch_to_rev(midleft.position(rev)) - Cjoint_left;
     joint_right = inch_to_rev(midright.position(rev)) - Cjoint_right;
     joint_sensor = (joint_right + joint_left)/2;
     error =  dist_to_cover - joint_sensor;
     derivative = error - previous_error;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 3){
       speed = 3;

     }

    
     
     if(joint_right > joint_left + allowance){
          prev_turn_error = correctional_error;
          correctional_error =  joint_right - joint_left;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed - ((decrease_spd_correction_constant *  correctional_error) + (turn_derivative * Tkd) + (Tki * turn_integral));  
          if(correctional_spd < 0 || correctional_spd > speed){
            correctional_spd = speed * 0.8;
          } 
          chasis_move(speed,correctional_spd);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));


     }
     else if (joint_left > joint_right + allowance){

          prev_turn_error = correctional_error;
          correctional_error =  joint_left - joint_right;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed - ((decrease_spd_correction_constant *  correctional_error) + (turn_derivative * Tkd) + (Tki * turn_integral));
          if(correctional_spd < 0 || correctional_spd > speed){
            correctional_spd = speed * 0.8;
          }     

          
          chasis_move(correctional_spd,speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));
      
     }
     else if(joint_left < joint_right + allowance && joint_right < joint_left + allowance ){
          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Fwd");
     }
     else{

          move_base(speed);
          Brain.Screen.setCursor(12,1);
          
     }
     }
            

     move_base(0);
     vex::task::sleep(200);
     int ange2 = 0;
     robot_heading = inertial_sensor.heading(degrees);


            if(head > robot_heading){
              ange2 = head - robot_heading;
              left = false;


            }
            else if(head < robot_heading){
              ange2=  robot_heading - head;
              left = true;
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              left = !left;

            }
           
          
          while(ange2 > 0){
               robot_heading = inertial_sensor.heading(degrees);
                ange2 = head - robot_heading;
               Brain.Screen.setCursor(1,1);
               Brain.Screen.print("Ange2:");
               Brain.Screen.setCursor(1,4);
               Brain.Screen.print(ange2);
               Brain.Screen.setCursor(3,1);
               Brain.Screen.print("Speed");
               Brain.Screen.setCursor(3,5);
               Brain.Screen.print(Tspeed);
 
              //adjust to heading

        if (left == true){
                   Tprev_error = ange2;
             
           
            if(head > robot_heading){
              ange2 = head - robot_heading;
              


            }
            else if(head < robot_heading){
              ange2=  robot_heading - head;
            
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              

            }

           if (ange2 < 0){
                    ange2 =  360 + ange2;
                }
                Fturn_derivative = ange2 - Tprev_error;              
                Fturn_integral = Fturn_integral + ange2;
                Tspeed = ftkp*ange2 + ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >turn_speed){
                     Tspeed = turn_speed;
                   }
                   else if(Tspeed < 2){
                     Tspeed = 2;
                   }
                   tank_left(Tspeed);     

            }
         else if(left == false){
                   Tprev_error = ange2;
  

            if(head > robot_heading){
              ange2 = head - robot_heading;
              


            }
            else if(head < robot_heading){
              ange2=  robot_heading - head;
            
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              

            }

            
                 if (ange2 < 0){
                     ange2 =  360 + ange2;
                   }
                   Fturn_derivative =ange2 - Tprev_error;              
                   Fturn_integral = Fturn_integral + ange2;
                   Tspeed = ftkp*ange2 + ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >turn_speed){
                     Tspeed = turn_speed;
                   }
                   else if(Tspeed < 2){
                     Tspeed = 2;
                   }
                   tank_right(Tspeed);
               }
            }
    move_base(0);



  
    //turn to final heading;
  } 
                  
}

void Odometry_test(){
  double X_cor;
  double Y_cor;
  float center_to_left_track_wheel = 3;
  float center_to_right_track_wheel = 3;
  float center_to_back_track_wheel = 5.5;
  double center_to_inner_track_wheel;
  double center_to_outer_track_wheel;
  float theta;
  int X_diff;
  int Y_diff;
  double allowance = 0.05;
   double Kp =  0.7;
   double Ki  = 0.01;
   double Kd = 1.4;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double prev_turn_error;
   double decrease_spd_correction_constant = 0.04;
   double correctional_error = 0;
   double turn_derivative;
   double turn_integral;
   double correctional_spd;
   double Tkd = 1.2;
   double Tki = 0.4;
   double ftkp = 0.5;
   double ftkd = 0.14;
   double ftki = 0.9;
   double Fturn_derivative;
   double Fturn_integral;
   float dist_to_cover;
  double Cjoint_left = midleft.rotation(rev);
  double Cjoint_right = midright.rotation(rev);
  double Ctheta;
  double Tjoint_left;
  double Tjoint_right;
  double joint_left;
  double joint_right;
  double back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev));
  double Cjoint;
  double joint_sensor;
  double inner_sensor;
  double outer_sensor;
  double Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));
  double Tback_sens;
  double inertial_heading;
  float speed;
  int target_heading;
  int angle_to_cover;
  float Tspeed;
  double prev_X = 0;
  double prev_Y = 0;
  float prev_theta;
  float Tprev_error;
  float robot_heading;
  float OGtheta;
  float base_heading = inertial_sensor.heading(deg);
  
  while(1){
  Brain.Screen.clearScreen();
  prev_theta =  robot_heading;

  back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev)) - Cback_sens;
  joint_left = inch_to_rev(midleft.rotation(rev)) - Cjoint_left;
  joint_right = inch_to_rev(midright.rotation(rev)) - Cjoint_right;
  Tjoint_left = Cjoint_left + joint_left;
  Tjoint_right = Cjoint_right + joint_right;
  Tback_sens = Cback_sens + back_sen;
  
  Ctheta = base_heading + (joint_left - joint_right)/(center_to_left_track_wheel + center_to_right_track_wheel);
  OGtheta = Ctheta;
  Ctheta = rad_to_deg(Ctheta);
  theta =  Ctheta - prev_theta;
  robot_heading = prev_theta + (theta/2);
  X_cor = prev_X + ((2*(sin(Ctheta/2))) * ((Tback_sens/OGtheta) + center_to_back_track_wheel));
  Y_cor = prev_Y + ((2*(sin(Ctheta/2))) * ((Tjoint_right/OGtheta) + center_to_right_track_wheel));
  
       Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Y:");
        Brain.Screen.setCursor(1,4);
        Brain.Screen.print(Y_cor);
        Brain.Screen.setCursor(3,1);
        Brain.Screen.print("X:");
        Brain.Screen.setCursor(3,4);
        Brain.Screen.print(X_cor);
        Brain.Screen.setCursor(5,1);
        Brain.Screen.print("Heading");
        Brain.Screen.setCursor(5,7);
        Brain.Screen.print(robot_heading);
        Brain.Screen.setCursor(7,1);
        Brain.Screen.print("X_wheel");
        Brain.Screen.setCursor(7,4);
        Brain.Screen.print( X_rotate_inch_to_rev(back_X_rotation.position(rev)));
        vex::task::sleep(55);
  Cjoint_left = midleft.rotation(rev);
  Cjoint_right = midright.rotation(rev);
  Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));

  }

 

}


void linear_advanced_positoning_systemk2(float X_target, float Y_target, int head, float max_speed, float turn_speed){
  //assumes Robot has no obstacles betwen it's current location and its target
  //Single straight line linear movement 
  
  double X_cor;
  double Y_cor;
  float center_to_left_track_wheel = 3;
  float center_to_right_track_wheel = 3;
  float center_to_back_track_wheel = 5.5;
  double center_to_inner_track_wheel;
  double center_to_outer_track_wheel;
  float theta;
  int X_diff;
  int Y_diff;
  double allowance = 0.05;
   double Kp =  0.7;
   double Ki  = 0.01;
   double Kd = 1.4;
   double error;
   double integral;
   double derivative;
   double previous_error;
   double prev_turn_error;
   double decrease_spd_correction_constant = 0.04;
   double correctional_error = 0;
   double turn_derivative;
   double turn_integral;
   double correctional_spd;
   double Tkd = 1.2;
   double Tki = 0.4;
   double ftkp = 0.5;
   double ftkd = 0.14;
   double ftki = 0.9;
   double Fturn_derivative;
   double Fturn_integral;
   float dist_to_cover;
  double Cjoint_left = midleft.rotation(rev);
  double Cjoint_right = midright.rotation(rev);
  double Ctheta;
  double Tjoint_left;
  double Tjoint_right;
  double joint_left;
  double joint_right;
  double back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev));
  double Cjoint;
  double joint_sensor;
  double inner_sensor;
  double outer_sensor;
  double Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));
  double Tback_sens;
  double inertial_heading;
  float speed;
  int target_heading;
  int angle_to_cover;
  float Tspeed;
  
  float Tprev_error;
  
  
  Brain.Screen.clearScreen();
  int robot_heading = inertial_sensor.heading(degrees);
  inertial_heading = inertial_sensor.heading(degrees);
  back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev)) - Cback_sens;
  joint_left = inch_to_rev(midleft.rotation(rev)) - Cjoint_left;
  joint_right = inch_to_rev(midright.rotation(rev)) - Cjoint_right;
  Tjoint_left = Cjoint_left + joint_left;
  Tjoint_right = Cjoint_right + joint_right;
  Tback_sens = Cback_sens + back_sen;
  Ctheta = (joint_left - joint_right)/(center_to_left_track_wheel + center_to_right_track_wheel);
  Ctheta = rad_to_deg(Ctheta);
  theta =  Ctheta - robot_heading;
  robot_heading = theta + (Ctheta/2);
  if (theta < 0){
    theta = 360 + theta;
  }
  X_cor = (2*(sin(theta/2))) * ((Tback_sens/theta) + center_to_back_track_wheel);
  Y_cor = (2*(sin(theta/2))) * ((Tjoint_right/theta) + center_to_right_track_wheel);
  Cjoint_left = midleft.rotation(rev);
  Cjoint_right = midright.rotation(rev);
  Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));

 

  if (X_cor != X_target || Y_target != Y_cor || robot_heading != head){
     
     
       Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Y:");
        Brain.Screen.setCursor(1,4);
        Brain.Screen.print(Y_cor);
        Brain.Screen.setCursor(3,1);
        Brain.Screen.print("X:");
        Brain.Screen.setCursor(3,4);
        Brain.Screen.print(X_cor);
        Brain.Screen.setCursor(5,1);
        Brain.Screen.print("Heading");
        Brain.Screen.setCursor(5,4);
        Brain.Screen.print(robot_heading);
        vex::task::sleep(2);
        inertial_heading = inertial_sensor.heading(degrees);
        back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev)) - Cback_sens;
        joint_left = inch_to_rev(midleft.rotation(rev)) - Cjoint_left;
        joint_right = inch_to_rev(midright.rotation(rev)) - Cjoint_right;
        Tjoint_left = Cjoint_left + joint_left;
        Tjoint_right = Cjoint_right + joint_right;
        Tback_sens = Cback_sens + back_sen;
          Ctheta = (joint_left - joint_right)/(center_to_left_track_wheel + center_to_right_track_wheel);
          Ctheta = rad_to_deg(Ctheta);
          theta =  Ctheta - robot_heading;
          robot_heading = theta + (Ctheta/2);
           if (theta < 0){
                theta = 360 + theta;
            }
              X_cor = (2*(sin(theta/2))) * ((Tback_sens/theta) + center_to_back_track_wheel);
              Y_cor = (2*(sin(theta/2))) * ((Tjoint_right/theta) + center_to_right_track_wheel);
              Cjoint_left =inch_to_rev( midleft.rotation(rev));
              Cjoint_right = inch_to_rev(midright.rotation(rev));
              Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));
            //Cjoint = midleft.rotation(rev) + midright.rotation(rev);
            //Y_cor = Cjoint*cos(robot_heading);
            //X_cor = Cjoint*sin(robot_heading);
            
            bool left = false;
            

            X_diff = X_target - X_cor;
            Y_diff = Y_target - Y_cor;

            bool need_turn = true;
            
           
            //This assumes robot is at 0 degree, which is impossible to determin
            //use inertial sensor to factor in robot angle?
            if (Y_diff == 0 || X_diff == 0){

              target_heading = 0;
            }
            else{
            target_heading = atan(Y_diff/X_diff);
            
            }
            int c = 1;
            if (target_heading < 0 ){
              target_heading = -target_heading;
              c = 0;
              
            }


            if (robot_heading > target_heading){
              angle_to_cover = robot_heading - target_heading;
              left = true;
            }
            else if(target_heading > robot_heading){
              angle_to_cover = target_heading - robot_heading;
              left = false;
            }
            else if (target_heading == robot_heading){
              need_turn = false;
              
            }
            if (angle_to_cover > 180){
              angle_to_cover  = 360 - angle_to_cover;
              left = !left;
            }



            if (X_diff < 0){
              X_diff = -X_diff;
            }
            else if (Y_diff < 0 ){
              Y_diff = -Y_diff;
            }
            
          
            //pythagoras therom for PID dist

           dist_to_cover =  sqrt(pow(X_diff,2) + pow(Y_diff,2));
           
            //turn to target 
           
            
            
          if (need_turn !=  false){
            
            while(angle_to_cover > 0){
                Brain.Screen.clearScreen();
                Brain.Screen.setCursor(1,1);
                Brain.Screen.print("Y: ");
                Brain.Screen.setCursor(1,4);
                Brain.Screen.print(Y_cor);
                Brain.Screen.setCursor(3,1);
                Brain.Screen.print("X: ");
                Brain.Screen.setCursor(3,4);
                Brain.Screen.print(X_cor);
                Brain.Screen.setCursor(5,1);
                Brain.Screen.print("ATG: ");
                Brain.Screen.setCursor(5,5);
                Brain.Screen.print(angle_to_cover);
                inertial_heading = inertial_sensor.heading(degrees);
                back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev)) - Cback_sens;
                joint_left = inch_to_rev(midleft.rotation(rev)) - Cjoint_left;
                joint_right = inch_to_rev(midright.rotation(rev)) - Cjoint_right;
                Tjoint_left = Cjoint_left + joint_left;
                Tjoint_right = Cjoint_right + joint_right;
                Tback_sens = Cback_sens + back_sen;
                Ctheta = (joint_left - joint_right)/(center_to_left_track_wheel + center_to_right_track_wheel);
                Ctheta = rad_to_deg(Ctheta);
                theta =  Ctheta - robot_heading;
                robot_heading = theta + (Ctheta/2);
                if (theta < 0){
                    theta = 360 + theta;
                }
                X_cor = (2*(sin(theta/2))) * ((Tback_sens/theta) + center_to_back_track_wheel);
                Y_cor = (2*(sin(theta/2))) * ((Tjoint_right/theta) + center_to_right_track_wheel);
                Cjoint_left = inch_to_rev(midleft.rotation(rev));
                Cjoint_right = inch_to_rev(midright.rotation(rev));
                Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));
             
                if (robot_heading >= target_heading){
                    angle_to_cover = robot_heading - target_heading;
                   
                 }
                   else if(target_heading > robot_heading){
                      angle_to_cover = target_heading - robot_heading;
                     
                    }
                 if (angle_to_cover > 180){
                       angle_to_cover  = 360 - angle_to_cover;
                        
                   }

               if (left == true){
                   Tprev_error = angle_to_cover;                        
                   Fturn_derivative =angle_to_cover - Tprev_error;              
                   Fturn_integral = Fturn_integral + angle_to_cover;
                   Tspeed = ftkp*angle_to_cover+ ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >turn_speed){
                     Tspeed = turn_speed;
                   }
                   else if(Tspeed < 1.5){
                     Tspeed = 1.5;
                   }
                   tank_left(Tspeed);     

                 }
              else if(left == false){
                  H.Screen.clearScreen();
                   Tprev_error = angle_to_cover;                    

                   Fturn_derivative =angle_to_cover - Tprev_error;              
                   Fturn_integral = Fturn_integral + angle_to_cover;
                   Tspeed = ftkp*angle_to_cover+ ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >turn_speed){
                     Tspeed = turn_speed;
                   }
                   else if(Tspeed < 1.5){
                     Tspeed = 1.5;
                   }
                   tank_right(Tspeed);
               }
               else{
                 break;
               }
                Cjoint_left =  inch_to_rev(midleft.rotation(rev));
                Cjoint_right =  inch_to_rev(midright.rotation(rev));
            }
            move_base(0);
            vex::task::sleep(300);
      }

    joint_sensor = 0;   
    error = dist_to_cover - joint_sensor;
     if (error == 0){
       integral = 0;
     }
     if (fabs(error)){
        integral = 0;


     }
     
     
    while(error > 0){
   
       Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Y:");
        Brain.Screen.setCursor(1,4);
         Brain.Screen.print(Y_cor);
        Brain.Screen.setCursor(3,1);
        Brain.Screen.print("X:");
        Brain.Screen.setCursor(3,4);
        Brain.Screen.print(X_cor);
        Brain.Screen.setCursor(5,1);
        Brain.Screen.print("Heading");
        Brain.Screen.setCursor(5,4);
        Brain.Screen.print(robot_heading);
        Brain.Screen.setCursor(8,1); 
 
        
        inertial_heading = inertial_sensor.heading(degrees);
        back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev)) - Cback_sens;
        joint_left = inch_to_rev(midleft.rotation(rev)) - Cjoint_left;
        joint_right = inch_to_rev(midright.rotation(rev)) - Cjoint_right;
        Tjoint_left = Cjoint_left + joint_left;
        Tjoint_right = Cjoint_right + joint_right;
         Tback_sens = Cback_sens + back_sen;
        Ctheta = (joint_left - joint_right)/(center_to_left_track_wheel + center_to_right_track_wheel);
         Ctheta = rad_to_deg(Ctheta);
         theta =  Ctheta - robot_heading;
        robot_heading = theta + (Ctheta/2);
          if (theta < 0){
            theta = 360 + theta;
          }
        X_cor = (2*(sin(theta/2))) * ((Tback_sens/theta) + center_to_back_track_wheel);
        Y_cor = (2*(sin(theta/2))) * ((Tjoint_right/theta) + center_to_right_track_wheel);

        Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));
     //Y_cor = (Cjoint_left + joint_left)*cos(robot_heading);
     //X_cor = (Cjoint_right + joint_right)*sin(robot_heading);
  
       //Uses AdvPID to target    
     previous_error = error;
     joint_left =  inch_to_rev(midleft.position(rev)) - Cjoint_left;
     joint_right = inch_to_rev(midright.position(rev)) - Cjoint_right;
     joint_sensor = (joint_right + joint_left)/2;
     error =  dist_to_cover - joint_sensor;
     derivative = error - previous_error;
     integral = integral + error;
     
     speed = Kp*error + Ki*integral + Kd*derivative;

     if (speed >= max_speed){
       speed = max_speed;
     }
     else if(speed < 3){
       speed = 3;

     }

    
     
     if(joint_right > joint_left + allowance){
          prev_turn_error = correctional_error;
          correctional_error =  joint_right - joint_left;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed - ((decrease_spd_correction_constant *  correctional_error) + (turn_derivative * Tkd) + (Tki * turn_integral));  
          if(correctional_spd < 0 || correctional_spd > speed){
            correctional_spd = speed * 0.8;
          } 
          chasis_move(speed,correctional_spd);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));


     }
     else if (joint_left > joint_right + allowance){

          prev_turn_error = correctional_error;
          correctional_error =  joint_left - joint_right;
          turn_derivative = correctional_error - prev_turn_error;
          turn_integral = turn_integral + correctional_error;
          correctional_spd = speed - ((decrease_spd_correction_constant *  correctional_error) + (turn_derivative * Tkd) + (Tki * turn_integral));
          if(correctional_spd < 0 || correctional_spd > speed){
            correctional_spd = speed * 0.8;
          }     

          
          chasis_move(correctional_spd,speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print(decrease_spd_correction_constant *  correctional_error + (turn_derivative * Tkd) + (Tki * turn_integral));
      
     }
     else if(joint_left < joint_right + allowance && joint_right < joint_left + allowance ){
          move_base(speed);
          Brain.Screen.setCursor(12,1);
          Brain.Screen.print("Fwd");
     }
     else{

          move_base(speed);
          Brain.Screen.setCursor(12,1);
          
     }
        Cjoint_left = inch_to_rev(midleft.rotation(rev));
        Cjoint_right =inch_to_rev( midright.rotation(rev));
     }
            

     move_base(0);
     vex::task::sleep(200);
     int ange2 = 0;
                     
                inertial_heading = inertial_sensor.heading(degrees);
                robot_heading = inertial_heading;
                back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev)) - Cback_sens;
                joint_left = inch_to_rev(midleft.rotation(rev)) - Cjoint_left;
                joint_right = inch_to_rev(midright.rotation(rev)) - Cjoint_right;
                Tjoint_left = Cjoint_left + joint_left;
                Tjoint_right = Cjoint_right + joint_right;
                Tback_sens = Cback_sens + back_sen;
                Ctheta = (joint_left - joint_right)/(center_to_left_track_wheel + center_to_right_track_wheel);
                Ctheta = rad_to_deg(Ctheta);
                theta =  Ctheta - robot_heading;
                robot_heading = theta + (Ctheta/2);
                if (theta < 0){
                  theta = 360 + theta;
                } 
                X_cor = (2*(sin(theta/2))) * ((Tback_sens/theta) + center_to_back_track_wheel);
                Y_cor = (2*(sin(theta/2))) * ((Tjoint_right/theta) + center_to_right_track_wheel);
                Cjoint_left = inch_to_rev(midleft.rotation(rev));
                Cjoint_right = inch_to_rev( midright.rotation(rev));
                Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));
                ange2 = head - robot_heading;


            if(head > robot_heading){
              ange2 = head - robot_heading;
              left = false;


            }
            else if(head < robot_heading){
              ange2=  robot_heading - head;
              left = true;
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              left = !left;

            }
           
          
          while(ange2 > 0){
                Brain.Screen.clearScreen();
                Brain.Screen.setCursor(1,1);
                Brain.Screen.print("Y:");
                Brain.Screen.setCursor(1,4);
                Brain.Screen.print(Y_cor);
                Brain.Screen.setCursor(3,1);
                Brain.Screen.print("X:");
                Brain.Screen.setCursor(3,4);
                Brain.Screen.print(X_cor);
                Brain.Screen.setCursor(5,1);
                Brain.Screen.print("Heading");
                Brain.Screen.setCursor(5,4);
                Brain.Screen.print(robot_heading);
                vex::task::sleep(10);
                inertial_heading = inertial_sensor.heading(degrees);
                back_sen = X_rotate_inch_to_rev(back_X_rotation.position(rev)) - Cback_sens;
                joint_left =  inch_to_rev(midleft.rotation(rev)) - Cjoint_left;
                joint_right =  inch_to_rev(midright.rotation(rev)) - Cjoint_right;
                Tjoint_left = Cjoint_left + joint_left;
                Tjoint_right = Cjoint_right + joint_right;
                Tback_sens = Cback_sens + back_sen;
               if (joint_left > joint_right){
                  outer_sensor =  joint_left;
                  inner_sensor =  joint_right;
                  center_to_inner_track_wheel =center_to_left_track_wheel;
                  center_to_outer_track_wheel = center_to_right_track_wheel;

                }  
              else if (Cjoint_right > Cjoint_left ){

                    inner_sensor = Tjoint_left;
                    outer_sensor =  Tjoint_right;
                    center_to_inner_track_wheel =center_to_right_track_wheel;
                    center_to_outer_track_wheel = center_to_left_track_wheel;
                 }
                else{
                     inner_sensor = Tjoint_left;
                     outer_sensor =  Tjoint_right;
                     center_to_inner_track_wheel =center_to_right_track_wheel;
                     center_to_outer_track_wheel = center_to_left_track_wheel;

                  }
                Ctheta = (joint_left - joint_right)/(center_to_left_track_wheel + center_to_right_track_wheel);
                Ctheta = rad_to_deg(Ctheta);
                theta =  Ctheta - robot_heading;
                robot_heading = theta + (Ctheta/2);
                if (theta < 0){
                  theta = 360 + theta;
                } 
                X_cor = (2*(sin(theta/2))) * ((Tback_sens/theta) + center_to_back_track_wheel);
                Y_cor = (2*(sin(theta/2))) * ((Tjoint_right/theta) + center_to_right_track_wheel);

                Cback_sens = X_rotate_inch_to_rev(back_X_rotation.position(rev));
               ange2 = head - robot_heading;
               Brain.Screen.setCursor(1,1);
               Brain.Screen.print("Ange2:");
               Brain.Screen.setCursor(1,4);
               Brain.Screen.print(ange2);
               Brain.Screen.setCursor(3,1);
               Brain.Screen.print("Speed");
               Brain.Screen.setCursor(3,5);
               Brain.Screen.print(Tspeed);
 
              //adjust to heading

        if (left == true){
                   Tprev_error = ange2;
             
           
            if(head > robot_heading){
              ange2 = head - robot_heading;
              


            }
            else if(head < robot_heading){
              ange2=  robot_heading - head;
            
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              

            }

           if (ange2 < 0){
                    ange2 =  360 + ange2;
                }
                Fturn_derivative = ange2 - Tprev_error;              
                Fturn_integral = Fturn_integral + ange2;
                Tspeed = ftkp*ange2 + ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >turn_speed){
                     Tspeed = turn_speed;
                   }
                   else if(Tspeed < 2){
                     Tspeed = 2;
                   }
                   tank_left(Tspeed);     

            }
         else if(left == false){
                   Tprev_error = ange2;
  

            if(head > robot_heading){
              ange2 = head - robot_heading;
              


            }
            else if(head < robot_heading){
              ange2=  robot_heading - head;
            
            }
            if (ange2 > 180){
              ange2 = 360 - ange2;
              

            }

            
                 if (ange2 < 0){
                     ange2 =  360 + ange2;
                   }
                   Fturn_derivative =ange2 - Tprev_error;              
                   Fturn_integral = Fturn_integral + ange2;
                   Tspeed = ftkp*ange2 + ftki*Fturn_integral + ftkd*Fturn_derivative;
                   if (Tspeed >turn_speed){
                     Tspeed = turn_speed;
                   }
                   else if(Tspeed < 2){
                     Tspeed = 2;
                   }
                   tank_right(Tspeed);
               }
                Cjoint_left =  inch_to_rev(midleft.rotation(rev));
                Cjoint_right =  inch_to_rev(midright.rotation(rev));
            }
    move_base(0);


    //turn to final heading;
  } 
                  
}

void intake_pneu(bool way){
  DigitalOutE.set(way);
  DigitalOutF.set(!way);
  


}
void Match_load_moment(){
  vex::task::sleep(5);
  adv_PID_base_fwdMk2( 11.5 , 7);
  PID_Match_load(40.6,8);
  adv_PID_base_fwdMk2(8.25,5);
  shootfwd();
  adv_PID_base_rev(15,5);
  vex::task::sleep(20);
  PID_Match_load_CB(40, 7);
  reset(700,12);
  vex::task::sleep(1200);

}
void Match_load_moment1(){
  vex::task::sleep(5);
  adv_PID_base_fwdMk2( 40 , 7);
  PID_Match_load(28,8);
  adv_PID_base_fwdMk2(8.25,5);
  shootfwd();
  adv_PID_base_rev(40,5);
  vex::task::sleep(20);
  PID_Match_load_CB(28.4, 7);
  reset(700,12);
  vex::task::sleep(1200);

}


void Match_load_moment2(){

  adv_PID_base_fwdMk2( 40 , 7);
  PID_Match_load(30,8);
  adv_PID_base_fwdMk2( 5 , 7);
  shoot();


}
void all_moments(){
  while(H.ButtonA.pressing() != 1)
  {

   Match_load_moment();
   Match_load_moment1();
   Match_load_moment2();
   break;
  }
}

void Programming_Skills(){

  start_program();
  
  intake.spin(reverse,12,vex::voltageUnits::volt);
  reset(400,-7);
  linear_advance_positoning_system(0 , 25 ,90, 9 , 6);
  Brain.Screen.print("turn complete");
  //X,Y(0,20)
   vex::task::sleep(200);
   reset(1025,10);
   vex::task::sleep(400);
   intake.stop();
   adv_PID_base_fwdMk2( 19, 8);
   linear_advance_positoning_system(2,72 ,4 , 9, 6);
   adv_PID_base_fwdMk2( 17, 8);
   shoot();
   iner_turn(60,7);
   adv_PID_base_rev(90,7);
   linear_advance_positoning_system(200, 300 ,330 , 9, 6);

  
}
void Programming_SkillsMk2(){

  start_program();
  
  intake.spin(reverse,12,vex::voltageUnits::volt);
  reset(400,-7);
  linear_advanced_positoning_systemk2(0 , 25 ,90, 9 , 6);
  Brain.Screen.print("turn complete");
  //X,Y(0,20)
   vex::task::sleep(200);
   reset(1025,10);
   vex::task::sleep(400);
   intake.stop();
   adv_PID_base_fwdMk2( 19, 8);
   linear_advanced_positoning_systemk2(2,72 ,4 , 9, 6);
   adv_PID_base_fwdMk2( 17, 8);
   shoot();
   iner_turn(60,7);
   adv_PID_base_rev(90,7);
   linear_advanced_positoning_systemk2(200, 300 ,330 , 9, 6);

  
}
void pneumatic_thingy(){
  DigitalOutA.set(true);
  DigitalOutD.set(true);

}


     
 
void driver_control(float spd_pct){

    H.Screen.clearLine();
    H.Screen.setCursor(3, 1);
    

    
    H.Screen.print("Base Temp %f",(frontleft.temperature(vex::percentUnits::pct)+midleft.temperature(vex::percentUnits::pct)+midright.temperature(vex::percentUnits::pct)+frontright.temperature(vex::percentUnits::pct))/4);

    cata_runV(spd_pct);
    
    
   
   if(H.ButtonX.pressing()==1){

     boosted_shoot(12,25);
     
   }
     else{
      DigitalOutA.set(false);
      DigitalOutB.set(false);
      DigitalOutC.set(false);
      DigitalOutD.set(false);
    }
    int Ax3 = (H.Axis3.value()/(127/12))*spd_pct;
    int Ax2 = (H.Axis2.value()/(127/12))*spd_pct;
    pure_chasis_move(Ax3,Ax2);


    intake.spin(reverse, V.Axis2.value()/(127/12), vex::voltageUnits::volt);  

    if(H.ButtonB.pressing() == 1){

     Expansion_out.set(true);


    }
    else{

      Expansion_out.set(false);
    }

    if(H.ButtonA.pressing()==1){


          DigitalOutB.set(true);


    }
    else{
      DigitalOutB.set(false);
    }
    if(H.ButtonX.pressing() == 1){

     DigitalOutE.set(true);
     DigitalOutF.set(false);
    }
    else{
     DigitalOutE.set(false);
     DigitalOutF.set(false);
    }
    if(H.ButtonY.pressing() == 1 ){
     cat_test.spin(reverse, 12 , vex::voltageUnits::volt);
     vex::task::sleep(65);
     cat_test.spin(reverse , 0 , vex::voltageUnits::volt);

    }

    else{
     cat_test.spin(forward,0,vex::voltageUnits::volt);

    }

  }


  void dogshit_driver_control(float spd_pct){

    H.Screen.clearLine();
    H.Screen.setCursor(3, 1);

    

    
    H.Screen.print("Base Temp %f",(frontleft.temperature(vex::percentUnits::pct)+midleft.temperature(vex::percentUnits::pct)+midright.temperature(vex::percentUnits::pct)+frontright.temperature(vex::percentUnits::pct))/4);

    float Ch3 = H.Axis3.value() * spd_pct;

    float Ch1 = H.Axis1.value()* spd_pct;
    if(fabs(Ch3) > 10){
      pure_chasis_move(Ch3 , Ch3 );
    }else if(fabs(Ch1) > 15){
       pure_chasis_move(Ch1 * 0.25, -Ch1 *0.25);
    }else {
      move_base(0);
    }

    dog_cata_run(spd_pct);
    
    
   
   if(H.ButtonX.pressing()==1){

     boosted_shoot(12,25);
     
   }
     else{
      DigitalOutA.set(false);
      DigitalOutB.set(false);
      DigitalOutC.set(false);
      DigitalOutD.set(false);
    }


    if(H.ButtonR1.pressing()== 1){

      intake.spin(forward, 12, vex::voltageUnits::volt);
    }
    else if (H.ButtonR2.pressing() == 1){
      intake.spin(reverse, 12 ,vex::voltageUnits::volt);
    }
    else{
      intake.stop();
    }
    
   

    if(H.ButtonB.pressing() == 1){

     Expansion_out.set(true);


    }
    else{

      Expansion_out.set(false);
    }

    if(H.ButtonA.pressing()==1){


          DigitalOutB.set(true);


    }
    else{
      DigitalOutB.set(false);
    }
    if(H.ButtonX.pressing() == 1){

     DigitalOutE.set(true);
     DigitalOutF.set(false);
    }
    else{
     DigitalOutE.set(false);
     DigitalOutF.set(false);
    }
    if(H.ButtonY.pressing() == 1 ){
     cat_test.spin(reverse, 12 , vex::voltageUnits::volt);
     vex::task::sleep(65);
     cat_test.spin(reverse , 0 , vex::voltageUnits::volt);

    }

    else{
     cat_test.spin(forward,0,vex::voltageUnits::volt);

    }

  }


  void autonredmk1(){
    DigitalOutE.set(false);
    DigitalOutF.set(false);
     float speed_change_zone = 145.75;
  
     float rotate_val = cata_rotate.angle(degrees);
    while(rotate_val  >= speed_change_zone){
       vex::task::sleep(20);
       rotate_val =  cata_rotate.angle(degrees);
       cat_test.spin(reverse, 12, vex::voltageUnits::volt);

      }
   
       cat_test.spin(forward, 0, vex::voltageUnits::volt);

    intake.spin(reverse,10, volt);
    PID_movement_W_heading(35, 15,17.95,7);
    intake.stop();
    vex::task::sleep(150);
    boosted_shoot(4.35,24);
    while(rotate_val  >= speed_change_zone){
       vex::task::sleep(20);
       rotate_val =  cata_rotate.angle(degrees);
       cat_test.spin(reverse, 12, vex::voltageUnits::volt);

      }
   
    cat_test.spin(forward, 0, vex::voltageUnits::volt);
    vex::task::sleep(200);
    intake.spin(reverse,12, volt);
    PID_movement_W_heading(0,12,330,8);
    vex::task::sleep(100);
    adv_PID_base_fwdMk1( 112, 13);
    intake.spin(forward,12, volt);
    vex::task::sleep(100);
    intake.spin(reverse,12, volt);
    reset(650,12);
    vex::task::sleep(100);
    PID_movement_W_heading(0,8,18 ,8);
    vex::task::sleep(300);
    adv_PID_base_fwdMk1( 11, 6);
    boosted_shoot(12, 17);
    reset(300,9);
    PID_movement_W_heading(0,10,327.5,9);
    reset(760,18);
    intake.spin(reverse, 12, vex::voltageUnits::volt);
    PID_roller(80,12);
    reset(610,9);
    reset(460,-8);
    intake.spin(reverse,0, volt);
    move_base(0);
  }
  void autonredmk2(){

    intake.spin(reverse,12,volt);
    base_left(-7);
    vex::task::sleep(370);
    cat_test.spin(forward, 0, vex::voltageUnits::volt);
    intake.spin(reverse,0,volt);
    PID_movement_W_heading( 12, 8,355.5,9);
    adv_PID_base_fwdMk1( 12.5,10);
    vex::task::sleep(200);
    boosted_shoot(12,25);
    reset(400,9);
    /*
    vex::task::sleep(200);
    PID_movement_W_heading( 0, 0,44,9);
    intake.spin(forward,12,volt);
    vex::task::sleep(250);
    PID_base_fwd(28, 12);
    intake.spin(reverse,12,volt);
    PID_base_fwd(5, 9);
    vex::task::sleep(450);
   reset(510,-2.75);
   PID_movement_W_heading( 0, 0, 355,10);
    adv_PID_base_fwdMk1(17, 11);
    boosted_shoot(12,24);
    reset(300,10);
    PID_movement_W_heading( 0, 0, 80,12);
    adv_PID_base_fwdMk1(100,12);
    reset(400,10);
    PID_movement_W_heading( 0, 0, 348,12);
    adv_PID_base_fwdMk1(40,9);
    boosted_shoot(12,26);
    */

  }
  void autonbluemk2(){

    intake.spin(reverse,12,volt);
    base_left(-7);
    vex::task::sleep(350);
    cat_test.spin(forward, 0, vex::voltageUnits::volt);
    intake.spin(reverse,0,volt);
    PID_movement_W_heading( 12, 8,352.5,9);
    adv_PID_base_fwdMk1( 9.85,10);
    vex::task::sleep(200);
    boosted_shoot(12,25);
    reset(400,9);
    /*
    vex::task::sleep(200);
    PID_movement_W_heading( 0, 0,44,9);
    intake.spin(forward,12,volt);
    vex::task::sleep(250);
    PID_base_fwd(28, 12);
    intake.spin(reverse,12,volt);
    PID_base_fwd(5, 9);
    vex::task::sleep(450);
   reset(510,-2.75);
   PID_movement_W_heading( 0, 0, 355,10);
    adv_PID_base_fwdMk1(17, 11);
    boosted_shoot(12,24);
    reset(300,10);
    PID_movement_W_heading( 0, 0, 80,12);
    adv_PID_base_fwdMk1(100,12);
    reset(400,10);
    PID_movement_W_heading( 0, 0, 348,12);
    adv_PID_base_fwdMk1(40,9);
    boosted_shoot(12,26);
    */

  }


  void autonbluemk1(){
    DigitalOutE.set(false);
    DigitalOutF.set(false);
     float speed_change_zone = 145.75;
  
     float rotate_val = cata_rotate.angle(degrees);
    while(rotate_val  >= speed_change_zone){
       vex::task::sleep(20);
       rotate_val =  cata_rotate.angle(degrees);
       cat_test.spin(reverse, 12, vex::voltageUnits::volt);

      }
   
       cat_test.spin(forward, 0, vex::voltageUnits::volt);

    intake.spin(reverse,10, volt);
    PID_movement_W_heading(37, 15,16.24,7);
    intake.stop();
    vex::task::sleep(150);
    boosted_shoot(9,23);
    while(rotate_val  >= speed_change_zone){
       vex::task::sleep(20);
       rotate_val =  cata_rotate.angle(degrees);
       cat_test.spin(reverse, 12, vex::voltageUnits::volt);

      }
   
    cat_test.spin(forward, 0, vex::voltageUnits::volt);
    vex::task::sleep(200);
    intake.spin(reverse,12, volt);
    PID_movement_W_heading(0,12,330,8);
    vex::task::sleep(100);
    adv_PID_base_fwdMk1( 105, 12);
    vex::task::sleep(100);
    reset(650,12);
    vex::task::sleep(100);
    PID_movement_W_heading(0,8,16.725 ,8);
    vex::task::sleep(300);
    adv_PID_base_fwdMk1( 5, 6);
    boosted_shoot(12,20);
    reset(300,9);
    PID_movement_W_heading(0,10,327.5,9);
    reset(720,18);
    intake.spin(reverse, 12, vex::voltageUnits::volt);
    PID_roller(78.5,12);
    reset(680,9);
    reset(420,-8);
    intake.spin(reverse,0, volt);
    move_base(0);
  }
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
 
  inertial_sensor.calibrate();

  
  while(inertial_sensor.isCalibrating())
  {
    vex::task::sleep(5);
  }

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  autonredmk1();

  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    solo_driver_control(1);

    
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
