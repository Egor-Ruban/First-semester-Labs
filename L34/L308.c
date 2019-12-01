#include <stdio.h>
#include "MP.h"
int main(){
	printf("Enter a, b, h: a<b, h<b-a\n");
	int a,b,h;
	scanf("%d%d%d",&a,&b,&h);	
	Func308(a,b,h);
	scanf("%d",&b);
	return 0;
}