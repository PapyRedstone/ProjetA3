#include "consigne.h"

float consigne(float csgn)
{
  if( access( ".verrouConsigne", F_OK ) == -1 ){
    FILE* verrou = fopen(".verrouConsigne", "w");
    FILE* consigne = fopen("consigne.txt", "r");

    fseek(consigne, 0, SEEK_SET);
    
    fscanf(consigne, "%f", &csgn);
    
    fclose(consigne);
    fclose(verrou);
    remove(".verrouConsigne");
  }
  return csgn;
}
