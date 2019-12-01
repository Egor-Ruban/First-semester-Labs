#include <stdio.h>
#include "MP.h"
int main(){
	printf("Enter X and P\n");
	int x,p;
	scanf("%d%d",&x,&p);	
	Func310(x,p);
	scanf("%d",&x);
	return 0;
}