#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void ScanArr(int n, int *a){
	for(int i = 0; i<n; i++){
		fflush(stdin);
		scanf("%d",*(a+i));
	}
}


void PrintArr(int n, int *a){
		for(int i = 0; i<n; i++){
			printf("\tarr[%d] = %d\n",i,*(a+i));
		}
}

void change(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void CopyArr(int n, int *arr, int *a){
	for(int i = 0;i<n;i++){
		*(a+i)=*(arr+i);
	}
}

void SortArrBub(int n, int *a){
	int check, it = 0;
	for(int i=0;i<n;i++){
		check = 0;
		for(int j=0;j<n-i-1;j++){
			if(*(a+j)>*(a+j+1)){
				change((a+j),(a+j+1));
				check++;
				it++;
			}
		}
		if(check == 0){
			printf("it took %d iterations:\n",it);
			break;
		}
	}
}

void SortArrSel(int n, int *a){
	int min;
	int it = 0;
	for(int i=0;i<n-1;i++){
		min = i;
		for(int j=i+1;j<n;j++){
			if(*(a+j)<*(a+min)){
				min = j;
				it++;
			}
		}
		change((a+min),(a+i));
	}
	printf("it took %d iterations:\n",it);
}

void SortArrIns(int n, int *a){
	int it = 0;
	int j;
	for(int i = 1; i<n;i++){
		j=i;
		while (j>0&& *(a+j-1)>*(a+j)){
			change((a+j),(a+j-1));
			j--;
			it++;
		}
	}
	printf("it took %d iterations:\n",it);
}

void RandArr(int n, int *a){
	for(int i = 0; i<n; i++){
		a[i] = -100 + rand()%201;
	}
}

void SearchForX(int n, int *a, int X){
	int count = 0;
	for(int i = 0; i<n; i++){
		if(*(a+i)==X){
			printf("\tX находится на %d-ом месте\n",i);
			count++;
		}
	}
	if(count==0){
		printf("Здесь нет иксов\n");

	}	
}

int SearchForXBin(int s, int n, int X, int *a){
	

	if(n>=s){
		int div = s+(n-s)/2;
		if( a[div]==X ) {
			return div;
		} else if ( a[div]>X ) {
			return SearchForXBin(s,div-1,X,a);
		} else {
			return SearchForXBin(div+1,n,X,a);
		}	
	}
	return -1;
}

int FewArr(int n,int *a){



	int j,it=0;
	for(int i = 1; i<n;i++){
		j=i;
		while(a[i]==a[i-1]){
			j=i;
			it++;
			while (j<n-1){
				change((a+j),(a+j+1));
				j++;
				
			}
		}
	}

	return n-it;
	
}

int* NewArr(int n, int *arr){
		int *arr1;
		arr1 = (int*)malloc( n * sizeof(int));
		CopyArr(n,arr,arr1);
		arr=arr1;
		return arr1;
}
		
	

	
		
		

	
	