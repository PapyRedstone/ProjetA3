#include "visualisationT.h"

void visualisationT(temp_t myTemp){
  if( access( ".verrouData", F_OK ) == -1 ){
    

    
    remove(".verrouData");
  }
}
