/*		1) Написат функции посимвольного ввода и вывода BigBool и операции над ними
		2) Вывести номера единичных компонент вектора X
 		3) Написать функцию, определяющую сравнимы ли два булевых вектора
		4) В булевой матрцие подсчитать число единиц на главной диагонали
		5) написать функцию циклического сдвига булевого вектор
*/

#include "MyLib.h"
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

void First(){		//1) Написат функции посимвольного ввода и вывода BigBool и операции над ними
	fflush(stdin);
	//========================================
	BoolV *vec1,*vec2;
	printf("ну давай, введи свой первый вектор:  ");
	char* S;
	S = ScanStr(S);
	vec1 = ReadBoolV(S);
	printf("ну давай, введи свой второй вектор:  ");
	S = ScanStr(S);
	vec2 = ReadBoolV(S);
	printf("Всё верно?\n");
	PrintfBoolV(vec1);
	PrintfBoolV(vec2);
	printf("Инверсия первого: ");
	PrintfBoolV(InvBoolV(vec1));
	printf("Конъюнкция: ");
	PrintfBoolV(ConBoolV(vec1,vec2));
	printf("Дизъюнкция: ");
	PrintfBoolV(DisBoolV(vec1,vec2));
	//=========================================
	free(S);
	FreeBoolV(vec1);
	FreeBoolV(vec2);				
}

void Second(){			//2) Вывести номера единичных компонент вектора X
	fflush(stdin);
	BoolV *vec;
	printf("ну давай, введи свой первый вектор: ");
	char* S;
	S = ScanStr(S);
	vec = ReadBoolV(S);
	//int* adr = (int*)malloc(sizeof(int));
	//int Len = 1;
	for(int i = 0; i<vec->lenb;i++){
		if(NormTakeBool(vec,i)){
			printf("%d, ",i);
			//adr[Len-1]=i;
			//Len++;
			//adr = (int*)realloc(adr,Len*sizeof(int));
		}
	}

	//for(int i = 0; i<Len-1;i++)
	//	printf("%d\t",adr[i]);
	printf("\n");
	free(S);
	FreeBoolV(vec);
	fflush(stdin);
}

void Third(){			//3) Написать функцию, определяющую сравнимы ли два булевых вектора
	fflush(stdin);
	BoolV *vec1,*vec2;
	printf("ну давай, введи свой первый вектор:  ");
	char* S;
	S = ScanStr(S);
	vec1 = ReadBoolV(S);
	printf("ну давай, введи свой второй вектор:  ");
	S = ScanStr(S);
	vec2 = ReadBoolV(S);
	printf("%d\n",isCompBoolV(vec1,vec2));
	free(S);
	FreeBoolV(vec1);
	FreeBoolV(vec2);		
}

void Four(){			//4) В булевой матрцие подсчитать число единиц на главной диагонали
	fflush(stdin);
	BoolV** BoolM;
	BoolM = CreateBoolM();
	printf("Num of One`s is %d\n",NumOfOne(BoolM));
	
}

void Five(){			//5) написать функцию циклического сдвига булевого вектор
		fflush(stdin);
	BoolV *vec;
	printf("ну давай, введи свой первый вектор: ");
	char* S;
	S = ScanStr(S);
	vec = ReadBoolV(S);
	printf("На сколько будем сдвигать (влево)?	");
	int shift;
	scanf("%d",&shift);
	vec = LShiftBoolV(vec,shift);
	PrintfBoolV(vec);

}


void Zero(){
		char a = ' ';
	do{
		printf("Какую функцию необходимо проверить?\n 1) вектора и операции над ними\n 2) поиск единичных компонент\n 3) сравнимы ли вектора\n");
		printf(" 4) подсчёт единиц в булевой матрцие\n 5) циклический сдвиг вектора\n");
		printf("введи номер нужной функции\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("Выбрана первая функция\n");
				First();	
				break;
			case '2':
				printf("Выбрана вторая функция\n");
				Second();
				break;
			case '3':
				printf("Выбрана третья функция\n");
				Third();
				break;
			case '4':
				printf("Выбрана четвертая функция\n");
				Four();
				break;
			case '5':
				printf("Выбрана пятая функция\n");
				Five();
				break;

		}
		printf("Если хотите повторить - введите пробел\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}


