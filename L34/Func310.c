#include <stdio.h>
#include <math.h>
#include "MP.h"
void Func310(int x, int p){
	int a=0;
	while(x!=0){
		x=x/p;
		a++;
	}
	printf("x in p base contains %d digits", a);
}