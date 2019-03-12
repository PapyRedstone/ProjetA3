#include "define.h" 

typedef struct{
  float Kp,Kd,Ki;
  float dt;
  float t;
  float lastTint;
  float lasterror;
}PID_param;

float regulationTest(int regul,float csgn,float* tabT, int nT);

float ToR(float csgn, float Tint);
float PID(float csgn, float Tint, PID_param *param);
