#include <stdio.h>
#include "MP.h"
int main(){
	printf("Enter k \n");
	int k, Fibk;
	scanf("%d",&k);	
	Fibk = Func312(k);
	printf("Fibk is %d \n",Fibk);
	scanf("%d",&k);
	return 0;
}