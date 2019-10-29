/*	1) для случайного целочисленного массива сформировать массив указателей на нулевые элементы массива 
	2) для строки с предложением сформировать массив указателей на начала слов в предложении (на ту букву - которая после пробела по массиву)
	3) считать список (ФИО) через перенаправление ввода. ввести какое-нибудь имя (в консоль). вывести всех студентовы с этим именем
	4) сформировать массив указателей на упорядоченные подпоследовательности в массиве (разбить данный массив на упорядоченные подмассивы)
	5) скопировать содержимое построчно из одного текстового файла в другой, фильтруя по ключевому слову, введенному в консоль
	6) отсортировать содержимое двух файлов и записать результат в третий (можно полностью считать документ) (хз) 
*/

#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void First(){			//  1) для случайного целочисленного массива сформировать массив указателей на нулевые элементы массива 
		fflush(stdin);
		int arrn = rand()%30 + 1, ptrn = 0;
		int *arr;
		arr = (int*)malloc(arrn*sizeof(int));  //рандомим массив в интервале -5 -> 5
		RandArrFT(arr,arrn,-5,5);
		int **ptr;
		ptr = (int**)malloc(ptrn * sizeof(int));
		for(int i = 0; i<arrn;i++){
			if(arr[i]==0){
				ptrn++;
				ptr = (int**)realloc(ptr, ptrn*sizeof(int));
				ptr[ptrn-1] = &arr[i];
			}
		}
		PrintArr(arr,arrn);
		printf("There is %d of zero`s\n",ptrn);
		for(int i = 0; i<ptrn; i++){
			printf("%d\n",ptr[i]);
		}
		free(ptr);
		free(arr);
		
}

void Second(){//	2) для строки с предложением сформировать массив указателей на начала слов в предложении (на ту букву - которая после пробела по массиву)
	fflush(stdin);
	char *str;
	printf("Enter string :\n");
	str = ScanStr(str);    //вводим строку и там же выделяем ей память
	char **ptr;
	ptr = (char**)malloc(1*sizeof(char*));
	int i = 1;
	int sLen = 1;
	ptr[0] = &str[0];	//считаем, что пользователь начнет с воода слова и адрес первого элемента сразу сохраним
	while(str[i]!='\0'){
		if(str[i-1] == ' ' && str[i]!=' '){  //считаем, что пробел знаменует новое слово
			sLen++;		
			ptr =(char**)realloc(ptr,sLen*sizeof(char*));
			ptr[sLen-1]=&str[i];
		}
		i++;
	}
	printf("There is %d words\n",sLen);
	free(str);
	free(ptr);
			
}


void Third(){//		3) считать список (ФИО) через перенаправление ввода. ввести какое-нибудь имя (в консоль). вывести всех студентовы с этим именем
    fflush(stdin);
//================================================================================================
	FILE* tin;
	tin = freopen("C:\\gcc\\L8\\txt\\fio.txt","r+",stdin);
   	char ***name = (char***)malloc(sizeof(char**));		 //дальше я очень некрасиво создаю массив куда из файла считываю всю базу
	name[0] = (char**)malloc(3*sizeof(char*)); 	 	 //в person - кол-во людей-1
	for(int j = 0;j<3;j++)                     		 //в name вся база
		name[0][j] = (char*)malloc(sizeof(char));
	int i = 0;
	int nn = 0;
	int person = 0;
	char c;
	while((c=getchar())!=EOF){
		if(c=='\n'){
			name[person][nn][i] = '\0';
			person++;
			name = (char***)realloc(name,(person+1)*sizeof(char**));
			name[person] = (char**)malloc(3*sizeof(char*));
			for(int j = 0;j<3;j++)
				name[person][j] = (char*)malloc(sizeof(char));
			nn = 0;
			i = 0;
		}else if(c==' '){
			name[person][nn][i] = '\0';
			nn++;
			i = 0;
		} else {
			name[person][nn][i] = c;
			i++;
			name[person][nn] = (char*)realloc(name[person][nn],(i+1)*sizeof(char));	
		}
	}
	name[person][nn][i] = '\0';
	freopen("CONIN$","r+",tin);
//========================================================================================
	char *str;
	printf("Введите имя: ");
	str = ScanStr(str);
	for(int j = 0; j<=person;j++){
		if(strcmp(str,name[j][1])==0){
			printf("%s %s %s\n",name[j][0],name[j][1],name[j][2]);
		}
	}
	for(int j = 0;j<=person;j++){
		for(int i =0;i<3;i++)
			free(name[j][i]);
		free(name[j]);
	}
	free(name);
	free(str);
}		
	

