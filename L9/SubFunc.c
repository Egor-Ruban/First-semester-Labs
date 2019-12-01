#include "MyLib.h"
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

int TakeBool(BoolV* pt, int base, int pos){
	return (pt->arr)[base]>>(31-pos)&(int)1;
}

int NormTakeBool(BoolV* pt, int i){
	int base = i/32;
	int pos = i%32;
	return TakeBool(pt,base,pos);
}

BoolV* CreateBoolV(char* S){
	BoolV* pt=(BoolV*)malloc(sizeof(BoolV));
	if(!pt) return NULL;
	pt->lenb = strlen(S);
	pt->lenw = (pt->lenb%32)?(pt->lenb/32+1):(pt->lenb/32);
	pt->arr = (int*)malloc(pt->lenw*sizeof(int));
	if(!pt->arr){
		free(pt);
		return NULL;
	}
	return pt;
}

BoolV* NormCreateBoolV(int n){
	BoolV* pt=(BoolV*)malloc(sizeof(BoolV));
	if(!pt) return NULL;
	pt->lenb = n;
	pt->lenw = (pt->lenb%32)?(pt->lenb/32+1):(pt->lenb/32);
	pt->arr = (int*)malloc(pt->lenw*sizeof(int));
	if(!pt->arr){
		free(pt);
		return NULL;
	}
	return pt;
}

void FreeBoolV(BoolV* pt){
	free(pt->arr);
	free(pt);
}
void PrintfBoolV(BoolV* pt){
	for(int i = 0;i<pt->lenb;i++){
		int base = i/32;
		int pos = i%32;
		printf("%d",TakeBool(pt,base,pos));
	}
	printf("\n");
}

BoolV* ReadBoolV(char* S){
	BoolV* pt = CreateBoolV(S);
	//PrintfBoolV(pt);
	for(int i = 0; i<pt->lenw;i++){
		int base = i/32;
		(pt->arr)[base]=0;
	}
	for(int i = 0; i<pt->lenb;i++){
		int base = i/32;
		int pos = i%32;
		int h = (((int)S[i]-'0')<<(31-pos));
		(pt->arr)[base]=(pt->arr)[base]|h;
	}
	return pt;
}



BoolV* ConBoolV(BoolV* pt1, BoolV* pt2){
	if((pt1->lenb)!=(pt2->lenb)) return NULL;
	BoolV* pt = NormCreateBoolV(pt1->lenb);
	for(int i = 0;i<pt->lenb;i++){
		int base = i/32;
		int pos = i%32;
		(pt->arr)[base]|=(TakeBool(pt1,base,pos)&TakeBool(pt2,base,pos))<<(31-pos);
	}
	return pt;
}

BoolV* DisBoolV(BoolV* pt1, BoolV* pt2){
	if((pt1->lenb)!=(pt2->lenb)) return NULL;
	BoolV* pt = NormCreateBoolV(pt1->lenb);
	for(int i = 0;i<pt->lenb;i++){
		int base = i/32;
		int pos = i%32;
		(pt->arr)[base]|=(TakeBool(pt1,base,pos)|TakeBool(pt2,base,pos))<<(31-pos);
	}
	return pt;
}

BoolV* 	InvBoolV(BoolV* pt1){		//возвращает адрес нового вектора, старый не изменяет
	BoolV* pt = NormCreateBoolV(pt1->lenb);
	for(int i = 0; i<pt1->lenb; i++){
		int base = i/32;
		int pos = i%32;
		(pt->arr)[base]|=((TakeBool(pt1,base,pos)?(0<<(31-pos)):1<<(31-pos)));
	}
	return pt;
}

char* ScanStr(char *str){
	long sLen = 0;
	char ch;
	str = (char*)malloc(0*sizeof(char));
    while((ch = getchar()) != '\n')
    {
	sLen++;
        str = (char*)realloc(str,((sLen))*sizeof(char));
        str[sLen-1] = ch;
    }
	sLen++;
        str = (char*)realloc(str,((sLen))*sizeof(char));
    	str[sLen-1] = '\0';
	return str;
}

int isCompBoolV(BoolV* pt1, BoolV* pt2){
	if((pt1->lenb)!=(pt2->lenb)) { return 0;
	} else {
		int check1 = 0;
		int check2 = 0;
		for(int i = 0;i<pt1->lenb;i++){
			if(NormTakeBool(pt1,i)>=NormTakeBool(pt2,i))	check1++;
			if(NormTakeBool(pt1,i)<=NormTakeBool(pt2,i))	check2++;
		}
		if(check1==pt1->lenb||check2==pt1->lenb)	return 1;
		else return 0;
	}
}

BoolV** CreateBoolM(){
	BoolV *vec;
	printf("ну давай, введи свой первый вектор: ");
	char* S;
	S = ScanStr(S);
	vec = ReadBoolV(S);
	//printf("vec len %d\n",vec->lenb);
	BoolV** BoolM = (BoolV**)malloc(vec->lenb*sizeof(BoolV*));
	BoolM[0] = ReadBoolV(S);
	printf("Вводи остальные\n");
	for(int i = 1; i<vec->lenb;i++){
		S=ScanStr(S);
		BoolM[i] = ReadBoolV(S);
	}
	return BoolM;
}

int NumOfOne(BoolV** BoolM){
	int num = 0;
	for(int i = 0; i<3;i++){
		if(TakeBool(BoolM[i],i/32,i%32)==1)		num++;
	}
	return num;
}

BoolV* LShiftBoolV(BoolV* pt, int shift){
	BoolV* pts = NormCreateBoolV(shift);
	int i = 0;
	for(i = 0; i<shift;i++){
		int base = i/32;
		int pos = i%32;
		(pts->arr)[base]|=(NormTakeBool(pt,i))<<(31-pos);
	}
	BoolV* ptt = NormCreateBoolV(pt->lenb);
	for(i = 0; i<ptt->lenw;i+=32){
		int base = i/32;
		(ptt->arr)[base]=0;
	}
	for(i = 0;i<ptt->lenb-shift;i++){
		int base = i/32;
		int pos = i%32;
		(ptt->arr)[base]|=((NormTakeBool(pt,i+shift))<<(31-pos));
	}
	for(int j = 0;i+j<ptt->lenb;j++){
		int base = (i+j)/32;
		int pos = (i+j)%32;
		(ptt->arr)[base]|=(NormTakeBool(pts,j))<<(31-pos);
	}
	FreeBoolV(pts);
	return ptt;
}
		
	
		
	
	