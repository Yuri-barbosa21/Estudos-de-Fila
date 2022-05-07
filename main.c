#include "stdio.h"
#include "stdlib.h"

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void Push(No **fila, int num){
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

No* Pop(No **fila){
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

void Imprimir(No *fila){
    printf("\t--------------- FILA ---------------\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t------------ FIM FILA -------------\n");
}

int main(void) {
    No *r, *fila = NULL;
    int opcao, valor;

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            Push(&fila, valor);
            break;
        case 2:
            r = Pop(&fila);
            if(r){
                printf("Removido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            Imprimir(fila);
            break;
        }
    }while(opcao != 0);
    
  return 0;
}
