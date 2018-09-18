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

node busca(lista l, char *n){
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

node retira(lista l, char *n){
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
