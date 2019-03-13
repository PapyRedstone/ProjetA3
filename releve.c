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
    temperature.interieure = -1;        //Température initialisée à -1 pour traiter les cas d'erreurs ensuite
    temperature.exterieure = -1;        //Température initialisée à -1 pour traiter les cas d'erreurs ensuite
    int SOText = 0, SOTint = 0;                 //Variables permettant la récupération des températures à partir des octets reçus
    FT_STATUS ftStatus;
    DWORD RxBytes = 6;                  //Nombre d'octets que l'on va recevoir
    DWORD BytesReceived;
    char RxBuffer[48];      //RxBuffer correspond aux octets récupérés par la suite, on récupèrera 6 octets

    ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);       //On lit grâce à FT_Read() et ftStatus = FT_OK si la lecture est faite
    if (ftStatus == FT_OK) {
        // FT_Read OK

        switch((RxBuffer[0] & 0xF0) >> 4){      //switch permettant de traiter chaque cas de réception, pour pouvoir identifier chaque octet et les traiter
            case 0:     //1er Quartet de l'octet 1 pour la température extérieure = 0 
                SOText = ((RxBuffer[0] & 0x0F) <<8) | ((RxBuffer[1] & 0x0F) <<4) | (RxBuffer[2] & 0x0F);        //Calcul des températures grâce à RxBuffer
                SOTint = ((RxBuffer[3] & 0x0F) <<8) | ((RxBuffer[4] & 0x0F) <<4) | (RxBuffer[5] & 0x0F);
            break;
            case 1:     //1er Quartet de l'octet 2 pour la température extérieure = 1 
                SOText = ((RxBuffer[5] & 0x0F) <<8) | ((RxBuffer[0] & 0x0F) <<4) | (RxBuffer[1] & 0x0F);        //Calcul des températures grâce à RxBuffer décalé de 1
                SOTint = ((RxBuffer[2] & 0x0F) <<8) | ((RxBuffer[3] & 0x0F) <<4) | (RxBuffer[4] & 0x0F);
            break;
            case 2:     //1er Quartet de l'octet 3 pour la température extérieure = 2 
                SOText = ((RxBuffer[4] & 0x0F) <<8) | ((RxBuffer[5] & 0x0F) <<4) | (RxBuffer[0] & 0x0F);        //Calcul des températures grâce à RxBuffer décalé de 2
                SOTint = ((RxBuffer[1] & 0x0F) <<8) | ((RxBuffer[2] & 0x0F) <<4) | (RxBuffer[3] & 0x0F);
            break;
            case 8:     //1er Quartet de l'octet 1 pour la température intérieure = 8 
                SOText = ((RxBuffer[3] & 0x0F) <<8) | ((RxBuffer[4] & 0x0F) <<4) | (RxBuffer[5] & 0x0F);        //Calcul des températures grâce à RxBuffer décalé de 3
                SOTint = ((RxBuffer[0] & 0x0F) <<8) | ((RxBuffer[1] & 0x0F) <<4) | (RxBuffer[2] & 0x0F);
            break;
            case 9:     //1er Quartet de l'octet 2 pour la température intérieure = 9
                SOText = ((RxBuffer[2] & 0x0F) <<8) | ((RxBuffer[3] & 0x0F) <<4) | (RxBuffer[4] & 0x0F);        //Calcul des températures grâce à RxBuffer décalé de 4
                SOTint = ((RxBuffer[5] & 0x0F) <<8) | ((RxBuffer[0] & 0x0F) <<4) | (RxBuffer[1] & 0x0F);
            break;
            case 10:    //1er Quartet de l'octet 3 pour la tempérture intérieure = 10
                SOText = ((RxBuffer[1] & 0x0F) <<8) | ((RxBuffer[2] & 0x0F) <<4) | (RxBuffer[3] & 0x0F);        //Calcul des températures grâce à RxBuffer décalé de 5
                SOTint = ((RxBuffer[4] & 0x0F) <<8) | ((RxBuffer[5] & 0x0F) <<4) | (RxBuffer[0] & 0x0F);
            break;
            default:

            break;
        }

        temperature.interieure = -39.64 + 0.04 * SOTint;        //Calcul de la température intérieure grâce a SOTint
        temperature.exterieure = -39.64 + 0.04 * SOText;        //Calcul de la température exterieure grâce a SOText

        return temperature;
    }else {
        // FT_Read Failed
        return temperature;     //retourne les températures = -1 si la lecture a échouée
    }
}
