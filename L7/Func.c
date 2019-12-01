#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void First(){
		fflush(stdin);
		int *Matrix;
		int n,m;
		printf("Введите кол-во строк и кол-во столбцов\n");
		scanf("%d%d",&n,&m);
		Matrix = (int*)malloc(n*m * sizeof(int));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним матрицу числами от -100 до 100");
				RandMatrix(n, m, Matrix);
		} else if(c=='2') {
				printf("введите матрицу\n");
				ScanMatrix(n, m, Matrix);

		}
		PrintMatrix(n, m, Matrix);	
}

void Second(){
		fflush(stdin);
		int *Matrix;
		int n;
		printf("Введите кол-во строк \n");
		scanf("%d",&n);
		Matrix = (int*)malloc(n*n * sizeof(int));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним матрицу числами от -100 до 100");
				RandMatrix(n, n, Matrix);
				PrintMatrix(n,n,Matrix);
		} else if(c=='2') {
				printf("введите матрицу\n");
				ScanMatrix(n, n, Matrix);
		}
		printf("а после транспонирования:\n");
		TrMat(n,Matrix);
		PrintMatrix(n,n,Matrix);
}

void Third(){
		fflush(stdin);
		int *Matrix1,*Matrix2;
		int n1,m1,n2,m2;
		printf("Введите кол-во строк и кол-во столбцов первой матрицы\n");
		scanf("%d%d",&n1,&m1);
		Matrix1 = (int*)malloc(n1*m2 * sizeof(int));

		printf("Введите кол-во строк и кол-во столбцов второй матрицы\n");
		scanf("%d%d",&n2,&m2);
		Matrix2 = (int*)malloc(n2*m2 * sizeof(int));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним матрицу числами от -100 до 100");
				RandMatrix(n1, m1, Matrix1);
				PrintMatrix(n1,m1,Matrix1);
				RandMatrix(n2, m2, Matrix2);
				PrintMatrix(n2,m2,Matrix2);
				printf("\n");
		} else if(c=='2') {
				printf("введите первую матрицу\n");
				ScanMatrix(n1, m1, Matrix1);
				printf("введите вторую матрицу\n");
				ScanMatrix(n2, m2, Matrix2);
		}
		int *Matrix;
		int n,m;
		n=n1; m=m2;
		Matrix = (int*)malloc(n*m * sizeof(int));
		MulMat(Matrix1,n1,m1,Matrix2,n2,m2,Matrix);
		PrintMatrix(n,m,Matrix);
}

void Four(){
		fflush(stdin);
		char *str;
		int n;
		printf("Введите кол-во элементов \n");
		scanf("%d",&n);
		str = (char*)malloc(n * sizeof(char));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним строку символами 32-126\n");
				RandStr(n,str);
				PrintStr(n,str);
		} else if(c=='2') {
				printf("введите строку\n");
				ScanStr(n,str);
		}
		printf("\n какой длины будет подстрока?\n");
		fflush(stdin);
		int l=0,k=0;
		char *substr;
		scanf("%d",&l);
		printf("C какого элемента начинаться?\n");
		scanf("%d",&k);
		substr = (char*)malloc(n * sizeof(char));

		CopyArrFT(k,l,str,substr);
		PrintStr(l,substr);
		printf("\n");		
}

void Five(){  //можно сделать намного короче и красивее, но мне дьявол нашептал сделать именно так - через задницу и самым извращенным методом
		fflush(stdin);
		int *Arr;
		int n;
		printf("Введите кол-во элементов\n");
		scanf("%d",&n);
		Arr = (int*)malloc(n * sizeof(int));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним массив числами от -100 до 100\n");
				RandArr(n, Arr);
		} else if(c=='2') {
				printf("введите массив\n");
				ScanArr(n, Arr);

		}
		SortArrBub(n,Arr);  //можно закоментить сортировку - работать все-равно будет. не убрал, потому что не зря же я сюда сортировку добавлял
		PrintArr(n, Arr);
		L705(n,Arr);	
		
}

