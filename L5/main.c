#include <stdio.h>
#include <locale.h>
#include "MyLib.h"
#include <Windows.h>
int main(){
	setlocale(LC_ALL, "Rus");
	Zero();
	system("pause");

	return 0;
}