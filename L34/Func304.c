#include <stdio.h>
#include "MP.h"
void Func304(int a){
	float S = 0;
	int  n = 1;
	while(S<a){
		S+=(float)1/n;
		n++;
	}
	printf("n is %d and S is %.5f\n",n,S);
}