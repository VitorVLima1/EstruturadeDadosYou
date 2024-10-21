#include <stdio.h>
#include <stdlib.h>

void soma( int x, int y, int * z){
    *z = x + y;
}

int main(){

    int a = 10;
    int b = 20;
    int c;
    soma(a,b,&c);

    printf("%d", c);
    


    return 0;
}