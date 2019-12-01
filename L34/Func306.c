#include <stdio.h>
#include "MP.h"
void Func306(int n, float y){
	float S = 0;
	int i=0;
	while(i<n){
		i++;
		S+=(float)y/(2*i);
	}
	printf("S is %.5f\n",S);
}