
 // Biblioteca para manipulação de Autômatos
#include "Fsm.h"
// Biblioteca para lidar com sensores e motores
//#include "funcionamentoParalelo.h"
#include "MotorDrive.h"
#include "InputsGlobais.h"

// Desabilitações de cada um dos supervisores (são atualizadas a cada estado)
uint8_t des_sup1;
uint8_t des_sup2;
uint8_t des_sup3;
uint8_t des_sup4;
uint8_t des_sup5;
uint8_t des_sup6;
uint8_t des_sup7;
uint8_t des_sup;

// Funções a serem executadas nos estados dos supervisores

void acao_estado1_S1()
{
  //desabilita a4
  bitWrite(des_sup1,0,0);
  bitWrite(des_sup1,1,0);
  bitWrite(des_sup1,2,0);
  bitWrite(des_sup1,3,1);
  bitWrite(des_sup1,4,0);
  bitWrite(des_sup1,5,0);
  Serial.println("S1 : ESTADO 1");
}
void acao_estado2_S1()
{
  // desabilita a4
  bitWrite(des_sup1,0,0);
  bitWrite(des_sup1,1,0);
  bitWrite(des_sup1,2,0);
  bitWrite(des_sup1,3,1);
  bitWrite(des_sup1,4,0);
  bitWrite(des_sup1,5,0);
  Serial.println("S1 : ESTADO 2");
}
void acao_estado3_S1()
{
  // desabilita a4
  bitWrite(des_sup1,0,0);
  bitWrite(des_sup1,1,0);
  bitWrite(des_sup1,2,0);
  bitWrite(des_sup1,3,1);
  bitWrite(des_sup1,4,0);
  bitWrite(des_sup1,5,0);
  Serial.println("S1 : ESTADO 3");
}
void acao_estado4_S1()
{
  // todos estado habilitados
  bitWrite(des_sup1,0,0);
  bitWrite(des_sup1,1,0);
  bitWrite(des_sup1,2,0);
  bitWrite(des_sup1,3,0);
  bitWrite(des_sup1,4,0);
  bitWrite(des_sup1,5,0);
  Serial.println("S1 : ESTADO 4");
}
void acao_estado1_S2()
{
  //desabilita a3
  bitWrite(des_sup2,0,0);
  bitWrite(des_sup2,1,0);
  bitWrite(des_sup2,2,1);
  bitWrite(des_sup2,3,0);
  bitWrite(des_sup2,4,0);
  bitWrite(des_sup2,5,0);
  Serial.println("S2 : ESTADO 1");
}
void acao_estado2_S2()
{
  //desabilita a3
  bitWrite(des_sup2,0,0);
  bitWrite(des_sup2,1,0);
  bitWrite(des_sup2,2,1);
  bitWrite(des_sup2,3,0);
  bitWrite(des_sup2,4,0);
  bitWrite(des_sup2,5,0);
  Serial.println("S2 : ESTADO 2");
}
void acao_estado3_S2()
{
  //desabilita a3
  bitWrite(des_sup2,0,0);
  bitWrite(des_sup2,1,1);
  bitWrite(des_sup2,2,0);
  bitWrite(des_sup2,3,0);
  bitWrite(des_sup2,4,0);
  bitWrite(des_sup2,5,0);
  Serial.println("S2 : ESTADO 3");
}
void acao_estado1_S3()
{
  //desabilita a6
  bitWrite(des_sup3,0,0);
  bitWrite(des_sup3,1,0);
  bitWrite(des_sup3,2,0);
  bitWrite(des_sup3,3,0);
  bitWrite(des_sup3,4,0);
  bitWrite(des_sup3,5,1);
  Serial.println("S3 : ESTADO 1");
}
void acao_estado2_S3()
{
  //desabilita a6
  bitWrite(des_sup3,0,0);
  bitWrite(des_sup3,1,0);
  bitWrite(des_sup3,2,0);
  bitWrite(des_sup3,3,0);
  bitWrite(des_sup3,4,0);
  bitWrite(des_sup3,5,1);
  Serial.println("S3 : ESTADO 2");
}
void acao_estado3_S3()
{
  //desabilita a6
  bitWrite(des_sup3,0,0);
  bitWrite(des_sup3,1,0);
  bitWrite(des_sup3,2,0);
  bitWrite(des_sup3,3,0);
  bitWrite(des_sup3,4,0);
  bitWrite(des_sup3,5,1);
  Serial.println("S3 : ESTADO 3");
}
void acao_estado4_S3()
{
  //todos eventos habilitados
  bitWrite(des_sup3,0,0);
  bitWrite(des_sup3,1,0);
  bitWrite(des_sup3,2,0);
  bitWrite(des_sup3,3,0);
  bitWrite(des_sup3,4,0);
  bitWrite(des_sup3,5,0);
  Serial.println("S3 : ESTADO 4");
}
void acao_estado1_S4()
{
  // a4, a5 e a6 desabilitados
  bitWrite(des_sup4,0,0);
  bitWrite(des_sup4,1,0);
  bitWrite(des_sup4,2,0);
  bitWrite(des_sup4,3,1);
  bitWrite(des_sup4,4,1);
  bitWrite(des_sup4,5,1);
  Serial.println("S4 : ESTADO 1");
}
void acao_estado2_S4()
{
  // a2 desabilitado
  bitWrite(des_sup4,0,0);
  bitWrite(des_sup4,1,1);
  bitWrite(des_sup4,2,0);
  bitWrite(des_sup4,3,0);
  bitWrite(des_sup4,4,0);
  bitWrite(des_sup4,5,0);
  Serial.println("S4 : ESTADO 2");
}
void acao_estado1_S5()
{
  // a5 desabilitado
  bitWrite(des_sup5,0,0);
  bitWrite(des_sup5,1,0);
  bitWrite(des_sup5,2,0);
  bitWrite(des_sup5,3,0);
  bitWrite(des_sup5,4,1);
  bitWrite(des_sup5,5,0);
  Serial.println("S5 : ESTADO 1");
}
void acao_estado2_S5()
{
  // a5 desabilitado
  bitWrite(des_sup5,0,0);
  bitWrite(des_sup5,1,0);
  bitWrite(des_sup5,2,0);
  bitWrite(des_sup5,3,0);
  bitWrite(des_sup5,4,1);
  bitWrite(des_sup5,5,0);
  Serial.println("S5 : ESTADO 2");
}
void acao_estado3_S5()
{
  // a5 desabilitado
  bitWrite(des_sup5,0,0);
  bitWrite(des_sup5,1,0);
  bitWrite(des_sup5,2,0);
  bitWrite(des_sup5,3,0);
  bitWrite(des_sup5,4,1);
  bitWrite(des_sup5,5,0);
  Serial.println("S5 : ESTADO 3");
}
void acao_estado4_S5()
{
  // todos eventos habilitados
  bitWrite(des_sup5,0,0);
  bitWrite(des_sup5,1,0);
  bitWrite(des_sup5,2,0);
  bitWrite(des_sup5,3,0);
  bitWrite(des_sup5,4,0);
  bitWrite(des_sup5,5,0);
  Serial.println("S5 : ESTADO 4");
}
void acao_estado1_S6()
{
  // a2 e a3 desabilitados
  bitWrite(des_sup6,0,0);
  bitWrite(des_sup6,1,1);
  bitWrite(des_sup6,2,1);
  bitWrite(des_sup6,3,0);
  bitWrite(des_sup6,4,0);
  bitWrite(des_sup6,5,0);
  Serial.println("S6 : ESTADO 1");
}
void acao_estado2_S6()
{
  // a1 desabilitado
  bitWrite(des_sup6,0,1);
  bitWrite(des_sup6,1,0);
  bitWrite(des_sup6,2,0);
  bitWrite(des_sup6,3,0);
  bitWrite(des_sup6,4,0);
  bitWrite(des_sup6,5,0);
  Serial.println("S6 : ESTADO 2");
}

