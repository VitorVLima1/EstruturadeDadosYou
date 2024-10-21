#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

void LinkedList_add_Order(LinkedList *L, int val){
    Node * q = Node_create(val);
    if(L->begin == NULL){
        L->begin = q;
        L->end = q;
        printf("valor adicionado no inicio\n");
    }else{
        Node * p = L->begin;
        Node * ant = NULL;
        while(p!=NULL && p->val < val){
            ant = p;
            p = p->next;
    
        }
        if(p==NULL){ //adicionar no final com mais de 1 elemento
                L->end->next = q;
                L->end = L->end->next;
        }else if(ant == NULL){ //adicionar no começo com mais de um elemento
                q->next = L->begin;
                L->begin = q;
        }else{
                ant->next = q;
                q->next = p;
        }
        printf("valor adicionado com sucesso\n");
    }
}

void LinkedList_remove_first(LinkedList *L){
    if(L->begin == NULL){
        printf("Lista vazia\n");
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
        printf("Lista vazia\n");
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

void LinkedList_remove_element(LinkedList *L, int index) {
    if (L->begin == NULL) { // lista vazia
        printf("Lista vazia\n");
        return;
    }

    if (index < 0) { // índice inválido
        printf("Índice inválido\n");
        return;
    }

    if (index == 0) { // valor no início
        Node *p = L->begin;
        L->begin = L->begin->next;
        if (L->begin == NULL) { // valor no início com apenas 1 elemento
            L->end = NULL;
        }
        free(p);
        printf("Item removido com sucesso\n");
    } else { // valor a partir do segundo elemento
        Node *p = L->begin; 
        Node *ant = NULL; 
        int cont = 0;

        while (p != NULL && cont < index) {
            ant = p; 
            p = p->next; 
            cont++;
        }

        if (p != NULL) { // um valor foi encontrado
            if (p->next == NULL) { // valor no fim
                L->end = ant;
                ant->next = NULL; 
            } else { // valor no meio
                ant->next = p->next; 
            }
            free(p); 
            printf("Item removido com sucesso\n");
        } else { // valor não encontrado
            printf("Índice inválido\n");
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

bool LinkedList_empty(LinkedList *L){
    if(L->begin == NULL){
        return true;
    }else{
        return false;
    }
}

void LinkedList_search(LinkedList *L, int index){
    Node * p = L->begin;
    int cont = 0;
    while(p!= NULL){
        if(cont == index){
            printf("valor contido na posicaoo %d da lista e: %d\n", cont, p->val);
            return;
        }
        p = p->next;
        cont++;
    }
    printf("indice nao encontrado ou fora do escopo da lista\n");
}

void LinkedList_Order(LinkedList *L){
    if(L->begin == NULL){
        printf("impossivel ordernar lista vazia\n");
    }else if(L->begin->next == NULL){
        printf("impossivel ordernar lista com apenas 1 elemento\n");
    }else{
        Node * p = L->begin->next;
        Node * ant = L->begin;
        int val;
        int cont;
        do{
            cont = 0;
            p = L->begin->next;
            ant = L->begin;
            while(p!=NULL){
                if(p->val < ant->val){
                    val = p->val;
                    p->val = ant->val;
                    ant->val = val;
                    p = p->next;
                    ant = ant->next;
                    cont=1;
                }else{
                    p = p->next;
                    ant = ant->next;
                }
            }
        }while(cont == 1);
    }
    
}





