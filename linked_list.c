/*//////////////////////////////////////////////////////////////////////
Nome: Alessandro Bezerra da Silva     NUSP: 10284351
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"
#include "advlib.h"

lista* l_cria(){
  lista *l= malloc(sizeof(lista));
  l->count=0;
  l->head=NULL;
  return l;
}

void l_destroi(lista *l){
  node *atual=l->head;
  while (atual!=NULL){
    free(l->head);
    l->head=atual;
    atual=l->head->next;
  }
  free(l->head);
  free(l);
}


lista* l_insere(lista *l, elemento *val){
  node *new=malloc(sizeof(node));
  new->ele=val;
  new->next=l->head;
  l->head=new;
  return l;
}


elemento* l_busca(lista *l, char *n){
  node *atual=l->head;

  while(atual != NULL){
    char *na=atual->ele->nome;
    if (strcmp(na,n)==0){
      return atual->ele;
    }
    atual = atual->next;
  }
  return NULL;      
 }


elemento* l_retira(lista *l, elemento *val){
  node *atual=l->head;
  node *anterior=atual;
  while(atual !=NULL){
    if(strcmp(atual->ele->nome,val->nome)==0){
      if(atual==l->head){//se for o primeiro da lista
        l->head=atual->next;
        atual->next=NULL;
      }else{ // caso esteja no meio da lista
        anterior->next=atual->next;
        atual->next=NULL;
      }
      return atual->ele;
    }
    anterior=atual;
    atual=atual->next;
  }
  return NULL;
}
