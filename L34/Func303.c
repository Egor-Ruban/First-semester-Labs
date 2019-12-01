#include <stdio.h>
#include "MP.h"
void Func303(int a, int b){
	int count = 0;
	while(a<b){
		count++;
		printf("%d (pow by %d) < %d\n",a,count,b);
		a*=a;
	}
	scanf("%d",&count);
}