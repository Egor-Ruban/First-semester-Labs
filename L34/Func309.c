#include <stdio.h>
#include <math.h>
#include "MP.h"
void Func309(float x, float EPS){
	float b=1, k=0;
	float NF, TF=0;
	NF = log(x+1);
	for(int i = 1;fabs(b)>=EPS;i++){
		b = pow(-1,i+1)*(float)(pow(x,i)/i);
		TF+=b;
	}
	printf("NF is %.10f and TF is %.10f\n",NF, TF);
}