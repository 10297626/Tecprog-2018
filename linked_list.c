#include "stdio.h"
#include "linked_list.h"
#include "advlib.h"

lista cria(){
  lista *l= (lista*)malloc(sixeof(lista));
  l->count=0;
  l->head=null;
}

void destroi(lista *l){
  free(l);
}


