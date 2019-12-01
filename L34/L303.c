#include <stdio.h>
#include "MP.h"
int main(){
	printf("Enter A and B, 1<A<B\n");
	int a,b;
	scanf("%d%d",&a,&b);
	Func303(a,b);
	scanf("%d",a);
	return 0;
}