void Six(){
		fflush(stdin);
		int *Arr;
		int n;
		printf("Введите кол-во элементов\n");
		scanf("%d",&n);
		Arr = (int*)malloc(n * sizeof(int));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним массив числами от -100 до 100\n");
				RandArr(n, Arr);
				for(int i = 0; i<n; i++){
					Arr[i]%=2;
				}
		} else if(c=='2') {
				printf("введите массив\n");
				ScanArr(n, Arr);

		}
		PrintArr(n,Arr);
		FZ(n,Arr);
		
}

void Seven(){
		fflush(stdin);
		printf("В разработке\n");
		int n;
		printf("Введите кол-во строк \n");
		scanf("%d",&n);
		float **Mat;
		Mat = (float**)malloc(n * sizeof(float*));
		for (int i = 0; i<n; i++)
			Mat[i] = (float*)malloc(n * sizeof(float*));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним матрицу числами от -100 до 100");
				RandMatrixF(n, n, Mat);
				PrintMatrixF(n,n,Mat);
		} else if(c=='2') {
				printf("введите матрицу\n");
				ScanMatrixF(n, n, Mat);
		}
		printf("а диагональная выглядит так:\n");
		DiagMat(n,Mat);
		PrintMatrixF(n,n,Mat);

}

void Eight(){
		fflush(stdin);
		int *Matrix;
		int n;
		printf("Введите кол-во строк \n");
		scanf("%d",&n);
		Matrix = (int*)malloc(n*n * sizeof(int));
		printf("зарандомим (1) или введем сами (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("заполним матрицу числами от -100 до 100");
				RandMatrix(n, n, Matrix);
				PrintMatrix(n,n,Matrix);
		} else if(c=='2') {
				printf("введите матрицу\n");
				ScanMatrix(n, n, Matrix);
		}
		int **Mat;
		Mat = (int**)malloc(n * sizeof(int*));
		for (int i = 0; i<n; i++)
			Mat[i] = (int*)malloc(n * sizeof(int*));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				Mat[i][j]=*(Matrix+i*n+j);
			}
		}	
		free(Matrix);
		printf("определитель равен: %d\n",DetMat(n,Mat));
		
}

void Nine(){
		fflush(stdin);
		char *str;
		int n;
		printf("Введите кол-во элементов \n");
		scanf("%d",&n);
		str = (char*)malloc(n * sizeof(char));
		printf("введите строку\n");
		fflush(stdin);
		ScanStr(n,str);
		PrintStr(n,str);
		int p;
		printf("Какая величина сдвига?\t");
		fflush(stdin);
		scanf("%d",&p);
		Cstr(n,str,p);
		PrintStr(n,str);

		Dstr(n,str,p);
		PrintStr(n,str);
}


void Zero(){
		char a = ' ';
	do{
		printf("Какую функцию необходимо проверить?\n 1) ввод и вывод матрицы \n 2) транспонирование квадратной матрицы \n 3) умножение матриц \n");
		printf(" 4) копирование подстроки\n 5) поиск максимально повторяющегося числа  \n 6) поиск самой длинной последовательности нулей \n");
		printf(" 7*) приведение квадратной матрциы к треугольной \n 8*) вычисление определителя матрицы \n 9*) шифр Цезаря \n");
		printf("введи номер нужной функции\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("Выбрана первая функция - ввод и вывод матрицы \n");
				First();	
				break;
			case '2':
				printf("Выбрана вторая функция - транспонирование квадратной матрицы \n");
				Second();
				break;
			case '3':
				printf("Выбрана третья функция - умножение матриц\n");
				Third();
				break;
			case '4':
				printf("Выбрана четвертая функция - копирование подстроки\n");
				Four();
				break;
			case '5':
				printf("Выбрана пятая функция - поиск максимально повторяющегося числа\n");
				Five();
				break;
			case '6':
				printf("Выбрана шестая функция - поиск самой длинной последовательности нулей\n");
				Six();
				break;
			case '7':
				printf("Выбрана седьмая* функция - приведение квадратной матрицы к треугольной\n");
				Seven();
				break;
			case '8':
				printf("Выбрана восьмая* функция - вычисление определителя матрицы\n");
				Eight();
				break;
			case '9':
				printf("Выбрана девятая* функция - шифр Цезаря\n");
				Nine();
				break;

		}
		printf("Если хотите повторить - введите пробел\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}


