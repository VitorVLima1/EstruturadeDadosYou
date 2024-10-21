#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _node{
    int val;
    struct _node *next;
}Node;

typedef struct _linked_list{
    Node *begin;
    Node *end;
}LinkedList;

Node * Node_create( int val){
    Node * node = (Node*)calloc(1,sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

LinkedList * LinkedList_create(){
    LinkedList * L = (LinkedList *)calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;
    return L;
}

void LinkedList_add_first(LinkedList *L, int val){
    //lista está vazia
    if(L->begin == NULL){
        Node * p = Node_create(val);
        L->begin = p;
    }else{
        Node * p = Node_create(val);
        p->next = L->begin;
        L->begin = p;
    }
}

void LinkedList_add_first_fast(LinkedList *L, int val){
    Node * p = Node_create(val);
    //lista está vazia
    if(L->begin == NULL){
        L->begin = p;
        L->end = p;
    }else{
       p->next = L->begin;
       L->begin = p;
    }
}

void LinkedList_add_last(LinkedList *L, int val){
    //lista está vazia
    if(L->begin == NULL){
        Node * q = Node_create(val);
        L->begin = q;
    }else{
        Node * p = L->begin;
        while(p->next != NULL){
            p = p->next;
        }
        //p aponta para o no final da lista
        Node * q = Node_create(val);
        p->next = q;
    }
}

void LinkedList_add_last_fast(LinkedList *L, int val){
    //lista está vazia
    Node * q = Node_create(val);
    if(L->begin == NULL){
        L->begin = q;
        L->end = q;
    }else{
        L->end->next = q;
        L->end = L->end->next;
    }
}

void LinkedList_add_element(LinkedList *L, int val, int index) {
    if (index < 0) {
        printf("impossivel acessar indice negativo\n");
        return;
    }

    Node *q = Node_create(val);
    
     if (index == 0) {
        q->next = L->begin;
        L->begin = q;
        if (L->end == NULL) { // Se a lista estava vazia
            L->end = q;
        }
        return;
    }
 
    Node *p = L->begin;
    for (int cont = 0; cont < index - 1; cont++) {
        if (p == NULL) {
            printf("Lista nao possui elementos suficientes para acessar essa posicao\n");
            free(q);
            return;
        }
        p = p->next;
    }

    if (p == NULL) {
        printf("Lista nao possui elementos suficientes para acessar essa posicao\n");
        free(q);
        return;
    }

    q->next = p->next;
    p->next = q;
     if (q->next == NULL) { // Se o novo nó é o último
        L->end = q;
    }
}

void LinkedList_remove_first(LinkedList *L){
    if(L->begin == NULL){
        printf("lista vazia");
        return;
    }
    Node * p = L->begin;
    L->begin = L->begin->next;
    if(L->begin == NULL){
        L->end = NULL;
    }
    free(p);
    printf("item removido com sucesso\n");
}

void LinkedList_remove_last(LinkedList *L){
    if(L->begin == NULL){ //lista vazia
        printf("lista vazia");
        return;
    }
    Node * p = L->begin->next;
    Node * ant = L->begin;
    if(L->begin->next == NULL){ //lista possui 1 elemento
        L->begin = NULL;
        L->end = NULL;
        free(ant);
    }else{
        while(p->next!= NULL){ //lista com mais de 1 elemento
            p = p->next;
            ant = ant->next;
        }
        L->end = ant;
        ant->next = NULL;
        free(p);
    }

}

void LinkedList_remove(LinkedList *L, int val){
    if(L->begin == NULL){ //lista vazia
        printf("lista vazia");
        return;
    }
    if(L->begin->val == val){ //valor no inicio
        Node * p = L->begin;
        L->begin = L->begin->next;
        if(L->begin == NULL){
        L->end = NULL;
        }
        free(p);
    }else{ //valor no meio
        Node * ant = L->begin;
        Node * p = L->begin->next;
        while(p!=NULL &&p->val!= val){
            p = p->next;
            ant = ant->next;
        }
        if(p != NULL){ //um valor foi encontrado
            if(p->next = NULL){ //valor no fim
                L->end = ant;
                ant->next = p->next;
                free(p);
            }else{  //valor no meio
                ant->next = p->next;
                free(p);
            }
        }else{ //valor nao encontrado
            printf("valor nao encontrado");
            return;
        }
    }
}

void LinkedList_print(LinkedList *L){
    Node * p;
    int cont=1;
    p = L->begin;
    while(p != NULL){
        printf("valor %d: %d\n", cont, p->val);
        p = p->next;
        cont++;
    }
    printf("\n");
}



