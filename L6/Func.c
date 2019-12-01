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
		printf("������� ������ �������\n");
		scanf("%d",&n);
		arr = (int*)malloc(n * sizeof(int));
		arr1 = (int*)malloc(n * sizeof(int));
		printf("�������� ������ ������� �� -100 �� 100\n");
		RandArr(n, arr);
		PrintArr(n,arr);

		CopyArr(n,arr,arr1);
		printf("����������� ����������:\n");
		SortArrBub(n,arr1);
		PrintArr(n,arr1);
		free(arr1);

		CopyArr(n,arr,arr1);
		printf("���������� �������\n");
		SortArrSel(n,arr1);
		PrintArr(n,arr1);
		free(arr1);
		
		CopyArr(n,arr,arr1);
		printf("���������� ���������\n");
		SortArrIns(n,arr1);
		PrintArr(n,arr1);
		free(arr1);
			
}

void Second(){
		fflush(stdin);
		int *arr;
		int n,X;
		printf("������� ������ �������\n");
		scanf("%d",&n);
		arr = (int*)malloc(n * sizeof(int));
		printf("�������� ������ ������� �� -100 �� 100\n");
		RandArr(n, arr);
		SortArrSel(n,arr);
		PrintArr(n,arr);
		printf("����� ����� ����� ������?\t");
		scanf("%d",&X);
		

		printf("����� � �����:\n");
		SearchForX(n,arr,X);

		printf("�������� �����:\n");
		int result = SearchForXBin(0,n-1,X,arr);
		if(result == -1) {
			printf( "��� �����\n");
		} else {
			printf("X ��������� �� %d-�� �����\n ",result);
		}
		free(arr);
}

void Third(){
		fflush(stdin);
		int *arr, *arr1;
		int n,X;
		printf("������� ������ �������\n");
		scanf("%d",&n);
		arr = (int*)malloc(n * sizeof(int));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������ ������� �� -100 �� 100\n");
				RandArr(n, arr);
				SortArrSel(n,arr);
				PrintArr(n,arr);
		} else if(c=='2') {
				printf("������� ������\n");
				ScanArr(n, arr);
				SortArrSel(n,arr);
				PrintArr(n,arr);
		}
		n = FewArr(n,arr);
		printf("� ����� ���������� ��������, size = %d:\n",n);
		arr = NewArr(n,arr);
		PrintArr(n,arr);
		
}


void Zero(){
		char a = ' ';
	do{
		printf("����� ������� ���������� ���������?\n 1) ����������\n 2) ����� ��������\n 3) ���������� �������\n");
		printf("����� ����� ������ �������\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("������� ������ ������� - ���������� �������:\n 1) ���������\n 2) �������\n 3) ��������� \n");
				First();	
				break;
			case '2':
				printf("������� ������ ������� - ����� ��������:\n 1) ���������� ����������\n 2) �������� ������� \n");
				Second();
				break;
			case '3':
				printf("������� ������ ������� - ���������� �������\n");
				Third();
				break;

		}
		printf("���� ������ ��������� - ������� ������\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}


