#include <stdio.h>
#include <stdlib.h>
#include "integration.h"
#include "releve.h"
#include "commande.h"

int main(){
  FT_HANDLE descr;
  temp_t temperature = {14,14};
  descr = initUSB();
  temperature = releve(descr);
  float cmd = 0.0, csgn=0; // cmd de chauffage
  PID_param p = {1, 0.01, 0.01, 10, 0, 0, 0};
  
  while(csgn != 5)
    visualisationT(temperature);
    visualisationC(cmd);
    csgn = consigne(csgn);
    cmd = PID(csgn, temperature.interieure, &p);
    temperature = releve(descr);
    commande(descr, cmd)
  }
  
  return EXIT_SUCCESS;
}

