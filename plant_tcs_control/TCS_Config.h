// Biblioteca para manipulação de Autômatos
#include "Fsm.h"
//#include "FiniteStateMachine.h"
//#include "InputsGlobais.h"

  
  TcsAutomataSetup(){
       
    // Inicia o funcionamento dos automatos das plantas, iniciando no estado 1
    G1.run_machine();
    G2.run_machine();
    G3.run_machine();
    G5.run_machine();
    G6.run_machine();
    
    // Inicia o funcionamento dos automatos dos supervisores modulares, iniciando no estado 1
    S1.run_machine();
    S2.run_machine();
    S3.run_machine();
    S4.run_machine();
    S5.run_machine();
    S6.run_machine();
    
    }
  
