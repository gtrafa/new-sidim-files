
#include "Arduino.h"

class MotorDrive{

  private:
  
  // Pinos para o controle do C.I. de Ponte H
  int MOTORLATCH;      // 45
  int MOTORCLK;        // 39
  int MOTORENABLE;     // 41
  int MOTORDATA;       // 43  
  
  public: 
  uint8_t motor = 0;

// Orden dos pinos no shield
// (pin4 = motorClk, pin7 = motorEnable, pin8 = motorData, pin12 = motorLatch)
  void SetMotorShieldPins(int motorClk, int motorEnable, int motorData, int motorLatch) {
     MOTORLATCH = motorLatch;      
     MOTORCLK = motorClk;        
     MOTORENABLE = motorEnable;  
     MOTORDATA = motorData;   
    }

  void inicializaMotores() {
    pinMode(MOTORLATCH, OUTPUT);
    pinMode(MOTORCLK, OUTPUT);
    pinMode(MOTORENABLE, OUTPUT);
    pinMode(MOTORDATA, OUTPUT);
    digitalWrite(MOTORENABLE, LOW);
    bitWrite(motor, 0, 0);  
    bitWrite(motor, 1, 0);
    bitWrite(motor, 2, 0);  
    bitWrite(motor, 3, 0);
    bitWrite(motor, 4, 0);  
    bitWrite(motor, 5, 0);
    bitWrite(motor, 6, 0);  
    bitWrite(motor, 7, 0);
  }

  void motor1Forward() {
    bitWrite(motor, 4, 1);  
    bitWrite(motor, 5, 0); 
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor1Backward() {
    bitWrite(motor, 4, 0);  
    bitWrite(motor, 5, 1);
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor1Stop() {
    bitWrite(motor, 4, 0);  
    bitWrite(motor, 5, 0);    
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor2Forward() {
    bitWrite(motor, 3, 0);  
    bitWrite(motor, 6, 1);    
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor2Backward() {
    bitWrite(motor, 3, 1);  
    bitWrite(motor, 6, 0);    
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor2Stop() {
    bitWrite(motor, 3, 0);  
    bitWrite(motor, 6, 0);    
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor3Forward() {
    bitWrite(motor, 0, 0);  
    bitWrite(motor, 2, 1);    
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor3Backward() {
    bitWrite(motor, 0, 1);  
    bitWrite(motor, 2, 0);    
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor3Stop() {
    bitWrite(motor, 0, 0);  
    bitWrite(motor, 2, 0);    
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor4Forward() {
    bitWrite(motor, 1, 1);  
    bitWrite(motor, 7, 0);  
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor4Backward() {
    bitWrite(motor, 1, 0);  
    bitWrite(motor, 7, 1);    
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }

  void motor4Stop() {
    bitWrite(motor, 1, 0);  
    bitWrite(motor, 7, 0);  
    digitalWrite(MOTORLATCH, LOW);
    shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
    digitalWrite(MOTORLATCH, HIGH);
  }
  
  };

  // MotorDrive MSD01;
  // MotorDrive MSD02;
  MotorDrive ROBO;
