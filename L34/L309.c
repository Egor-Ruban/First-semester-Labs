#include <stdio.h>
#include "MP.h"
int main(){
	printf("Enter x and EPS\n");
	float x;
	float EPS;
	scanf("%f%f",&x,&EPS);	
	
	Func309(x,EPS);
	scanf("%d",&x);
	return 0;
}