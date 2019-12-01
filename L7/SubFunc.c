#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void ScanMatrix(int n, int m, int *M){
	for(int i = 0; i<n; i++){
		fflush(stdin);
		printf("¬ведите %d-ую строку\n",i+1);
		for(int j=0; j<m; j++){
			scanf("%d",(M+i*m+j));
		}
		printf("\n");
	}
				
}

void PrintMatrix(int n, int m, int *M){
	for(int i = 0; i<n; i++){
		fflush(stdin);
		for(int j=0; j<m; j++){
			printf("M[%d][%d] = %d\t\t",i+1,j+1,*(M+i*m+j));
		}
		printf("\n");
	}
}

void RandMatrix(int n, int m, int *M){
	for(int i = 0; i<n; i++){
		fflush(stdin);
		for(int j=0; j<m; j++){
			*(M+i*m+j) = rand()%201 - 100;
		}
		printf("\n");
	}
}

void change(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void TrMat(int n, int *M){
	int k = 0;
	for(int i = 0; i<n; i++){
		for( int j = k; j<n;j++){
			change((M+i*n+j),(M+j*n+i));
		}
		k++;
	}
}

void MulMat(int *M1, int n1, int m1, int *M2, int n2, int m2, int *M){
	int n = n1; int m = m2;
	for(int i = 0; i<m1; i++){
		for(int j = 0; j<m2;j++){
			*(M+i*m+j)=0;
			for(int k = 0; k<m;k++){
				*(M+i*m+j)+=*(M1+i*m1+k)*(*(M2+k*m2+j));
			}
		}
	}
}



void CopyArrFT(int s, int n, char *arr, char *a){
	for(int i = s;i<s+n;i++){
		*(a+i-s)=*(arr+i);
	}
}

void ScanStr(int n, char *a){
	for(int i = 0; i<n; i++){
		scanf("%c",(a+i));
	}
}


void PrintStr(int n, char *a){
		for(int i = 0; i<n; i++){
			printf("%c",a[i]);
			
		}
		printf("\n");
		
}

void RandStr(int n, char *a){
	for(int i = 0; i<n; i++){
		*(a+i) = 32 + rand()%126;
	}
}

void RandArr(int n, int *a){
	for(int i = 0; i<n; i++){
		fflush(stdin);
		a[i] = -100 + rand()%201;
	}
}

void ScanArr(int n, int *a){
	for(int i = 0; i<n; i++){
		scanf("%d",(a+i));
	}
}


void PrintArr(int n, int *a){
		for(int i = 0; i<n; i++){
			printf("\tarr[%d] = %d\n",i,*(a+i));
		}
}

void L705(int n, int *arr){
	int **a;
	int l=1,count=0;
	a = (int**)malloc(1 * sizeof(int*));

	for (int i = 0; i<l; i++){
 		a[i] = (int*)malloc(2 * sizeof(int));
		a[i][1]=1;
	}

	a[0][0]=arr[0];
	for(int i = 1; i<n; i++){
		for(int j = 0; j<l; j++){
			if(arr[i]==a[j][0]){
				a[j][1]++;
				count++;
			}
		}
		if(count==0){

			l++;
			a = realloc (a, l * sizeof(int));
			a[l-1] = (int*)malloc(2 * sizeof(int));
			a[l-1][0]=arr[i];
			a[l-1][1]=1;
		}
		count=0;
	}
	int max=0;

	for(int i = 0; i<l; i++){
		if(a[i][1]>a[max][1]){
			max=i;
		}
	}
	printf("чаще других встречаетс€ a[%d] = %d\n",max,a[max][0]);
}


void SortArrBub(int n, int *a){
	int check, it = 0;
	for(int i=0;i<n;i++){
		check = 0;
		for(int j=0;j<n-i-1;j++){
			if(*(a+j)>*(a+j+1)){
				int temp;
				change((a+j),(a+j+1));
				check++;
				it++;
			}
		}
		if(check == 0){
			printf("it took %d iterations:\n",it);
			break;
		}
	}
}

void FZ(int n, int *a){
	int s=0,st=0,k=0,kt=0,l=0,lt=0;
	if(a[0]==0){
		kt++;
		lt++;
	}
	for(int i = 1; i<n; i++){
		if(a[i]==0&&a[i-1]==0){
			lt++;
			kt++;
			if(lt>l){
				s=st;
				l=lt;
				k=kt;
			}
		}
		if(a[i]==0&&a[i-1]!=0){
			lt++;
			st=i;
			kt=i;
		}
		if(a[i]!=0&&a[i-1]==0){
			if(lt>l){
				s=st;
				l=lt;
				k=kt;
			}
			lt=0;
			kt=0;
			st=0;
		}
	}
	printf("сама€ длинна€ последовательность нулей с %d по %d: %d штук\n",s,k,l);
}

void Cstr(int n, char *str, int p){
	for(int i =0; i<n; i++){
		if(str[i]>='A'&&str[i]<='Z'){
			str[i] = 'A' + (str[i]-'A'+p)%26;
		}
		if(str[i]>='а'&&str[i]<='z'){
			str[i] = 'a' + (str[i]-'a'+p)%26;
		}
		
	}
}

void Dstr(int n, char *str, int p){
	for(int i = 0; i<n; i++){
		if(str[i]>='A'&&str[i]<='Z'){
			if(str[i]-p<'A'){
				str[i] = 'A' + 26 + (str[i]-'A'-p)%26;
			} else {
				str[i] = 'A' + (str[i]-'A'-p)%26;
			}
		}
		if(str[i]>='a'&&str[i]<='z'){
			if(str[i]-p<'a'){
				str[i] = 'a' + (str[i]-'a'-p+26)%26;
			} else {
				str[i] = 'a' + (str[i]-'a'-p)%26;
			}
		}

	}
}

void NewMat(int **M, int **p, int i, int j, int n) {
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki<n-1; ki++) { 
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj<n-1; kj++) { 
			if (kj == j) dj = 1;
			p[ki][kj] = M[ki + di][kj + dj];
		}
	}
}

