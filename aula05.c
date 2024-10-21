#include <stdio.h>
#include <stdlib.h>

int main(){

    int v[4]={5,4,3,2};

    for(int i=0;i<4;i++){
        printf("&v[%d]= %p, v[%d]=%d\n", i,&v[i],i,v[i]);
        printf("(v + %d)= %p, *(v + %d)=%d\n\n", i,(v+i),i,*(v+i));
    }
    


    return 0;
}