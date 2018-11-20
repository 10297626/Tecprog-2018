/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <string.h>
#include "base.h"
#include "advlib.h"
#include "hashtable.h"
#include "linkedlist.h"

int main(){
	//printf("teste\n");
	int a = 10;
	int* aa = &a;
	int b = 15;
	int* bb = &b;
	int c = -5;
	int* cc = &c;
	printf("%d\n", compareInt(aa, aa));
	printf("%d\n", compareInt("ab", "abc"));
	printf("%d\n", compareInt(bb, aa));
	printf("%d\n", compareInt(cc, bb));

	return 0;
}