void Four(){//		4) сформировать массив указателей на упорядоченные подпоследовательности в массиве (разбить данный массив на упорядоченные подмассивы)
		fflush(stdin);
		int arrn = rand()%15 + 1, ptrn = 1;
		int *arr;
		arr = (int*)malloc(arrn*sizeof(int));  //рандомим массив в интервале (0;15)
		RandArrFT(arr,arrn,0,15);
		int **ptr;
		ptr = (int**)malloc(ptrn * sizeof(int));
		ptr[0] = &arr[0];
		for(int i = 1; i<arrn;i++){
			if(arr[i]<=arr[i-1]){        // если какое-то число прерывает упорядоченную последовательность - оно является началом новой
				ptrn++;
				ptr = (int**)realloc(ptr, ptrn*sizeof(int));
				ptr[ptrn-1] = &arr[i];
			}
		}
		PrintArr(arr,arrn);
		printf("There is %d of subarrs\n",ptrn);
		for(int i = 0; i<ptrn; i++){
			printf("%d - %d\n",ptr[i],*ptr[i]);
		}
		free(ptr);
		free(arr);
}

void Five(){//		5) скопировать содержимое построчно из одного текстового файла в другой, фильтруя по ключевому слову, введенному в консоль
		fflush(stdin);
		printf("Введите фильтр-слово: ");
		char *filtr;				
		filtr = ScanStr(filtr);

		FILE* tin = freopen("C:\\gcc\\L8\\txt\\InFilt.txt","r+",stdin);
		FILE* tout = freopen("C:\\gcc\\L8\\txt\\OutFilt.txt","w+",stdout);
		char *strin;
		strin = (char*)malloc(sizeof(char));
		char c;
		int i = 0;
		while((c=getchar())!=EOF){
			strin[i] = c;
			i++;
			strin = (char*)realloc(strin,(i+1)*sizeof(char));
			if(c=='\n'){
				strin[i-1] = '\0';
				if(strstr(strin,filtr)!=NULL){
					printf("%s\n",strin);
				}
				free(strin);
				i=0;
				strin = (char*)malloc(sizeof(char));
			}
		}
		strin[i] = '\0';
		if(strstr(strin,filtr)!=NULL){
			printf("%s\n",strin);
		}
		freopen("CONOUT$","w+",tout);
		freopen("CONIN$","r+",tin);
		printf("check results in OutFilt.txt");
		free(filtr);
		free(strin);
}
//==============================================================================
//==============================================================================
void Six(){//		6) отсортировать содержимое двух файлов и записать результат в третий (можно полностью считать документ) (хз) 
		fflush(stdin);
		
	FILE* tout;
	FILE* tin;					
	tin = freopen("C:\\gcc\\L8\\txt\\N1.txt","r+",stdin);
		
	int *arr;
	int i = 0;
	arr = (int*)malloc(sizeof(int));
	char c;
	int num = 0;

//===========================================================================
	while((c=getchar())!=EOF){
		if(c==' '||c=='\n'){
			arr[i]=num;
			i++;
			arr = (int*)realloc(arr,(i+1)*sizeof(int));
			num = 0;								//считывание первого файла
		} else {
			num=num*10+(int)(c-'0');
		}
	}
	arr[i]=num;
	i++;
	arr = (int*)realloc(arr,(i+1)*sizeof(int));
	num = 0;	
//============================================================================
	tin = freopen("C:\\gcc\\L8\\txt\\N2.txt","r+",tin);	
	while((c=getchar())!=EOF){
		if(c==' '||c=='\n'){
			arr[i]=num;
			i++;
			arr = (int*)realloc(arr,(i+1)*sizeof(int));				//считывание второго файла
			num = 0;
		} else {
			num=num*10+(int)(c-'0');
		}
	}
	arr[i]=num;
	i++;
	freopen("CONIN$","r+",tin);
//==============================================================================
		SortArr(i,arr);						//сортировка полученного результата
//==============================================================================
		tout = freopen("C:\\gcc\\L8\\txt\\N3.txt","w+",stdout);
		int count = 0;
		for(int j = 0; j<i;j++){
			if(count==6){
				printf("\n");				//вывод в N3
				count=0;
			}
			printf("%d\t",arr[j]);
			count++;
		}
		freopen("CONOUT$","w+",tout);
//==============================================================================
		printf("проверьте результат в N3.txt\n");
		free(arr);
}
//==============================================================================
//==============================================================================
void Zero(){
		char a = ' ';
	do{
		printf("Какую функцию необходимо проверить?\n");
		printf(" 1) массив указателей на двумерный массив \n 2) массив указателей на предложение \n 3) база по ФИО \n");
		printf(" 4) неупорядоченный массив в упорядоченные массивы\n 5) фильтр текстового файла  \n");
		printf(" 6) сортировка двух текстовых файлов \n");
		printf("введи номер нужной функции\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("Выбрана первая функция \n");
				First();	
				break;
			case '2':
				printf("Выбрана вторая функция \n");
				Second();
				break;
			case '3':
				printf("Выбрана третья функция \n");
				Third();
				break;
			case '4':
				printf("Выбрана четвертая функция \n");
				Four();
				break;
			case '5':
				printf("Выбрана пятая функция \n");
				Five();
				break;
			case '6':
				printf("Выбрана шестая функция \n");
				Six();
				break;

		}
		printf("Если хотите повторить - введите пробел\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}


