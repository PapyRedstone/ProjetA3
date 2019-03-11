#include "visualisationT.h"

void visualisationT(temp_t myTemp){
  if( access( ".verrouData", F_OK ) == -1 ){
    FILE* verrou = fopen(".verrouData", "w");
    FILE* data = fopen("data.txt", "w");

    fseek(data, 0, SEEK_SET);
    
    fprintf(data, "%.2f\n", myTemp.exterieure);
    fprintf(data, "%.2f\n", myTemp.interieure);
    fprintf(data, "true\n");
    
    fclose(data);
    fclose(verrou);
    remove(".verrouData");
  }
}
