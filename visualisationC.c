#include "visualisationC.h"


void visualisationC(float puissance_f){
  //on verifie si l'acces est disponible
  if( access( ".verrouData", F_OK ) == -1 ){
    //on ouvre les fichiers
    FILE* verrou = fopen(".verrouData", "w");
    FILE* data = fopen("data.txt", "r+");

    //on place le curseur correctement
    fseek(data, -5, SEEK_END);

    //on ecrit la bonne valeur
    if((int)puissance_f){
      fprintf(data, "true\n");
    }else{
      fprintf(data, "false\n");
    }
    
    //on libere les fichiers
    fclose(data);
    fclose(verrou);
    remove(".verrouData");
  }
}
