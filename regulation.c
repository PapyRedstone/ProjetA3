#include "regulation.h"
	 
float regulationTest(int regul,float csgn,float* tabT, int nT){
  float cmd = 100.;
  int i;
  
  if(regul == 1){
    cmd = ToR(csgn, tabT[nT-1]);
  }else if(regul == 2){
    PID_param p = {1,0.1,0.1, 10, 0, 0, 0};
    for(i=0; i<nT; i++){
      cmd = PID(csgn, tabT[i], &p);
    }
  }
  
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
    integral += (error + param->lasterror)/2 *param->dt;
    derivated = (error - param->lasterror) / param->t;
    I = param->Ki * integral;
    D = param->Kd * derivated;
  }else{
    I =0;
    D = 0;
  }
  
  result = P+I+D;
  
  if(result > 100){
    result = 100;
  }else if(result < 0){
    result = 0;
  }
  
  param->lasterror = error;
  param->lastTint = Tint;
  param->t += param->dt;
  
  return result;
}
