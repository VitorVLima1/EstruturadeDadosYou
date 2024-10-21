#include <stdlib.h>

typedef struct _livro{
    char titulo[100];
    unsigned int num_paginas;
    float preco;
}Livro;


Livro * create_livro( const char *titulo, unsigned int num_paginas, float preco){
    Livro *livro= (Livro*)calloc(1,sizeof(Livro));
    strcpy(livro->titulo,titulo);
    livro->num_paginas= num_paginas;
    livro->preco = preco;

    return livro;
}

void print_livro(const Livro * livro){
    printf("Titulo: %s\n", livro->titulo);
    printf("Num Paginas: %d\n",livro->num_paginas);
    printf("Preco: %f\n", livro->preco);
}

void destroy_livro(Livro **livro_ref){
    Livro * livro = * livro_ref;
    free(livro);
    *livro_ref = NULL;
}

int main(int argc, char**argv){
    Livro * harry = create_livro("Harry Potter", 500, 23.50);
    print_livro(harry);

    destroy_livro(&harry);
    printf("harry == NULL? %d\n", harry == NULL);

    return 0;
}