#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "MyLib.h"

void First(){
		fflush(stdin);
		int n;
		printf("Введите размер массива\n");
		scanf("%d",&n);
		int arr[n];
		printf("Введите массив\n");	
		ScanArr(n, arr);
		PrintArr(n-1,arr,0);
		printf("Теперь я сам сгенерирую числа в пределах от -100 до 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
}

void Second(){
		fflush(stdin);
		int n;
		printf("Введите размер массива\n");
		scanf("%d",&n);
		int arr[n], Xarr[n], Yarr[n];
		printf("Создадим массив рандомно от -100 до 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
		CreateArr(n,arr,Xarr,Yarr);
		printf("Выведем X\n");
		PrintArr(n-1,Xarr,0);
		printf("Выведем Y\n");
		PrintArr(n-1,Yarr,0);
		
		
}

void Third(){
		fflush(stdin);
		int n;
		printf("Введите размер массива\n");
		scanf("%d",&n);
		int arr[n];
		printf("Создадим массив рандомно от -100 до 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
		CheckArr(n,arr);
}

void Fourth(){
		fflush(stdin);
		int n;
		int AdMin, AdMax;
		printf("Введите размер массива\n");
		scanf("%d",&n);
		int arr[n];
		printf("Создадим массив рандомно от -100 до 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
		AdMin=FindMin(n,arr);
		AdMax=FindMax(n,arr);
		printf("AdMin is %d and AdMax is %d\n",AdMin,AdMax);
		PrintArr(AdMax,arr,AdMin);
}

void Fifth(){
		fflush(stdin);
		int n,X;
		printf("Введите размер массива и необходимый X\n");
		scanf("%d%d",&n,&X);
		int arr[n];
		printf("Создадим массив рандомно от -100 до 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
		SearchForX(n,arr,X);
}

void Sixth(){
		fflush(stdin);
		int n,X,ost;
		printf("Введите степень полинома и необходимый X\n");
		scanf("%d%d",&n,&X);
		int arr[n+1];
		printf("Введите коэффициенты полинома от старшего члена к младшему\n");	
		ScanArr(n+1, arr);
		PrintArr(n,arr,0);
		printf("значение полинома в точке %d равен %d\n",X,Gorn(n,arr,X));
}

void Seventh(){
		fflush(stdin);
		int n;
		printf("Введите кол-во переменных\n");
		scanf("%d",&n);
		n=pow(2,n);
		_Bool arr[n];
		fflush(stdin);
		printf("Введите вектор значений\n");
		ScanBool(n, arr);
		PrintBool(n,arr);
		ClassBool(n,arr);
}


void Zero(){
		char a = ' ';
	do{
		printf("Какую функцию необходимо проверить?\n");
		printf("введи номер нужной функции\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("Выбрана первая функция - ввод и вывод массива, заполнение массива рандомными символами\n");
				First();	
				break;
			case '2':
				printf("Выбрана вторая функция - построение дополнительных массивов по спец. правилам\n");
				Second();
				break;
			case '3':
				printf("Выбрана третья функция - определение двух идущих подряд элементов одного знака\n");
				Third();
				break;
			case '4':
				printf("Выбрана четвертая функция - вывод части массива межуд минимальным и максимальным элементом\n");
				Fourth();
				break;
			case '5':
				printf("Выбрана пятая функция - Поиск элемента в неупорядоченном массиве\n");
				Fifth();
				break;
			case '6':
				printf("Выбрана шестая функция - вычисление значение многочлена по схеме Горнера\n");
				Sixth();
				break;
			case '7':
				printf("Выбрана седьмая функция - Определение принадлежности к стандартным классам булевой функции\n");
				Seventh();
				break;
		}
		printf("Если хотите продолжить - нажмите пробел\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}

