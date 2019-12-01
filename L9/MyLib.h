typedef struct {
	int* arr;
	int lenb;
	int lenw;
} BoolV;

void Zero();

char* ScanStr(char *str);
BoolV* 	InvBoolV(BoolV* pt1);
BoolV* DisBoolV(BoolV* pt1, BoolV* pt2);
BoolV* ConBoolV(BoolV* pt1, BoolV* pt2);
BoolV* ReadBoolV(char* S);
void PrintfBoolV(BoolV* pt);
void FreeBoolV(BoolV* pt);
BoolV* NormCreateBoolV(int n);
BoolV* CreateBoolV(char* S);
int TakeBool(BoolV* pt, int base, int pos);
int NormTakeBool(BoolV* pt, int i);
int isCompBoolV(BoolV* pt1, BoolV* pt2);
BoolV** CreateBoolM();
int NumOfOne(BoolV**);
BoolV* LShiftBoolV(BoolV* pt, int shift);


