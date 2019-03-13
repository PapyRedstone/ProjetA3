#include "visualisationT.h"

void visualisationT(temp_t myTemp){
  //verifie si l'acces est disponible
  if( access( ".verrouData", F_OK ) == -1 ){
    //ouvre les fichiers
    FILE* verrou = fopen(".verrouData", "w");
    FILE* data = fopen("data.txt", "w");

    fseek(data, 0, SEEK_SET);

    //ecrit les donnees
    fprintf(data, "%.2f\n", myTemp.exterieure);
    fprintf(data, "%.2f\n", myTemp.interieure);
    fprintf(data, "true\n");//etat du chauffage par default

    //on libere les fichiers
    fclose(data);
    fclose(verrou);
    remove(".verrouData");
  }
}
