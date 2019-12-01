#include <stdio.h>
#include "MP.h"
int main(){
	char a;
	printf("Enter two numbers to find GCD");
	int c,b;
	scanf("%d%d",&b,&c);
	GCD1(c,b);
	scanf("%c",&a);
	return 0;
}