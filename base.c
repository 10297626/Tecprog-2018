/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

#include "base.h"

/**
 * Fucao usada para comparar valores de strings, para buscas e sorting
 * @param  p primeira string
 * @param  q segunda string
 * @return   retorna 0 para o caso igual, inteiro negativo se p<q, inteiro positivo se p>q
 */

/*int compareStr(void* p, void* q) {
	char *pp = (char*) p;
	char *qq = (char*) q;
	unsigned char c1, c2;
    while ((c1 = *pp++) == (c2 = *qq++)) {
        if (c1 == '\0')
            return 0;
    }
    return c1 - c2;
}*/

/**
 * Funcao para comparar valores inteiros, para buscas e sorting
 * @param  p ponteiro para o primeiro inteiro
 * @param  q ponteiro para o segundo inteiro
 * @return   retorna 0 para o caso igual, inteiro negativo se p<q, inteiro positivo se p>q
 */

/*int compareInt(void* p, void* q) {
	int pp = *((int*) p);
	int qq = *((int*) q);
	return pp-qq;
}*/
