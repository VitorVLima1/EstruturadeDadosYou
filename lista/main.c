#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
 
int main(){

    LinkedList * lista = LinkedList_create();
    
    LinkedList_add_first(lista,2);
    LinkedList_add_first(lista,3);
    LinkedList_add_first(lista,4);
    LinkedList_add_last(lista,5);
    LinkedList_print(lista);
    LinkedList_add_element(lista,6,4);
    LinkedList_print(lista);
    LinkedList_add_last(lista,7);
    LinkedList_print(lista);
    LinkedList_remove_first(lista);
    LinkedList_print(lista);
    LinkedList_remove_last(lista);
    LinkedList_remove_element(lista,1);
    LinkedList_print(lista);
    
    if(LinkedList_empty(lista)){
        printf("lista esta vazia\n");
    }else{
        printf("lista possui 1 ou mais elementos\n");
    }

    LinkedList_search(lista,2);




    return 0;
}