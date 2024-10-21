#include <stdio.h>
#include <stdlib.h>

int main(){

    int***m=NULL;
    int nlinha, ncoluna,nfatia;
    nfatia = 2;
    nlinha = 2;
    ncoluna = 3;
    m = (int***)calloc(nfatia, sizeof(int**));
    for(int i = 0; i<nfatia; i++){
        m[i]= (int**)calloc(nlinha,sizeof(int*));
        for(int j = 0;j < nlinha; j++){
            m[i][j] = (int*)calloc(ncoluna,sizeof(int));
        }
    }

    printf("&m = %p, m = %p\n\n", &m, m);

    for(int i = 0; i<nfatia; i++){
        printf("&m[%d]=%p, m[%d]=%p  ", i, &m[i],i,m[i]);
    }
    puts("");
    puts("");

    for(int i=0;i<nfatia;i++){
        for(int j=0; j<nlinha;j++){
            for(int k=0;k<ncoluna;k++){
                m[i][j][k]=j + i + k;
            printf("m[%d][%d][%d]=%p, m[%d][%d][%d]=%d  ",i,j,k,&m[i][j][k],i,j,k,m[i][j][k]);
            }
            puts(" ");
        }
        puts(" ");
    }

    for(int k=0; k<nfatia; k++){
        for(int i=0;i<nlinha ; i++){
            free(m[k][i]);
        }
        free(m[k]);
    }
    free(m);

    


    return 0;
}