// Declara-se abaixo os estados e as FSM dos Supervisores Modulares Locais Reduzidos

// S1 - Supervisor modular reduzido 1
static State ESTADO1_S1(acao_estado1_S1, NULL, NULL);
static State ESTADO2_S1(acao_estado2_S1, NULL, NULL);
static State ESTADO3_S1(acao_estado3_S1, NULL, NULL);
static State ESTADO4_S1(acao_estado4_S1, NULL, NULL);
static Fsm S1(&ESTADO1_S1);

// S2 - Supervisor modular reduzido 2
static State ESTADO1_S2(acao_estado1_S2, NULL, NULL);
static State ESTADO2_S2(acao_estado2_S2, NULL, NULL);
static State ESTADO3_S2(acao_estado3_S2, NULL, NULL);
static Fsm S2(&ESTADO1_S2);

// S3 - Supervisor modular reduzido 3
static State ESTADO1_S3(acao_estado1_S3, NULL, NULL);
static State ESTADO2_S3(acao_estado2_S3, NULL, NULL);
static State ESTADO3_S3(acao_estado3_S3, NULL, NULL);
static State ESTADO4_S3(acao_estado4_S3, NULL, NULL);
static Fsm S3(&ESTADO1_S3);

// S4 - Supervisor modular reduzido 4
static State ESTADO1_S4(acao_estado1_S4, NULL, NULL);
static State ESTADO2_S4(acao_estado2_S4, NULL, NULL);
static Fsm S4(&ESTADO1_S4);

