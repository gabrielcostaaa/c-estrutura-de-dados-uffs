#include <stdio.h>
#include <string.h>

int main()
{

    int Ngame = 0, AlturaMinima = 0, identificado = 0, Pgame = 0, result = 0;

    while (scanf("%d %d", &Ngame, &AlturaMinima) != EOF){

    for (int i = 0; i < Ngame; i++)
    {
        scanf("%d %d", &identificado, &Pgame);

        if (identificado == AlturaMinima)
        {
            if (Pgame == 0)
            {
                result += 1;
            }
        }
    }
    printf("%d\n", result);
    result = 0;

}
    return 0;
}