#include "stdio.h"
#include "linked_list.h"
#include "advlib.h"

lista cria(){
  lista *l= (lista*)malloc(sixeof(lista));
  l->count=0;
  l->head=null;
  l->last=null;
  return l;
}

void destroi(lista *l){
  free(l);
}

lista insere(lista l, elemeento *val, char *n){
  node new;
  new->ele=val;
  new->next=null;
  new->nome=n;
  
  if (l->head==null){
    l->head=new;
    l->last=new;
  }else{
    l.last->next=new;
    l.last=new;
  }    
}

elemento busca(lista l, char *n){
  node atual;
  atual=l.head
  if(atual.nome==n){
    return head.ele;
  }
  while(atual.next!=null){
    atual = head.next;
    if (atual.nome==n){
      return atual.ele;
    }
  }
  return null;      
 }
  
  
}
