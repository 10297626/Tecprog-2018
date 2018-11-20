/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

#ifndef base_h
#define base_h

//Booleanos
typedef enum {
	False, True
} Boolean;

// union entre string a int
typedef union {
	char* S;
	int I;
} StrInt;

int compareStr(void* p, void* q);
int compareInt(void* p, void* q);

#endif
