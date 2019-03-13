#include "integration.h"
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"

void integrationTest(int regul,temp_t tInit,int nIterations){
  int i;

  temp_t temperature = tInit;
  struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
  float puissance = 40.0*1.27, csgn=0; // puissance et consigne de chauffage
  PID_param p = {1, 0.01, 0.01, 10, 0, 0, 0};
  
  for(i=0; i<nIterations; i++){
    //on ecrit l'etat actuelle dans data.txt
    visualisationT(temperature);
    visualisationC(puissance);

    //on recupere la consigne dans consigne.txt
    csgn = consigne(csgn);

    //on calcule la puissance du chauffage on fonction de regul
    if(regul == 1){
      puissance = ToR(csgn, temperature.interieure); //Tout ou Rien
    }else{
      puissance = PID(csgn, temperature.interieure, &p); //Proportionnel, Integral, Derive
    }
    
    temperature = simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
  }
}
