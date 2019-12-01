#include <stdio.h>
#include "MP.h"
int main(){
	printf("Enter A and B\n");
	int A,B;
	scanf("%d%d",&A,&B);	
	
	Func311(A,B);
	scanf("%d",&A);
	return 0;
}