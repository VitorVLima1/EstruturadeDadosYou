#include <stdio.h>
#include <stdlib.h>

int main(){

    int**m=NULL;
    int nlinha, ncoluna;
    nlinha = 3;
    ncoluna = 3;
    m = (int**)calloc(nlinha, sizeof(int*));
    for(int i = 0; i<nlinha; i++){
        m[i]= (int*)calloc(ncoluna,sizeof(int));
    }

    printf("&m = %p, m = %p\n\n", &m, m);

    for(int i = 0; i<nlinha; i++){
        printf("&m[%d]=%p, m[%d]=%p  ", i, &m[i],i,m[i]);
    }
    puts("");
    puts("");


    for(int i=0;i<nlinha;i++){
        for(int j=0; j<ncoluna;j++){
            m[i][j]=j + i;
            printf("m[%d][%d]=%p, m[%d][%d]=%d  ",i,j,&m[i][j],i,j,m[i][j]);
        }
        puts(" ");
    }

for(int i=0;i<nlinha;i++){
    free(m[i]);
}
free(m);
    


    return 0;
}