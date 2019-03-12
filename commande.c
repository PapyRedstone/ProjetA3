#include "commande.h"

void commande(FT_HANDLE ftHandle, float cmd){
    FT_STATUS ftStatus;
    DWORD BytesWritten;
    char TxBuffer[256];
    int puis = (int)cmd*1.27;

    TxBuffer[0] = 0;
    for(int i=0;i<6;i++){
        TxBuffer[i+1] = (int)(puis/pow(2,6-i));
        puis = puis - TxBuffer[i]*pow(2,6-i);
    }

    ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);
    if (ftStatus == FT_OK) {
        // FT_Write OK
    }else {
        // FT_Write Failed
    }
}
