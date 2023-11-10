#include <stdio.h>
#include <string.h>

int main()
{

    int Nvisitantes = 0, AlturaMinima = 0, AlturaMaxima = 0, AlturaVisitante = 0, result = 0;

    while (scanf("%d %d %d", &Nvisitantes, &AlturaMinima, &AlturaMaxima) != EOF){

    for (int i = 0; i < Nvisitantes; i++) {
        scanf("%d", &AlturaVisitante);

        if (AlturaVisitante >= AlturaMinima && AlturaVisitante <= AlturaMaxima) {
                result += 1;
            }
    }

    printf("%d\n", result);
    result = 0;

    }
    return 0;
}