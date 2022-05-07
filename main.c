#include "stdio.h"
#include "stdlib.h"

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void push(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL){
            *fila = novo;
        }
        else{
            aux = *fila;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else{
        printf("\nErro ao alocar memoria.\n");
    }
}

No* pop(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else{
        printf("\tFila vazia\n");
    }
    return remover;
}

int main(void) {
    No *fila = NULL;
    
  return 0;
}
