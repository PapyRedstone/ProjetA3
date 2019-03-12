#include "visualisationC.h"


void visualisationC(float puissance_f){
  if( access( ".verrouData", F_OK ) == -1 ){
    FILE* verrou = fopen(".verrouData", "w");
    FILE* data = fopen("data.txt", "r+");

    fseek(data, -5, SEEK_END);

    if((int)puissance_f){
      fprintf(data, "true\n");
    }else{
      fprintf(data, "false\n");
    }
    
    
    fclose(data);
    fclose(verrou);
    remove(".verrouData");
  }
}