// S5 - Supervisor modular reduzido 5
static State ESTADO1_S5(acao_estado1_S5, NULL, NULL);
static State ESTADO2_S5(acao_estado2_S5, NULL, NULL);
static State ESTADO3_S5(acao_estado3_S5, NULL, NULL);
static State ESTADO4_S5(acao_estado4_S5, NULL, NULL);
static Fsm S5(&ESTADO1_S5);

// S6 - Supervisor modular reduzido 6
static State ESTADO1_S6(acao_estado1_S6, NULL, NULL);
static State ESTADO2_S6(acao_estado2_S6, NULL, NULL);
static Fsm S6(&ESTADO1_S6);

void supervisorSetup(){
                         
    // Função de transição de S1
    S1.add_transition(&ESTADO1_S1, &ESTADO2_S1,
                         bv, NULL);
    S1.add_transition(&ESTADO2_S1, &ESTADO3_S1,
                         bp, NULL);
    S1.add_transition(&ESTADO3_S1, &ESTADO4_S1,
                         b2, NULL);                     
    S1.add_transition(&ESTADO4_S1, &ESTADO1_S1,
                         a4, NULL);
    S1.add_transition(&ESTADO2_S1, &ESTADO1_S1,
                         bg, NULL);
    
    // Função de transição de S2
    S2.add_transition(&ESTADO1_S2, &ESTADO2_S2,
                         ba, NULL);
    S2.add_transition(&ESTADO2_S2, &ESTADO3_S2,
                         bg, NULL);
    S2.add_transition(&ESTADO3_S2, &ESTADO1_S2,
                         a3, NULL);
    S2.add_transition(&ESTADO2_S2, &ESTADO1_S2,
                         bp, NULL);                     
    
    // Função de transição de S3
    S3.add_transition(&ESTADO1_S3, &ESTADO2_S3,
                         bv, NULL);
    S3.add_transition(&ESTADO2_S3, &ESTADO3_S3,
                         bg, NULL);
    S3.add_transition(&ESTADO3_S3, &ESTADO4_S3,
                         b2, NULL);                     
    S3.add_transition(&ESTADO4_S3, &ESTADO1_S3,
                         a6, NULL);                     
    S3.add_transition(&ESTADO2_S3, &ESTADO1_S3,
                         bp, NULL);
                         
    // Função de transição de S4
    S4.add_transition(&ESTADO1_S4, &ESTADO2_S4,
                         b2, NULL);
    S4.add_transition(&ESTADO2_S4, &ESTADO1_S4,
                         a5, NULL);
    S4.add_transition(&ESTADO2_S4, &ESTADO1_S4,
                         a4, NULL);
    S4.add_transition(&ESTADO2_S4, &ESTADO1_S4,
                         a6, NULL);
    
    // Função de transição de S5
    S5.add_transition(&ESTADO1_S5, &ESTADO2_S5,
                         ba, NULL);
    S5.add_transition(&ESTADO2_S5, &ESTADO3_S5,
                         bp, NULL);
    S5.add_transition(&ESTADO3_S5, &ESTADO4_S5,
                         b2, NULL);                     
    S5.add_transition(&ESTADO4_S5, &ESTADO1_S5,
                         a5, NULL);
    S5.add_transition(&ESTADO2_S5, &ESTADO1_S5,
                         bg, NULL);                     
    
    // Função de transição de S6
    S6.add_transition(&ESTADO1_S6, &ESTADO2_S6,
                         b1, NULL);                     
    S6.add_transition(&ESTADO2_S6, &ESTADO1_S6,
                         a3, NULL);                     
    S6.add_transition(&ESTADO2_S6, &ESTADO1_S6,
                         a2, NULL);

        
    // Inicia o funcionamento dos automatos dos supervisores modulares, iniciando no estado 1
    S1.run_machine();
    S2.run_machine();
    S3.run_machine();
    S4.run_machine();
    S5.run_machine();
    S6.run_machine();
  
  }

