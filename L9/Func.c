/*		1) ������� ������� ������������� ����� � ������ BigBool � �������� ��� ����
		2) ������� ������ ��������� ��������� ������� X
 		3) �������� �������, ������������ �������� �� ��� ������� �������
		4) � ������� ������� ���������� ����� ������ �� ������� ���������
		5) �������� ������� ������������ ������ �������� ������
*/

#include "MyLib.h"
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

void First(){		//1) ������� ������� ������������� ����� � ������ BigBool � �������� ��� ����
	fflush(stdin);
	//========================================
	BoolV *vec1,*vec2;
	printf("�� �����, ����� ���� ������ ������:  ");
	char* S;
	S = ScanStr(S);
	vec1 = ReadBoolV(S);
	printf("�� �����, ����� ���� ������ ������:  ");
	S = ScanStr(S);
	vec2 = ReadBoolV(S);
	printf("�� �����?\n");
	PrintfBoolV(vec1);
	PrintfBoolV(vec2);
	printf("�������� �������: ");
	PrintfBoolV(InvBoolV(vec1));
	printf("����������: ");
	PrintfBoolV(ConBoolV(vec1,vec2));
	printf("����������: ");
	PrintfBoolV(DisBoolV(vec1,vec2));
	//=========================================
	free(S);
	FreeBoolV(vec1);
	FreeBoolV(vec2);				
}

void Second(){			//2) ������� ������ ��������� ��������� ������� X
	fflush(stdin);
	BoolV *vec;
	printf("�� �����, ����� ���� ������ ������: ");
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

void Third(){			//3) �������� �������, ������������ �������� �� ��� ������� �������
	fflush(stdin);
	BoolV *vec1,*vec2;
	printf("�� �����, ����� ���� ������ ������:  ");
	char* S;
	S = ScanStr(S);
	vec1 = ReadBoolV(S);
	printf("�� �����, ����� ���� ������ ������:  ");
	S = ScanStr(S);
	vec2 = ReadBoolV(S);
	printf("%d\n",isCompBoolV(vec1,vec2));
	free(S);
	FreeBoolV(vec1);
	FreeBoolV(vec2);		
}

void Four(){			//4) � ������� ������� ���������� ����� ������ �� ������� ���������
	fflush(stdin);
	BoolV** BoolM;
	BoolM = CreateBoolM();
	printf("Num of One`s is %d\n",NumOfOne(BoolM));
	
}

void Five(){			//5) �������� ������� ������������ ������ �������� ������
		fflush(stdin);
	BoolV *vec;
	printf("�� �����, ����� ���� ������ ������: ");
	char* S;
	S = ScanStr(S);
	vec = ReadBoolV(S);
	printf("�� ������� ����� �������� (�����)?	");
	int shift;
	scanf("%d",&shift);
	vec = LShiftBoolV(vec,shift);
	PrintfBoolV(vec);

}


void Zero(){
		char a = ' ';
	do{
		printf("����� ������� ���������� ���������?\n 1) ������� � �������� ��� ����\n 2) ����� ��������� ���������\n 3) �������� �� �������\n");
		printf(" 4) ������� ������ � ������� �������\n 5) ����������� ����� �������\n");
		printf("����� ����� ������ �������\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("������� ������ �������\n");
				First();	
				break;
			case '2':
				printf("������� ������ �������\n");
				Second();
				break;
			case '3':
				printf("������� ������ �������\n");
				Third();
				break;
			case '4':
				printf("������� ��������� �������\n");
				Four();
				break;
			case '5':
				printf("������� ����� �������\n");
				Five();
				break;

		}
		printf("���� ������ ��������� - ������� ������\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}


