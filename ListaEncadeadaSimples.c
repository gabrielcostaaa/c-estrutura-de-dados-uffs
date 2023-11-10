#include <stdio.h>
#include <stdlib.h>

typedef struct date
{
    int dia;
    int mes;
    int ano;
} Date;

typedef struct employee
{
    int id;
    char name[41];
    double income;
    Date dbirth;
    struct employee *next;
} Employee;

Employee *append(Employee *f, Employee *e)
{
    Employee *aux = f;
    if (f == NULL)
    {
        f = e;
    }
    else
    {
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = e;
    }
    return f;
}

void printList(Employee *f)
{
    Employee *aux = f;
    while (aux != NULL)
    {
        printf("Id: %d\n", aux->id);
        printf("Nascimento: %d %d %d\n", aux->dbirth.dia, aux->dbirth.mes, aux->dbirth.ano);
        aux = aux->next;
    }
}

int main()
{
    Employee *first = NULL;
    Employee *func = NULL;

    while (1)
    {
        func = malloc(sizeof(Employee));

        if (func == NULL)
        {
            printf("Erro na alocação de memória\n");
            return 1;
        }

        printf("Preencha o ID do funcionário:");
        scanf("%d", &func->id);
        if (func->id == 0)
        {

            break;
        }
        printf("Preencha o nome do funcionário:");
        scanf(" %40s", func->name);
        printf("Preencha o salário do funcionário:");
        scanf("%lf", &func->income);
        printf("Preencha o aniversário do funcionário:");
        scanf("%d %d %d", &func->dbirth.dia, &func->dbirth.mes, &func->dbirth.ano);

        func->next = NULL;

        first = append(first, func);
    }

    printList(first);
    return 0;
}
