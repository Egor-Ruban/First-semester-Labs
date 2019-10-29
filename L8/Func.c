/*	1) ��� ���������� �������������� ������� ������������ ������ ���������� �� ������� �������� ������� 
	2) ��� ������ � ������������ ������������ ������ ���������� �� ������ ���� � ����������� (�� �� ����� - ������� ����� ������� �� �������)
	3) ������� ������ (���) ����� ��������������� �����. ������ �����-������ ��� (� �������). ������� ���� ���������� � ���� ������
	4) ������������ ������ ���������� �� ������������� ��������������������� � ������� (������� ������ ������ �� ������������� ����������)
	5) ����������� ���������� ��������� �� ������ ���������� ����� � ������, �������� �� ��������� �����, ���������� � �������
	6) ������������� ���������� ���� ������ � �������� ��������� � ������ (����� ��������� ������� ��������) (��) 
*/

#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void First(){			//  1) ��� ���������� �������������� ������� ������������ ������ ���������� �� ������� �������� ������� 
		fflush(stdin);
		int arrn = rand()%30 + 1, ptrn = 0;
		int *arr;
		arr = (int*)malloc(arrn*sizeof(int));  //�������� ������ � ��������� -5 -> 5
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

void Second(){//	2) ��� ������ � ������������ ������������ ������ ���������� �� ������ ���� � ����������� (�� �� ����� - ������� ����� ������� �� �������)
	fflush(stdin);
	char *str;
	printf("Enter string :\n");
	str = ScanStr(str);    //������ ������ � ��� �� �������� �� ������
	char **ptr;
	ptr = (char**)malloc(1*sizeof(char*));
	int i = 1;
	int sLen = 1;
	ptr[0] = &str[0];	//�������, ��� ������������ ������ � ����� ����� � ����� ������� �������� ����� ��������
	while(str[i]!='\0'){
		if(str[i-1] == ' ' && str[i]!=' '){  //�������, ��� ������ ��������� ����� �����
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


void Third(){//		3) ������� ������ (���) ����� ��������������� �����. ������ �����-������ ��� (� �������). ������� ���� ���������� � ���� ������
    fflush(stdin);
//================================================================================================
	FILE* tin;
	tin = freopen("C:\\gcc\\L8\\txt\\fio.txt","r+",stdin);
   	char ***name = (char***)malloc(sizeof(char**));		 //������ � ����� ��������� ������ ������ ���� �� ����� �������� ��� ����
	name[0] = (char**)malloc(3*sizeof(char*)); 	 	 //� person - ���-�� �����-1
	for(int j = 0;j<3;j++)                     		 //� name ��� ����
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
	printf("������� ���: ");
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
	

void Four(){//		4) ������������ ������ ���������� �� ������������� ��������������������� � ������� (������� ������ ������ �� ������������� ����������)
		fflush(stdin);
		int arrn = rand()%15 + 1, ptrn = 1;
		int *arr;
		arr = (int*)malloc(arrn*sizeof(int));  //�������� ������ � ��������� (0;15)
		RandArrFT(arr,arrn,0,15);
		int **ptr;
		ptr = (int**)malloc(ptrn * sizeof(int));
		ptr[0] = &arr[0];
		for(int i = 1; i<arrn;i++){
			if(arr[i]<=arr[i-1]){        // ���� �����-�� ����� ��������� ������������� ������������������ - ��� �������� ������� �����
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

void Five(){//		5) ����������� ���������� ��������� �� ������ ���������� ����� � ������, �������� �� ��������� �����, ���������� � �������
		fflush(stdin);
		printf("������� ������-�����: ");
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
void Six(){//		6) ������������� ���������� ���� ������ � �������� ��������� � ������ (����� ��������� ������� ��������) (��) 
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
			num = 0;								//���������� ������� �����
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
			arr = (int*)realloc(arr,(i+1)*sizeof(int));				//���������� ������� �����
			num = 0;
		} else {
			num=num*10+(int)(c-'0');
		}
	}
	arr[i]=num;
	i++;
	freopen("CONIN$","r+",tin);
//==============================================================================
		SortArr(i,arr);						//���������� ����������� ����������
//==============================================================================
		tout = freopen("C:\\gcc\\L8\\txt\\N3.txt","w+",stdout);
		int count = 0;
		for(int j = 0; j<i;j++){
			if(count==6){
				printf("\n");				//����� � N3
				count=0;
			}
			printf("%d\t",arr[j]);
			count++;
		}
		freopen("CONOUT$","w+",tout);
//==============================================================================
		printf("��������� ��������� � N3.txt\n");
		free(arr);
}
//==============================================================================
//==============================================================================
void Zero(){
		char a = ' ';
	do{
		printf("����� ������� ���������� ���������?\n");
		printf(" 1) ������ ���������� �� ��������� ������ \n 2) ������ ���������� �� ����������� \n 3) ���� �� ��� \n");
		printf(" 4) ��������������� ������ � ������������� �������\n 5) ������ ���������� �����  \n");
		printf(" 6) ���������� ���� ��������� ������ \n");
		printf("����� ����� ������ �������\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("������� ������ ������� \n");
				First();	
				break;
			case '2':
				printf("������� ������ ������� \n");
				Second();
				break;
			case '3':
				printf("������� ������ ������� \n");
				Third();
				break;
			case '4':
				printf("������� ��������� ������� \n");
				Four();
				break;
			case '5':
				printf("������� ����� ������� \n");
				Five();
				break;
			case '6':
				printf("������� ������ ������� \n");
				Six();
				break;

		}
		printf("���� ������ ��������� - ������� ������\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}


