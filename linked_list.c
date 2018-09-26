/*//////////////////////////////////////////////////////////////////////
Nome: Alessandro Bezerra da Silva     NUSP: 10284351
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include "stdio.h"
#include "linked_list.h"
#include "advlib.h"

lista l_cria(){
  lista *l= (lista*)malloc(sixeof(lista));
  l->count=0;
  l->head=null;
  l->last=null;
  return l;
}

void l_destroi(lista *l){
  free(l);
}

lista l_insere(lista l, elemeento *val, char *n){
  node *new=(node*) malloc(sizeof(node));
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

node l_busca(lista l, char *n){
  node atual;
  atual=l->head
  if(atual.nome==n){
    return head;
  }
  while(atual.next!=null){
    atual = atual.next;
    if (atual.nome==n){
      return atual;
    }
  }
  return null;      
 }

node l_retira(lista l, char *n){
  node atual;
  atual=l->head;
  if(atual->nome==n){
    l->head=atual->next;
    return l->head;
  }
  while(atual.next!=null){
    if(atual.next.nome==n){
      node rem=atual.next;
      atual.next=rem.next;
      rem.next=null;
      return l->head;
    }
  }
  return null;
}
