#include <stdio.h>
#include <math.h>
#include "MP.h"
void Func308(int a, int b, int h){
	int fh=0;
	int H=0;
	for(;a+H<=b;){
		printf("%d\t",a+H);
		H=H+h;
	}
	printf("\n");
	for(;a+fh<=b;){
		printf("%.3f\t",log(1+a+fh));
		fh+=h;
	}

}


