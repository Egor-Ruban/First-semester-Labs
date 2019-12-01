#include <stdio.h>
#include <math.h>
#include "MP.h"
void Func311(int a, int b){
	int GCD,LCM;
	LCM = a*b;
	while(a>0&&b>0){
		if(a>b){	
			a%=b;
		} else {
			b%=a;
		}
	}
	if(a==0){
		GCD = b;
	} else {
		GCD = a;
	}
	LCM/=GCD;
	printf("LCM is %d\n",LCM);
}


