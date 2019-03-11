#include "regulation.h"
	 
float regulationTest(int regul,float csgn,float* tabT, int nT){
  float cmd = 100.;

  if(regul == 1){
    cmd = ToR(csgn, tabT[nT-1]);
  }else{
    cmd = PID(csgn, tabT, nT);
  }
  
  return cmd;
}

float ToR(float csgn, float Tint){
  if(csgn > Tint){
    return 40.0;
  }
  return 0.0;
}

float PID(float csgn, float* tabT, int nT){
  float Kp = 1, Ki = 0.1, Kd = 0.1, P,I,D, error, sum_error = 0, last_error;
  int i;
  //compute errors
  for(i=0; i<nT; i++){
    last_error = error;
    error = tabT[i] - csgn;
    sum_error += error;
  }

  P = Kp * error;
  I = Ki * sum_error;
  D = Kd * (error - last_error);

  return P+I+D;
}
