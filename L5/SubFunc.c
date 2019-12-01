#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>
#include "MyLib.h"

void ScanArr(int n, int *a){
	for(int i = 0; i<n; i++){
		scanf("%d",&a[i]);
	}
}


void PrintArr(int n, int *a, int k){
	if(k<n){
		for(int i = k; i<=n; i++){
			printf("arr[%d] = %d\n",i,a[i]);
		}
	} else {
		for(int i = n; i<=k; i++){
			printf("arr[%d] = %d\n",i,a[i]);
		}
	}
}

int FindMin(int n, int *a){
	int Min = a[0];
	int AdMin = 0;
	for(int i = 1; i<n; i++){
		if(a[i]<Min){
			Min = a[i];
			AdMin = i;
		}
	}
	return AdMin;
}

int FindMax(int n, int *a){
	int Max = a[0];
	int AdMax = 0;
	for(int i = 1; i<n; i++){
		if(a[i]>Max){
			Max = a[i];
			AdMax = i;
		}
	}
	return AdMax;
}

void RandArr(int n, int *a){
	srand(time(NULL));
	for(int i = 0; i<n; i++){
		a[i] = -100 + rand()%201;
	}
}

void CreateArr(int n, int *arr, int *X, int *Y){
	for(int i=0;i<n;i++){
		if(arr[i]>=0){
			X[i] = arr[i];
			Y[i] = 1;
		} else{
			X[i] = -1;
			Y[i] = arr[i];
		}
	}
}

void CheckArr(int n, int *arr){
	int check=0;
	for(int i = 1; i<n; i++){
		if(arr[i]<0&&arr[i-1]<0||arr[i]>0&&arr[i-1]>0){
			printf("На %d-ом и %d-ом местах идут числа с одинаковыми знаками\n",i-1,i);
			check++;
		} else if (arr[i]==0&&arr[i-1]==0){
			printf("На %d-ом и %d-ом местах идут нули\n",i-1,i);
			check++;
		}
	}
	if(check==0){
		printf("В массиве нет двух идущих подряд чисел с одинаковыми знаками\n");
	}
}

void SearchForX(int n, int *a, int X){
	int count = 0;
	for(int i = 1; i<n; i++){
		if(a[i]==X){
			printf("X находится на %d-ом месте\n",i);
			count++;
		}
	}
	if(count==0){
		printf("Здесь нет иксов\n");
	}
}

int Gorn(int n, int *a, int X){
	int ost = a[0];
	for(int i = 1; i<=n; i++){
		ost=X*ost+a[i];
	}
	return ost;
}

void ScanBool(int n, _Bool *a){
	char c;
	
	for(int i=0; i<n; i++){
		scanf("%c",&c);
		if(c=='0'){
			a[i]=0;
		} else {
			a[i]=1;
		}
	}
}

void PrintBool(int n, _Bool *a){
		for(int i = 0; i<n; i++){
			printf("%d",a[i]);
		}
		printf("\n");
}

void ClassBool(int n, _Bool *a){
		if(a[0]==0){
			printf("Функция принадлежит к Т0\n");
		}
		if(a[n-1]==1){
			printf("Функция принадлежит к Т1\n");
		}
		int check = 0, i = 0;
		do{
			if(a[i]==a[n-1-i]){
				check++;
			}
			i++;
		}while(i<=n/2);
		if(check==0){
			printf("Функция принадлежит к S\n");
		}
}

	
		
		

	
	