#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
<<<<<<< HEAD
#include "releve.h"
#include "commande.h"
=======
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"
#include "regulation.h"
>>>>>>> 7f9508c14a3cefa7db5897eb579b2278217a9151

int main(){
  FT_HANDLE descr;
  temp_t temperature;
  temperature.exterieure = 14.0;
  temperature.interieure = 15.0;
<<<<<<< HEAD
  descr = initUSB();
  temperature = releve(descr);
  struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisï¿½e ï¿½ 0%
  int i=0; // increment de boucle
  float puissance = 70.0; // puissance de chauffage
  for(i=0;i< 30;i++){
=======
  struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
  float puissance = 0.0, csgn=5; // puissance de chauffage
  float tempInt[50],nT = 50;

  visualisationT(temperature);
  visualisationC(puissance);   

  while((int)csgn != 5){
    
    csgn = consigne(csgn);    
    puissance = ToR(csgn, temperature.interieure);
>>>>>>> 7f9508c14a3cefa7db5897eb579b2278217a9151
    temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
  }
  
  simDestruct(monSimulateur_ps); // destruction de simulateur
  commande(descr,40);
  FT_Close(descr);
  return EXIT_SUCCESS;
}

