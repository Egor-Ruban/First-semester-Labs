#include <stdio.h>
#include "MP.h"
void Func307(int *a, int i){
	int b=0, g=0;

	printf("first task\n");
	for(int j=0; j<i-1; j++){
		if((a[j]>5)&&(a[j]<15)){
			b++;
		}
		if(a[j]==5){
			g++;
		}
	}
	printf("%d numbers between 5 and 10\n",b);
	b=0;

	printf("second task\n");
	for(int j=0; j<i; j++){
		if(a[j]>7||a[j]<3){
			b++;
		}
	}
	printf("%d numbers not between 3 and 7\n",b);
	b=0;

	printf("third task\n");
	for(int j=0; j<i; j++){
		if(a[j]/100!=0&&a[j]/1000==0){
			b++;
		}
	}
	printf("%d numbers between 99 and 1000\n",b);
	b=1;

	printf("fourth task\n");
	for(int j=0; j<i; j++){
		b*=a[j];
	}
	printf("multiplication of them is %d\n",b);
	b=0;
	
	float avg=0;
	printf("fifth task\n");
	for(int j=0; j<i; j++){
		if(a[j]%2!=0){
			avg+=a[j];
			b++;
		}
	}
	if(b!=0){
		avg/=b;
		printf("average of odd is %.5f\n",avg);
	} else {
		printf("average of odd is 0");
	}
	b=0;

	printf("sixth task\n");
	for(int j=0; j<i; j++){
		if(a[j]==5){
			printf("there were some 5`s\n");
			b++;
		} 
	}
	if(b==0){
		printf("0 5");
	}
	b=0;

	
	printf("seventh task\n");
	for(int j=0; j<i; j++){
		if(a[j]>10){
			printf("%d\n",a[j]);
			break;
		}
		if(j=i-1){
			printf("no\n");
		}
	}
	b=0;

	printf("eighth task\n");
	for(int b=1; b<i;b++){
		if(a[b]<a[b-1]){
			printf("%d\n",b);
			break;
		}
	}
		if(b=i){
			printf("yes\n");
		}
	b=0;
	
	int max, min;
	printf("nineth task\n");
	for(int j=0; j<i; j++){
		if(a[j]>max){
			max=a[j];
		}
		if(a[j]<min){
			min=a[j];
		}
	}
	printf("Minimum num is %d, and max num is %d",min,max);
	b=0;
}