int DetMat(int n, int **M){
	int  i , j=1, det = 0 ;
	int **p;
	p = (int**)malloc(n * sizeof(int*));
		for (i = 0; i<n; i++)
			p[i] = (int*)malloc(n * sizeof(int*));
	if(n==0){
		return 0;
	} else if (n==1){
		det=M[0][0];
		return  det;
	} else if (n==2){
		det = M[0][0]*M[1][1]-(M[0][1]*M[1][0]);
		return det;
	} else {
		for (i = 0; i<n; i++) {
		NewMat(M, p, i, 0, n);
		det = det + j * M[i][0] * DetMat(n-1,p);
		j = -j;
		}
	}
	return det;
}

void DiagMat(int n, float **M){
float g = 0;
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n;j++){
			g = M[j][i];
			for(int k = i; k<n; k++){
				float temp = (float)M[i][k]/M[i][i];
				M[j][k]=M[j][k]-temp*g;
			}
		}
	}
}
			
void ScanMatrixF(int n, int m, float **M){
	for(int i = 0; i<n; i++){
		fflush(stdin);
		printf("¬ведите %d-ую строку\n",i+1);
		for(int j=0; j<m; j++){
			scanf("%f",&M[i][j]);
		}
		printf("\n");
	}
				
}

void PrintMatrixF(int n, int m, float **M){
	for(int i = 0; i<n; i++){
		fflush(stdin);
		for(int j=0; j<m; j++){
			printf("M[%d][%d] = %.4f\t\t",i+1,j+1,M[i][j]);
		}
		printf("\n");
	}
}

void RandMatrixF(int n, int m, float **M){
	for(int i = 0; i<n; i++){
		fflush(stdin);
		for(int j=0; j<m; j++){
			M[i][j] = rand()%50;
		}
		printf("\n");
	}
}
		
		



	
	