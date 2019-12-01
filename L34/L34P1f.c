#include <stdio.h>
void GCD1(int a, int b){

	int counter = 0;
	int c=a,d=b; 
	printf("Finding GCD by division\n");

	while(a>0&&b>0){
		if(a>b){	
			counter++;
			a%=b;
		} else {
			counter++;
			b%=a;
		}
	}

	if(a>b){
		printf("GCD is %d and it took %d operations\n",a,counter);
	
	} else {
		printf("GCD is %d and it took %d operations\n",b,counter);
	}
	int counter1 = counter;
	a=c; b=d; counter=0;
	printf("Finding GCD by submision\n");
	while(a>0&&b>0){
		if(a>b){
			counter++;
			a-=b;
		} else {
			counter++;
			b-=a;
		}
	}

	if(a>b){
		printf("GCD is %d and it took %d operations\n",a,counter);
	
	} else {
		printf("GCD is %d and it took %d operations\n",b,counter);
	}
	if(counter1 < counter){
		printf("finding GCD by division more effective");
	} else {
		printf("finding GCD by submision more effective");
	}
	scanf("%d",counter);
		
}