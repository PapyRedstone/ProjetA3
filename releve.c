#include "releve.h"

FT_HANDLE initUSB(){
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        // FT_Open failed
        return NULL;
    }else{
        return ftHandle;
    }
}

temp_t releve(FT_HANDLE ftHandle){

    temp_t temperature;
    temperature.interieure = 0;
    temperature.exterieure = 0;
    FT_STATUS ftStatus;
    DWORD EventDWord;
    DWORD TxBytes;
    int SOText = 0, SOTint = 0;
    int i;
    int j = 0;
    DWORD RxBytes;
    DWORD BytesReceived;
    char RxBuffer[256];


    FT_GetStatus(ftHandle,&RxBytes,&TxBytes,&EventDWord);
    while(RxBytes < 0);

    ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
    if (ftStatus == FT_OK) {
        // FT_Read OK
        printf("In");
        for(i=0;i<sizeof(RxBuffer);i++){
            printf("%d", RxBuffer[i]);
        }

        for(i=0;i<11;i++){
            SOTint = SOTint + (2048/pow(2,i))*RxBuffer[i+4+j];
            if(i==3||i==7){
                j = j+4;
            }
        }
        temperature.interieure = -39.64 + 0.04 * SOTint;
        printf("%d",SOTint);

        j = 0;
        for(i=0;i<11;i++){
            SOText = SOText + (2048/pow(2,i))*RxBuffer[i+28+j];
            if(i==3||i==7){
                j = j+4;
            }
        }
        temperature.exterieure = -39.64 + 0.04 * SOText;
        printf("%d",SOText);

        return temperature;
    }else {
        // FT_Read Failed
        printf("Erreur 2");
        return temperature;
    }
}
