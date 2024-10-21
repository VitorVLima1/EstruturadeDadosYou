#include <stdio.h>
#include <stdlib.h>

int **create_int_matrix(int nrows, int ncols){

    int **m = (int**)calloc(nrows, sizeof(int*));
    for(int i = 0; i<nrows; i++){
        m[i]= (int*)calloc(ncols,sizeof(int));
    }

    return m;
}

void print_int_matrix(int **m, int nrows, int ncols){
     for(int i=0;i<nrows;i++){
        for(int j=0; j<ncols;j++){
            m[i][j]=j + i;
            printf("m[%d][%d]=%p, m[%d][%d]=%d  ",i,j,&m[i][j],i,j,m[i][j]);
        }
        puts(" ");
    }
}

void destroy_int_matrix(int ***mat, int nrows, int ncols){
    int **aux = *mat;
    for(int i=0;i<nrows;i++){
    free(aux[i]);
}
free(aux);
*mat = NULL;
}

int main(int argc, char**argv){
    if(argc !=3){
        printf("ERRO\n%s nrows ncols\n", argv[0]);
        exit(-1);
    }
    int nrows = atoi(argv[1]);
    int ncols = atoi(argv[2]);

    int **m = create_int_matrix(nrows,ncols);
    for (int i=0;i<nrows;i++){
        for (int j=0;j<ncols;j++){
            m[i][j]= i+j;
        }
    }

    print_int_matrix(m,nrows,ncols);
    destroy_int_matrix(m,nrows,ncols);
    print_int_matrix(&m,nrows,ncols);

    return 0;
}