#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
    char link[61];
    struct elemento *prox;
} Elemento;

typedef struct {
    Elemento *topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void empilharLink(Pilha *pilha, char *link) {
    Elemento *novoElemento = malloc(sizeof(Elemento));
    strcpy(novoElemento->link, link);

    novoElemento->prox = pilha->topo;
    pilha->topo = novoElemento;
}

void desempilharLink(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Vazio\n");
        return;
    }

    Elemento *elementoRemovido = pilha->topo;
    printf("%s\n", elementoRemovido->link);

    pilha->topo = pilha->topo->prox;
    free(elementoRemovido);
}

void liberarPilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("!");
    }

    while (!pilhaVazia(pilha)) {
        Elemento *elementoRemovido = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(elementoRemovido);
        printf("@");
    }

    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    while (1) {
        char link[61];
        scanf(" %[^\n]", link);

        if (link[1] == 0) {
            if (link[0] == 'B') {
                desempilharLink(&pilha);
            } else if (link[0] == 'E') {
                liberarPilha(&pilha);
                break;
            }
        } else {
            empilharLink(&pilha, link);
        }
    }

    return 0;
}

