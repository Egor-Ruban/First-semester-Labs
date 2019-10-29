#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(){
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	Zero();
	system("pause");

	return 0;
}