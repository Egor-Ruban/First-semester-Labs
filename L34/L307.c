#include <stdio.h>
#include "MP.h"
int main(){
	int a[100];
	printf("Enter row with '0'at the end\n");
	int b;
	int i;
	for(i=0;b!=0;i++){
		scanf("%d",&b);
		a[i] = b;	
	}
	i--;
	Func307(a,i);
	scanf("%d",&b);
	return 0;
}