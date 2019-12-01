#include <stdio.h>
#include <math.h>
#include "MP.h"
int Func312(int k){
	if(k<0){
		return 0;
	} else if (k==0|| k==1) {
		return 1;
	} else if (k>1) {
		return(Func312(k-1)+Func312(k-2));
	}
}


