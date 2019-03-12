#include "commande.h"

void commande(FT_HANDLE ftHandle, float cmd){
    FT_STATUS ftStatus;
    DWORD BytesWritten;
    char TxBuffer[1] = {0};     //TxBuffer correspond aux octets envoyés par la suite, on enverra un seul octet
    char puis = (int)cmd*1.27;      //calcul de la puissance à partir de la commande

    TxBuffer[0] = puis&0x7F;        //Le premier octet est affecté, on y met puis avec le premier bit à 0

    ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);       //On écrit grâce à FT_Write() et ftStatus = FT_OK si l'écriture est faite
    if (ftStatus == FT_OK) {
        // FT_Write OK
    }else {
        // FT_Write Failed
    }
}
