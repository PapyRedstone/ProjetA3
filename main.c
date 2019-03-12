#include <stdio.h>
#include <stdlib.h>
#include "integration.h"

int main(){
  /*  temp_t temperature;
  temperature.exterieure = 14.0;
  temperature.interieure = 15.0;
  struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
  float puissance = 0.0, csgn=5; // puissance de chauffage
  float tempInt[50],nT = 50;

  visualisationT(temperature);
  visualisationC(puissance);   

  while((int)csgn != 5){
    
    csgn = consigne(csgn);    
    puissance = ToR(csgn, temperature.interieure);
    temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
  }
  
  simDestruct(monSimulateur_ps); // destruction de simulateur*/

  temp_t tInit = {25.12,24.64};
  tInit.interieure = 14;
  tInit.exterieure = 14;

  integrationTest(2, tInit, 100);
    
  return EXIT_SUCCESS;
}

