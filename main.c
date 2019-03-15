#include <stdio.h>
#include <stdlib.h>
#include "regulation.h"
#include "visualisationT.h"
#include "visualisationC.h"
#include "consigne.h"
#include "releve.h"
#include "commande.h"

int main(){
  FT_HANDLE descr;
  temp_t temperature = {14,14};
  descr = initUSB();
  temperature = releve(descr);
  float cmd = 0.0, csgn=0; // cmd de chauffage
  PID_param p = {1, 0.01, 0.01, 10, 0, 0, 0};
  
  while(csgn != 5){
      if(temperature.interieure != -1){
      visualisationT(temperature);
      visualisationC(cmd);
      csgn = consigne(csgn);
      cmd = PID(csgn, temperature.interieure, &p);
      commande(descr, cmd);
    }
    temperature = releve(descr);
  }

  commande(dscr, 0);
  FT_Close(dscr);
  
  return EXIT_SUCCESS;
}

