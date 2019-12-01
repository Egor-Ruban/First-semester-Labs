#include <stdio.h>
#include "MP.h"
void Func305(int a){
	int S = 0;
	while(a!=0){
		S+=a%10;
		a/=10;
	}
	printf("S is %d\n",S);
}