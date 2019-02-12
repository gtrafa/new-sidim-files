//Arduino DC motor control - L298N 

#include "Arduino.h"

class MotorDrive2HBridge{

  private:
  int enableA;      // speed control: with jumper motor A max speed, 
                    // without jumper: connect a PWM to control speed.
  int enableB;      // speed control: with jumper motor B max speed, 
                    // without jumper: connect a PWM to control speed.
  
  int input01;      // controls motor A
  int input02;      // controls motor A
  int input03;      // controls motor B
  int input04;      // controls motor B

  
  public:

  // Set the pin for the PWM control 
  // This part needs to be integrated with the pwm.
  void SetSpeedControl(int enA, int enB){
     enableA = enA;
     enableB = enB;    
    }
  
  // Set the pins that will control the motors  
  void SetMotorShieldPins( int in01, int in02, int in03, int in04) {
     input01 = in01;
     input02 = in02;
     input03 = in03;
     input04 = in04;   
    }
  
  //   
  void inicializaMotoresComPWM() {
      pinMode(enableA, OUTPUT);
      pinMode(enableA, OUTPUT);
  }
  
  void inicializaMotores() {
      pinMode(input01, OUTPUT);
      pinMode(input02, OUTPUT);
      pinMode(input03, OUTPUT);
      pinMode(input04, OUTPUT);
      
      // iniciliza motores parados
      digitalWrite(input01,LOW);
      digitalWrite(input02,LOW);
      digitalWrite(input03,LOW);
      digitalWrite(input04,LOW);
    }

    // Motor control Methods
  void motor_A_Forward() {
      digitalWrite(input01,HIGH);
      digitalWrite(input02,LOW);
  }

  void motor_A_Backward() {
    digitalWrite(input01,LOW);
    digitalWrite(input02,HIGH);
  }

  void motor_A_Stop() {
    digitalWrite(input01,LOW);
    digitalWrite(input02,LOW);
  }

  void motor_B_Forward() {
      digitalWrite(input03,HIGH);
      digitalWrite(input04,LOW);
  }

  void motor_B_Backward() {
    digitalWrite(input03,LOW);
    digitalWrite(input04,HIGH);
  }

  void motor_B_Stop() {
    digitalWrite(input03,LOW);
    digitalWrite(input04,LOW);
  }

};

MotorDrive2HBridge MSD03;
