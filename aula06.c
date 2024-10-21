#include <stdio.h>
#include <stdlib.h>

int main(){

    int * a = (int*)malloc(10*sizeof(int));
    for(int i = 0;i<10;i++){
        a[i]= i+10;
        printf("&a[%d] = %p, a[%d]=%d\n",i,&a[i],i,a[i] );
    }
    free(a);
    
    printf("\n");
    int* b = (int*)calloc(10,sizeof(int));
     for(int i = 0;i<10;i++){
        printf("&b[%d] = %p, b[%d]=%d\n",i,&b[i],i,b[i] );
    }

     for(int i = 0;i<10;i++){
        printf("\n&a[%d] = %p \n",i,&a[i]);
    }

    


    return 0;
}