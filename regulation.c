#include "regulation.h"
	 
float regulationTest(int regul,float csgn,float* tabT, int nT){
  float cmd = 100.;
  int i;

  //calcul de la derniere commande de chauffage en fonction de regul
  if(regul == 1){
    cmd = ToR(csgn, tabT[nT-1]);//tout ou rien on calcul pour la derniere valeur
  }else if(regul == 2){
    PID_param p = {1,0.1,0.1, 10, 0, 0, 0};
    //PID on doit mesurer depuis el debut afin d'avoir de bonnes valeur de I et de l'erreur precedente
    for(i=0; i<nT; i++){
      cmd = PID(csgn, tabT[i], &p);
    }
  }

  //on retourne la derniere commande
  return cmd;
}

float ToR(float csgn, float Tint){
  if(csgn > Tint){
    return 40.0;
  }
  return 0.0;
}

float PID(float csgn, float Tint, PID_param *param){
  static float integral = 0;
  float P,I,D, error, derivated, result;
  
  error = csgn - Tint;

  P = param->Kp * error;

  if(param->t){
    //si t != 0 alors on calcule les valeurs de I et D normalement
    integral += (error + param->lasterror)/2 *param->dt;
    derivated = (error - param->lasterror) / param->t;
    I = param->Ki * integral;
    D = param->Kd * derivated;
  }else{
    //si t == 0 alors les valeurs de I et D doivent valoir 0
    I =0;
    D = 0;
  }
  
  result = P+I+D;

  //on verifie si  la puissance est bien dans les bornes
  if(result > 100){
    result = 100;
  }else if(result < 0){
    result = 0;
  }

  //on met a jour les valeurs de param pour la prochaine iteration
  param->lasterror = error;
  param->lastTint = Tint;
  param->t += param->dt;
  
  return result;
}
