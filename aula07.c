#include <stdio.h>
#include <stdlib.h>

void destruidor(int **v){
    free(*v);
    *v = NULL;

}

int main(){
    char * n;
    for(int i=0;i<100000000;i++){
    n = (char*)malloc(10*sizeof(char));
    free(n);
    }

    return 0;
}