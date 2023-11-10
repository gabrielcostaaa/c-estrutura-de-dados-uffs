#include <stdio.h>
#include <stdlib.h>

// DEFINIÇÕES DAS STRUCTS ###################################################

typedef int Item;

typedef struct TQueue {
    Item item;
    struct TQueue *next;
} EQueue;

typedef struct {
    EQueue *head;
    EQueue *tail;
} Queue;


// FUNÇÕES DO PROGRAMA ######################################################



// EXECUÇÃO #################################################################

int main (){

Queue *queue;




    return 0;
}