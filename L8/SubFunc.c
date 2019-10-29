#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void RandArrFT(int *arr, int n, int from, int to){
	for(int i = 0; i<n; i++){
		arr[i]=rand()%(to+1)+from;
	}
}
void RandArr(int *arr, int n){
	RandArrFT(arr,n,-100,100);
}

void PrintArrFT(int *arr, int from, int to){
	for(int i = from; i<to; i++){
		printf("[%d] = %d\n",i,arr[i]);
	}
}

void PrintArr(int *arr, int n){
	PrintArrFT(arr,0,n);
}
char* ScanStr(char *str){
	long sLen = 0;
	char ch;
	str = (char*)malloc(0*sizeof(char));
    while((ch = getchar()) != '\n')
    {
	sLen++;
        str = (char*)realloc(str,((sLen))*sizeof(char));
        str[sLen-1] = ch;
    }
	sLen++;
        str = (char*)realloc(str,((sLen))*sizeof(char));
    	str[sLen-1] = '\0';
	return str;
}

void change(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SortArr(int n, int *a){
	int min;
	for(int i=0;i<n-1;i++){
		min = i;
		for(int j=i+1;j<n;j++){
			if(*(a+j)<*(a+min)){
				min = j;
			}
		}
		change((a+min),(a+i));
	}
}

	
	