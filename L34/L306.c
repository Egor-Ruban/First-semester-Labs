#include <stdio.h>
#include "MP.h"
int main(){
	printf("Enter natural even n and real y\n");
	int n;
	float y;
	scanf("%d%f",&n,&y);
	Func306(n,y);
	scanf("%d",&n);
	return 0;
}