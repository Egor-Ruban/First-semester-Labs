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
		printf("������� ������ �������\n");
		scanf("%d",&n);
		int arr[n];
		printf("������� ������\n");	
		ScanArr(n, arr);
		PrintArr(n-1,arr,0);
		printf("������ � ��� ���������� ����� � �������� �� -100 �� 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
}

void Second(){
		fflush(stdin);
		int n;
		printf("������� ������ �������\n");
		scanf("%d",&n);
		int arr[n], Xarr[n], Yarr[n];
		printf("�������� ������ �������� �� -100 �� 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
		CreateArr(n,arr,Xarr,Yarr);
		printf("������� X\n");
		PrintArr(n-1,Xarr,0);
		printf("������� Y\n");
		PrintArr(n-1,Yarr,0);
		
		
}

void Third(){
		fflush(stdin);
		int n;
		printf("������� ������ �������\n");
		scanf("%d",&n);
		int arr[n];
		printf("�������� ������ �������� �� -100 �� 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
		CheckArr(n,arr);
}

void Fourth(){
		fflush(stdin);
		int n;
		int AdMin, AdMax;
		printf("������� ������ �������\n");
		scanf("%d",&n);
		int arr[n];
		printf("�������� ������ �������� �� -100 �� 100\n");
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
		printf("������� ������ ������� � ����������� X\n");
		scanf("%d%d",&n,&X);
		int arr[n];
		printf("�������� ������ �������� �� -100 �� 100\n");
		RandArr(n,arr);
		PrintArr(n-1,arr,0);
		SearchForX(n,arr,X);
}

void Sixth(){
		fflush(stdin);
		int n,X,ost;
		printf("������� ������� �������� � ����������� X\n");
		scanf("%d%d",&n,&X);
		int arr[n+1];
		printf("������� ������������ �������� �� �������� ����� � ��������\n");	
		ScanArr(n+1, arr);
		PrintArr(n,arr,0);
		printf("�������� �������� � ����� %d ����� %d\n",X,Gorn(n,arr,X));
}

void Seventh(){
		fflush(stdin);
		int n;
		printf("������� ���-�� ����������\n");
		scanf("%d",&n);
		n=pow(2,n);
		_Bool arr[n];
		fflush(stdin);
		printf("������� ������ ��������\n");
		ScanBool(n, arr);
		PrintBool(n,arr);
		ClassBool(n,arr);
}


void Zero(){
		char a = ' ';
	do{
		printf("����� ������� ���������� ���������?\n");
		printf("����� ����� ������ �������\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("������� ������ ������� - ���� � ����� �������, ���������� ������� ���������� ���������\n");
				First();	
				break;
			case '2':
				printf("������� ������ ������� - ���������� �������������� �������� �� ����. ��������\n");
				Second();
				break;
			case '3':
				printf("������� ������ ������� - ����������� ���� ������ ������ ��������� ������ �����\n");
				Third();
				break;
			case '4':
				printf("������� ��������� ������� - ����� ����� ������� ����� ����������� � ������������ ���������\n");
				Fourth();
				break;
			case '5':
				printf("������� ����� ������� - ����� �������� � ��������������� �������\n");
				Fifth();
				break;
			case '6':
				printf("������� ������ ������� - ���������� �������� ���������� �� ����� �������\n");
				Sixth();
				break;
			case '7':
				printf("������� ������� ������� - ����������� �������������� � ����������� ������� ������� �������\n");
				Seventh();
				break;
		}
		printf("���� ������ ���������� - ������� ������\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}

