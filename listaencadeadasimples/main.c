#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
 
int main(){

    LinkedList * lista = LinkedList_create();
    
    LinkedList_add_first_fast(lista,2);
    LinkedList_add_first_fast(lista,3);
    LinkedList_add_first_fast(lista,4);
    LinkedList_add_last_fast(lista,5);
    LinkedList_print(lista);
    LinkedList_add_element(lista,6,4);
    LinkedList_print(lista);
    LinkedList_add_last_fast(lista,7);
    LinkedList_print(lista);
    LinkedList_remove_first(lista);
    LinkedList_print(lista);
    LinkedList_remove_last(lista);
    LinkedList_print(lista);



    return 0;
}