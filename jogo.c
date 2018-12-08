/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include "hashtable.h"

int yyparse();
TabSim init_table();
TabSim sym_table;

int main() {
	/* Monta o mundo */
	sym_table = init_table(sym_table);
	/* Descrição inicial */
	printf("Você acorda em um banheiro sem saber o que aconteceu na noite anterior e nota que está preso com as janelas emparedadas e com a porta trancada!\n");
	/* Que comece o jogo */
	while (yyparse());
	return 0;
}
