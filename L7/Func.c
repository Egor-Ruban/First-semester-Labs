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
		printf("������� ���-�� ����� � ���-�� ��������\n");
		scanf("%d%d",&n,&m);
		Matrix = (int*)malloc(n*m * sizeof(int));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������� ������� �� -100 �� 100");
				RandMatrix(n, m, Matrix);
		} else if(c=='2') {
				printf("������� �������\n");
				ScanMatrix(n, m, Matrix);

		}
		PrintMatrix(n, m, Matrix);	
}

void Second(){
		fflush(stdin);
		int *Matrix;
		int n;
		printf("������� ���-�� ����� \n");
		scanf("%d",&n);
		Matrix = (int*)malloc(n*n * sizeof(int));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������� ������� �� -100 �� 100");
				RandMatrix(n, n, Matrix);
				PrintMatrix(n,n,Matrix);
		} else if(c=='2') {
				printf("������� �������\n");
				ScanMatrix(n, n, Matrix);
		}
		printf("� ����� ����������������:\n");
		TrMat(n,Matrix);
		PrintMatrix(n,n,Matrix);
}

void Third(){
		fflush(stdin);
		int *Matrix1,*Matrix2;
		int n1,m1,n2,m2;
		printf("������� ���-�� ����� � ���-�� �������� ������ �������\n");
		scanf("%d%d",&n1,&m1);
		Matrix1 = (int*)malloc(n1*m2 * sizeof(int));

		printf("������� ���-�� ����� � ���-�� �������� ������ �������\n");
		scanf("%d%d",&n2,&m2);
		Matrix2 = (int*)malloc(n2*m2 * sizeof(int));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������� ������� �� -100 �� 100");
				RandMatrix(n1, m1, Matrix1);
				PrintMatrix(n1,m1,Matrix1);
				RandMatrix(n2, m2, Matrix2);
				PrintMatrix(n2,m2,Matrix2);
				printf("\n");
		} else if(c=='2') {
				printf("������� ������ �������\n");
				ScanMatrix(n1, m1, Matrix1);
				printf("������� ������ �������\n");
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
		printf("������� ���-�� ��������� \n");
		scanf("%d",&n);
		str = (char*)malloc(n * sizeof(char));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������ ��������� 32-126\n");
				RandStr(n,str);
				PrintStr(n,str);
		} else if(c=='2') {
				printf("������� ������\n");
				ScanStr(n,str);
		}
		printf("\n ����� ����� ����� ���������?\n");
		fflush(stdin);
		int l=0,k=0;
		char *substr;
		scanf("%d",&l);
		printf("C ������ �������� ����������?\n");
		scanf("%d",&k);
		substr = (char*)malloc(n * sizeof(char));

		CopyArrFT(k,l,str,substr);
		PrintStr(l,substr);
		printf("\n");		
}

void Five(){  //����� ������� ������� ������ � ��������, �� ��� ������ �������� ������� ������ ��� - ����� ������� � ����� ����������� �������
		fflush(stdin);
		int *Arr;
		int n;
		printf("������� ���-�� ���������\n");
		scanf("%d",&n);
		Arr = (int*)malloc(n * sizeof(int));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������ ������� �� -100 �� 100\n");
				RandArr(n, Arr);
		} else if(c=='2') {
				printf("������� ������\n");
				ScanArr(n, Arr);

		}
		SortArrBub(n,Arr);  //����� ����������� ���������� - �������� ���-����� �����. �� �����, ������ ��� �� ��� �� � ���� ���������� ��������
		PrintArr(n, Arr);
		L705(n,Arr);	
		
}

void Six(){
		fflush(stdin);
		int *Arr;
		int n;
		printf("������� ���-�� ���������\n");
		scanf("%d",&n);
		Arr = (int*)malloc(n * sizeof(int));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������ ������� �� -100 �� 100\n");
				RandArr(n, Arr);
				for(int i = 0; i<n; i++){
					Arr[i]%=2;
				}
		} else if(c=='2') {
				printf("������� ������\n");
				ScanArr(n, Arr);

		}
		PrintArr(n,Arr);
		FZ(n,Arr);
		
}

void Seven(){
		fflush(stdin);
		printf("� ����������\n");
		int n;
		printf("������� ���-�� ����� \n");
		scanf("%d",&n);
		float **Mat;
		Mat = (float**)malloc(n * sizeof(float*));
		for (int i = 0; i<n; i++)
			Mat[i] = (float*)malloc(n * sizeof(float*));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������� ������� �� -100 �� 100");
				RandMatrixF(n, n, Mat);
				PrintMatrixF(n,n,Mat);
		} else if(c=='2') {
				printf("������� �������\n");
				ScanMatrixF(n, n, Mat);
		}
		printf("� ������������ �������� ���:\n");
		DiagMat(n,Mat);
		PrintMatrixF(n,n,Mat);

}

void Eight(){
		fflush(stdin);
		int *Matrix;
		int n;
		printf("������� ���-�� ����� \n");
		scanf("%d",&n);
		Matrix = (int*)malloc(n*n * sizeof(int));
		printf("���������� (1) ��� ������ ���� (2)?\n");
		char c;
		fflush(stdin);
		scanf("%c",&c);
		if(c=='1'){
				printf("�������� ������� ������� �� -100 �� 100");
				RandMatrix(n, n, Matrix);
				PrintMatrix(n,n,Matrix);
		} else if(c=='2') {
				printf("������� �������\n");
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
		printf("������������ �����: %d\n",DetMat(n,Mat));
		
}

void Nine(){
		fflush(stdin);
		char *str;
		int n;
		printf("������� ���-�� ��������� \n");
		scanf("%d",&n);
		str = (char*)malloc(n * sizeof(char));
		printf("������� ������\n");
		fflush(stdin);
		ScanStr(n,str);
		PrintStr(n,str);
		int p;
		printf("����� �������� ������?\t");
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
		printf("����� ������� ���������� ���������?\n 1) ���� � ����� ������� \n 2) ���������������� ���������� ������� \n 3) ��������� ������ \n");
		printf(" 4) ����������� ���������\n 5) ����� ����������� �������������� �����  \n 6) ����� ����� ������� ������������������ ����� \n");
		printf(" 7*) ���������� ���������� ������� � ����������� \n 8*) ���������� ������������ ������� \n 9*) ���� ������ \n");
		printf("����� ����� ������ �������\n");
		fflush(stdin);
		scanf("%c",&a);
		switch(a){
			case '1':
				printf("������� ������ ������� - ���� � ����� ������� \n");
				First();	
				break;
			case '2':
				printf("������� ������ ������� - ���������������� ���������� ������� \n");
				Second();
				break;
			case '3':
				printf("������� ������ ������� - ��������� ������\n");
				Third();
				break;
			case '4':
				printf("������� ��������� ������� - ����������� ���������\n");
				Four();
				break;
			case '5':
				printf("������� ����� ������� - ����� ����������� �������������� �����\n");
				Five();
				break;
			case '6':
				printf("������� ������ ������� - ����� ����� ������� ������������������ �����\n");
				Six();
				break;
			case '7':
				printf("������� �������* ������� - ���������� ���������� ������� � �����������\n");
				Seven();
				break;
			case '8':
				printf("������� �������* ������� - ���������� ������������ �������\n");
				Eight();
				break;
			case '9':
				printf("������� �������* ������� - ���� ������\n");
				Nine();
				break;

		}
		printf("���� ������ ��������� - ������� ������\n");
		fflush(stdin);
		scanf("%c",&a);
	}while(a==' ');
}


