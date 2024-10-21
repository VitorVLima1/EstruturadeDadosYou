#ifndef LISTA_H
#define LISTA_H

typedef struct _node Node;
typedef struct _linked_list LinkedList;

Node * Node_create( int val);
LinkedList * LinkedList_create();
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_add_first_fast(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_add_last_fast(LinkedList *L, int val);
void LinkedList_add_element(LinkedList *L, int val, int index);
void LinkedList_remove_first(LinkedList *L);
void LinkedList_remove(LinkedList *L, int val);
void LinkedList_remove_last(LinkedList *L);
void LinkedList_print(LinkedList *L);
bool LinkedList_empty(LinkedList *L);

#endif