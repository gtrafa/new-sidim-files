
 // Biblioteca para manipulação de Autômatos
#include "Fsm.h"
// Biblioteca para lidar com sensores e motores
//#include "funcionamentoParalelo.h"
#include "MotorDrive.h"
#include "InputsGlobais.h"

// Funções a serem executadas nos respectivos Estados
void acao_estado1_G1() { MSD01.motor1Stop();}
void acao_estado2_G1() { MSD01.motor1Forward();}

void acao_estado1_G2() { MSD01.motor2Stop();}
void acao_estado2_G2() { MSD02.motor2Forward();}
void acao_estado3_G2() { MSD02.motor2Backward();}

void acao_estado1_G3() { MSD01.motor3Stop();}
void acao_estado2_G3() { MSD01.motor3Forward();}
void acao_estado3_G3() { MSD01.motor3Backward();}
void acao_estado4_G3() { MSD01.motor3Forward();}

void acao_estado1_G5(){}
void acao_estado1_G6(){}


// Declara-se abaixo os estados e as FSM das Plantas

// G1 - Esteira 1
static State ESTADO1_G1(acao_estado1_G1, NULL, NULL);
static State ESTADO2_G1(acao_estado2_G1, NULL, NULL);
static Fsm G1(&ESTADO1_G1);

// G2 - Esteira 2
static State ESTADO1_G2(acao_estado1_G2, NULL, NULL);
static State ESTADO2_G2(acao_estado2_G2, NULL, NULL);
static State ESTADO3_G2(acao_estado3_G2, NULL, NULL);
static Fsm G2(&ESTADO1_G2);

// G3 - Esteira 3
static State ESTADO1_G3(acao_estado1_G3, NULL, NULL);
static State ESTADO2_G3(acao_estado2_G3, NULL, NULL);
static State ESTADO3_G3(acao_estado3_G3, NULL, NULL);
static State ESTADO4_G3(acao_estado4_G3, NULL, NULL);
static Fsm G3(&ESTADO1_G3);

// G5 - Sensor de cor
static State ESTADO1_G5(acao_estado1_G5, NULL, NULL);
static Fsm G5(&ESTADO1_G5);

// G6 - Sensor de tamanho
static State ESTADO1_G6(acao_estado1_G6, NULL, NULL);
static Fsm G6(&ESTADO1_G6);


void plantaSetup(){
  
  // Função de transição de G1
    G1.add_transition(&ESTADO1_G1, &ESTADO2_G1,
                         a1, NULL);
    G1.add_transition(&ESTADO2_G1, &ESTADO1_G1,
                         b1, NULL);
    
    // Função de transição de G2
    G2.add_transition(&ESTADO1_G2, &ESTADO2_G2,
                         a2, NULL);
    G2.add_transition(&ESTADO1_G2, &ESTADO3_G2,
                         a3, NULL);
    G2.add_transition(&ESTADO2_G2, &ESTADO1_G2,
                         b2, NULL);
    G2.add_transition(&ESTADO3_G2, &ESTADO1_G2,
                         b3, NULL);
    
    // Função de transição de G3
    G3.add_transition(&ESTADO1_G3, &ESTADO2_G3,
                         a4, NULL);
    G3.add_transition(&ESTADO1_G3, &ESTADO3_G3,
                         a5, NULL);
    G3.add_transition(&ESTADO1_G3, &ESTADO4_G3,
                         a6, NULL);                     
    G3.add_transition(&ESTADO2_G3, &ESTADO1_G3,
                         b4, NULL);
    G3.add_transition(&ESTADO3_G3, &ESTADO1_G3,
                         b5, NULL);
    G3.add_transition(&ESTADO4_G3, &ESTADO1_G3,
                         b6, NULL);
    
    // Função de transição de G5                    
    G5.add_transition(&ESTADO1_G5, &ESTADO1_G5,
                         bv, NULL);
    G5.add_transition(&ESTADO1_G2, &ESTADO1_G2,
                         ba, NULL);
    
    // Função de transição de G6
    G6.add_transition(&ESTADO1_G6, &ESTADO1_G6,
                         bp, NULL);
    G6.add_transition(&ESTADO1_G6, &ESTADO1_G6,
                         bg, NULL);
                             

    // Inicia o funcionamento dos automatos das plantas, iniciando no estado 1
    G1.run_machine();
    G2.run_machine();
    G3.run_machine();
    G5.run_machine();
    G6.run_machine();
    
  }

