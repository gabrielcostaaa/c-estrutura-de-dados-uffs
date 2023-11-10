#include <stdio.h>
#include <stdlib.h>

// DEFINIÇÕES DAS STRUCTS ###################################################

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
    struct employee *prev;
} Employee;

// FUNÇÕES DO PROGRAMA #######################################################

// CRIAR UM FUNCIONÁRIO*******************************************************
Employee *createEmployee(int id, char *name, double income, int dia, int mes, int ano)
{
    Employee *func = malloc(sizeof(Employee));
    func->id = id;
    strcpy(func->name, name);
    func->income = income;
    func->dbirth.dia = dia;
    func->dbirth.mes = mes;
    func->dbirth.ano = ano;
    func->next = NULL;
    func->prev = NULL;
    return func;
}

// INSERIR NO INICIO DA LISTA *********************************
Employee *appendBefore(Employee *f, Employee *e)
{
    Employee *aux = f;
    if (f == NULL)
    {
        f = e;
    }
    else
    {
        while (aux->prev != NULL)
        {
            aux = aux->prev;
        }
        aux->prev = e;
        e->next = aux;
        f = e;
    }
    return f;
}

// INSERIR NO FINAL DA LISTA *********************************
Employee *appendAfter(Employee *f, Employee *e)
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
        e->prev = aux;
    }
    return f;
}

// PERCORRE LISTA ENCADEADA IMPRIMINDO CADA NODE *********************************
void printList(Employee *f)
{
    Employee *aux = f;
    while (aux != NULL)
    {
        printf("\nId: %d\n", aux->id);
        printf("Nome: %s\n", aux->name);
        printf("Salario: %.2lf\n", aux->income);
        printf("Nascimento: %d/%d/%d\n", aux->dbirth.dia, aux->dbirth.mes, aux->dbirth.ano);
        aux = aux->next;
    }
}

// BUSCAR FUNCIONÁRIO POR ID ******************************************************
Employee *findEmployeeByID(Employee *f, int id)
{
    Employee *aux = f;

    while (aux != NULL)
    {
        if (aux->id == id)
        {
            return aux;
        }

        aux = aux->next;
    }

    printf("Funcionário com ID %d não encontrado.\n", id);
    return NULL;
}

// DELETAR FUNCIONÁRIO POR ID ********************************************************
Employee *deleteEmployeeByID(Employee *f, int id)
{
    Employee *aux = f;

    while (aux != NULL)
    {
        if (aux->id == id)
        {
            // Verificar se é o primeiro nó da lista
            if (aux->prev == NULL)
            {
                f = aux->next;
                if (f != NULL)
                {
                    f->prev = NULL;
                }
            }
            else if (aux->next == NULL)
            { // Verificar se é o último nó da lista
                aux->prev->next = NULL;
            }
            else
            { // Nó intermediário
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }
            free(aux);
            return f;
        }
        aux = aux->next;
    }

    printf("Funcionário com ID %d não encontrado.\n", id);
    return f;
}

// INSERIR ANTES DO ELEMENTO DA LISTA DADO O ID DELE *********************************
Employee *AfterID(Employee *f, Employee *e, int id)
{
    Employee *aux = f;
    // CASO LISTA VAZIA
    if (f == NULL)
    {
        f = e;
        return f;
    }
    // CASO ID SEJA O PRIMEIRO ELEMENTO DA LISTA (NOVO NODE PASSARA A SER O PRIMEIRO DAI)
    if (aux->id == id)
    {
        e->next = aux;
        e->prev = NULL;
        aux->prev = e;
        f = e;
        return f;
    }

    while (aux->next != NULL)
    {
        if (aux->id == id)
        {
            e->next = aux;
            e->prev = aux->prev;
            aux->prev->next = e;
            aux->prev = e;
            return f;
        }
        aux = aux->next;
    }
    // CASO ID NO FINAL
    if (aux->id == id)
    {
        e->next = aux;
        e->prev = aux->prev;
        aux->prev->next = e;
        aux->prev = e;
    }

    return f;
}
// BUSCA FUNCIONÁRIO E IMPRIME SUAS INFORMAÇÕES DADO ID *****************************

void buscarFuncionarioPorID(Employee *f, int id)
{
    Employee *aux = f;
    while (aux != NULL)
    {
        if (aux->id == id)
        {
            printf("\nFuncionário encontrado com ID: %d\n\n", id);
            printf("Id: %d\n", aux->id);
            printf("Nome: %s\n", aux->name);
            printf("Salário: %.2lf\n", aux->income);
            printf("Nascimento: %d/%d/%d\n", aux->dbirth.dia, aux->dbirth.mes, aux->dbirth.ano);
            return;
        }
        aux = aux->next;
    }
    printf("Funcionário com ID %d não encontrado.\n", id);
}

// EXECUÇÃO DO PROGRAMA #######################################################

int main()
{
    Employee *first = NULL;
    Employee *func = NULL;
    int N;

    // Solicita o número de funcionários a serem inseridos na lista
    printf("Quantos funcionários deseja adicionar? ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int id;
        char name[41];
        double income;
        int dia, mes, ano;

        // Preenche os detalhes do funcionário
        printf("Preencha o ID do funcionário %d: ", i + 1);
        scanf("%d", &id);
        printf("Preencha o nome do funcionário %d: ", i + 1);
        scanf(" %40s", name); // Leitura segura do nome (limite de 40 caracteres).
        printf("Preencha o salário do funcionário %d: ", i + 1);
        scanf("%lf", &income);
        printf("Preencha a data de nascimento do funcionário %d (dia mês ano): ", i + 1);
        scanf("%d %d %d", &dia, &mes, &ano);

        // Cria o funcionário usando sua função createEmployee
        func = createEmployee(id, name, income, dia, mes, ano);

        // Adiciona o funcionário à lista
        first = appendBefore(first, func);
    }

    // Imprime a lista de funcionários usando sua função printList
    printf("Lista de Funcionários:\n");
    printList(first);

    // Exemplo de como buscar um funcionário por ID e imprimir suas informações
    int id_a_buscar;
    printf("Digite o ID do funcionário que deseja buscar: ");
    scanf("%d", &id_a_buscar);
    buscarFuncionarioPorID(first, id_a_buscar);

    // Exemplo de como excluir um funcionário por ID
    // int id_a_excluir;
    // printf("Digite o ID do funcionário que deseja excluir: ");
    // scanf("%d", &id_a_excluir);
    // first = deleteEmployeeByID(first, id_a_excluir);

    return 0;
}
