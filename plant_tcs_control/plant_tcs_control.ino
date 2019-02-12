
//#include "TCS_Config.h"
#include "MotorDrive.h"
#include "MotorDrive2HBridge.h"

#define MODO_DE_OPERACAO 37

// sensores robo
int roboVertical_fc_pin = 52;
int roboVertical_encoder_pin = 51;

int roboHorizontal_fc_pin = 49;
int roboHorizontal_encoder_pin = 48;

int roboRotacional_fc_pin = 33;
int roboRotacional_encoder_pin = 32;

void setup() {
  //Definindo pino digital "MODO_DE_OPERACAO" como de entrada.
  pinMode(MODO_DE_OPERACAO, INPUT);

  // Configurando e Inicializando Motor Shields(azul)
  ROBO.SetMotorShieldPins(34, 35, 36, 37); // (pin4 = motorClk, pin7 = motorEnable, pin8 = motorData, pin12 = motorLatch)
  ROBO.inicializaMotores();

  //MSD02.SetMotorShieldPins(4, 5, 6, 7);
  //MSD02.inicializaMotores();

  // Ponte-H vermelha
  MSD03.SetMotorShieldPins(44, 43, 42, 41);
  MSD03.inicializaMotores();

  // TCS Planta e Supervisor
  // Esta parte precisa ser aprimorada por usar mais de um Motor Shield
  // SIDIM.TcsAutomataSetup();
  // PlantaESupervisorSetup();

  // testar os sensores da planta
  Serial.begin (9600);
  pinMode(roboVertical_fc_pin, INPUT_PULLUP);
  pinMode(roboVertical_encoder_pin, INPUT_PULLUP);
  pinMode(roboHorizontal_fc_pin, INPUT_PULLUP);
  pinMode(roboHorizontal_encoder_pin, INPUT_PULLUP);
  pinMode(roboRotacional_fc_pin, INPUT_PULLUP);
  pinMode(roboRotacional_encoder_pin, INPUT_PULLUP);
  
}

void loop() {

  // teste dos motor Shields 01, 02 e 03
  // sensores robo
  int roboVetFC = digitalRead(roboVertical_fc_pin);
  int roboVetEncoder = digitalRead(roboVertical_encoder_pin);

  int roboHorFC = digitalRead(roboHorizontal_fc_pin);
  int roboHorEncoder = digitalRead(roboHorizontal_encoder_pin);

  int roboRotFC = digitalRead(roboRotacional_fc_pin);
  int roboRotEncoder = digitalRead(roboRotacional_encoder_pin);

  Serial.print (" Vertical: ");
  Serial.print (roboVetFC);
  Serial.print (" , ");
  Serial.print (roboVetEncoder);
  Serial.print (" , Horizontal: ");
  Serial.print (roboHorFC);
  Serial.print (" , ");
  Serial.print (roboHorEncoder);
  Serial.print (" , Rotacao:");
  Serial.print (roboRotFC);
  Serial.print (" , ");
  Serial.println (roboRotEncoder);
  delay(100);
}

  // motod shield 01 = robo
  /*
  // movimento horizontal
  ROBO.motor1Forward();
  delay(100);
  ROBO.motor1Backward();
  delay(100);
  ROBO.motor1Backward();
  delay(100);
  ROBO.motor1Stop();

  // movimento vertical
  ROBO.motor2Forward();
  delay(200);
  ROBO.motor2Backward();
  delay(200); 
  ROBO.motor2Backward();
  delay(200);
  ROBO.motor2Stop();

  // movimento rotacional
  ROBO.motor3Forward();
  delay(200);
  ROBO.motor3Backward();
  delay(200);
  ROBO.motor3Stop();

  // movimento da garra
  ROBO.motor4Forward();
  delay(200);
  ROBO.motor4Backward();
  delay(200);
  ROBO.motor4Stop();
*/

