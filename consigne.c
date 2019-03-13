#include "consigne.h"

float consigne(float csgn)
{
  //on verifie l'acces au fichier
  if( access( ".verrouConsigne", F_OK ) == -1 ){
    //on ouvre les fichiers
    FILE* verrou = fopen(".verrouConsigne", "w");
    FILE* consigne = fopen("consigne.txt", "r");

    fseek(consigne, 0, SEEK_SET);

    //on lit la consigne
    fscanf(consigne, "%f", &csgn);

    //on libere les fichiers
    fclose(consigne);
    fclose(verrou);
    remove(".verrouConsigne");
  }
  //on retourne la consigne
  return csgn;
}
