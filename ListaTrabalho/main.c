#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
 
int main(){

    LinkedList * lista = LinkedList_create();
    LinkedList_add_first(lista,14);
    LinkedList_add_first(lista,10);
    LinkedList_add_first(lista,18);
    LinkedList_add_first(lista,18);
    LinkedList_add_first(lista,12);
    LinkedList_print(lista);
    LinkedList_Order(lista);
    LinkedList_print(lista);

    




    return 0;
}