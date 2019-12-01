#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void First(){
		fflush(stdin);
		int *arr,*arr1;
		int n;
		printf("введите размер массива\n");
		scanf("%d",&n);
		arr = (int*)malloc(n * sizeof(int));
		arr1 = (int*)malloc(n * sizeof(int));
		printf("заполним массив числами от -100 до 100\n");
		RandArr(n, arr);
		PrintArr(n,arr);

		CopyArr(n,arr,arr1);
		printf("пузырьковая сортировка:\n");
		SortArrBub(n,arr1);
		PrintArr(n,arr1);
		free(arr1);

		CopyArr(n,arr,arr1);
		printf("Сортировка выбором\n");
		SortArrSel(n,arr1);
		PrintArr(n,arr1);
		free(arr1);
		
		CopyArr(n,arr,arr1);
		printf("Сортировка вставками\n");
		SortArrIns(n,arr1);
		PrintArr(n,arr1);
		free(arr1);
			
}

void Second(){
		fflush(stdin);
		int *arr;
		int n,X;
		printf("введите размер массива\n");
		scanf("%d",&n);
		arr = (int*)malloc(n * sizeof(int));
		printf("заполним массив числами от -100 до 100\n");
		RandArr(n, arr);
		SortArrSel(n,arr);
		PrintArr(n,arr);
		printf("какое число будем искать?\t");
		scanf("%d",&X);
		

		printf("поиск в тупую:\n");
		SearchForX(n,arr,X);

		printf("бинарный поиск:\n");
		int result = SearchForXBin(0,n-1,X,arr);
		if(result == -1) {
			printf( "нет иксов\n");
		} else {
			printf("X находится на %d-ом месте\n ",result);
		}
		free(arr);
}

void Third(){
		fflush(stdin);
		int *arr, *arr1;
		int n,X;
		printf("введите размер массива\n");
		scanf("%d",&n);
		arr = (int*)malloc(n * sizeof(int));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним массив числами от -100 до 100\n");
				RandArr(n, arr);
				SortArrSel(n,arr);
				PrintArr(n,arr);
		} else if(c=='2') {
				printf("введите массив\n");
				ScanArr(n, arr);
				SortArrSel(n,arr);
				PrintArr(n,arr);
		}
		n = FewArr(n,arr);
		printf("а после уплотнения поулчаем, size = %d:\n",n);
		arr = NewArr(n,arr);
		PrintArr(n,arr);
		
}


void Zero(){
		char a = ' ';
	do{
		printf("Какую функцию необходимо проверить?\n 1) сортировка\n 2) поиск элемента\n 3) уплотнение массива\n");
		printf("введи номер нужной функции\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("Выбрана первая функция - Сортировка массива:\n 1) пузырьком\n 2) выбором\n 3) вставками \n");
				First();	
				break;
			case '2':
				printf("Выбрана вторая функция - поиск элемента:\n 1) простейшим алгоритмом\n 2) бинарным поиском \n");
				Second();
				break;
			case '3':
				printf("Выбрана третья функция - уплотнение массива\n");
				Third();
				break;

		}
		printf("Если хотите повторить - введите пробел\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}


