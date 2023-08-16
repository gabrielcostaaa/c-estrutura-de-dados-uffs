#include <stdio.h>

int main(int argc, char const *argv[])
{
    // AUTORIA DOS CÓDIGOS: GABRIEL SANTOS COSTA
    
/*
1. Faça um programa que peça o número de horas trabalhadas e o valor da hora de um determinado funcionário. 
Em seguida, calcule o salário do funcionário. Caso o funcionário tenha trabalhado mais de 200 horas, o salário final é acrescido de 5%. 
Exemplos de execução:
	Horas trabalhadas: 120				Horas trabalhadas: 210
	Valor da hora: 100,00				Valor da hora: 50.00
	Salário: 12000.00					Salário: 11025.00
*/
/*
    int hora;
    float valor_hora, salario;

    printf("Digite o número de horas trabalhadas: \n");
    scanf("%d", &hora);
    printf("Digite quanto ganha por hora trabalhada: \n");
    scanf("%f", &valor_hora);

    salario = hora * valor_hora;

        if (hora > 200){
        salario = salario + (salario * 0.05);
    }

    printf("Horas trabalhadas: %d \n", hora);
    printf("Valor da hora: %.2f \n", valor_hora);
    printf("Salario: %.2f \n", salario);
*/



/*
2. Uma loja vende produtos à vista e a prazo (pagamento 30 dias depois da compra). À vista tem um desconto de 5% e a prazo um acréscimo de 10%.
 Faça um programa em C que peça o preço do produto e a forma de pagamento: 1 para à vista e 2 para a prazo. Depois apresente o preço final do produto.
 Exemplos de execução:
	Preço do produto: 120.00				Preço do produto: 200.00
	Forma de pagamento: 1				Forma de pagamento: 2
	Preço a vista: 114.00				Preço a prazo: 220.00
*/
/*

float preco, valor_final;
int forma_pagto;

printf("Digite o preco do produto: \n");
scanf("%f", &preco);
printf("Digite a forma de pagamento - [1] a Vista [2] a Prazo -: \n");
scanf("%d", &forma_pagto);

if (forma_pagto == 1){
    valor_final = preco - (preco * 0.05);
    printf("Preco do produto: %.2f \n", preco);
    printf("Forma de pagamento: %d \n", forma_pagto);
    printf("Preco a vista: %.2f \n", valor_final);
} else {
    if (forma_pagto == 2){
        valor_final = preco + (preco * 0.1);
        printf("Preco do produto: %.2f \n", preco);
        printf("Forma de pagamento: %d \n", forma_pagto);
        printf("Preco a prazo: %.2f \n", valor_final);
    }
    
}

*/
/*
3. Faça um programa que calcule a duração de um evento qualquer. Para tal, o programa pede a hora de início e hora de fim (sem os minutos), as horas serão informadas de 0 a 23.
 Perceba que um evento pode começar em um dia e acabar em outro. Os eventos nunca terão duração de mais de 24 horas. 
 Exemplos de execução:
	Início: 12			Início: 10			Início: 21
	Fim: 4				Fim: 15			Fim: 6
	Duração: 16 horas		Duração: 5 horas		Duração: 9 horas
*/
/*

int hora_inicio, hora_fim, resultado_hora;

printf("Digite o horario do inicio: \n");
scanf("%d", &hora_inicio);
printf("Digite o horario do fim: \n");
scanf("%d", &hora_fim);

 if (hora_fim >= hora_inicio) {
        resultado_hora = hora_fim - hora_inicio;
    } else {
        resultado_hora = 24 - hora_inicio + hora_fim;
    }

printf("Inicio: %d \n", hora_inicio);
printf("Fim: %d \n", hora_fim);
printf("Duracao: %d horas", resultado_hora);

*/
/*
4. Faça um programa que peça 4 números inteiros. Em seguida, apresente quantos números informados são negativos e quantos são positivos (considere o 0 como positivo). Exemplos de execução:
	N1: 12			N1: -1
	N2: 4			N2: -20
	N3: -3			N3: -7
	N4: 5			N4: -11
	3 (+) e 1 (-)	0 (+) e 4 (-)
*/
/*

int a, b, c, d, contador_positivo, contador_negativo;

printf("Digite os números a serem lidos: \n");
scanf("%d %d %d %d", &a, &b, &c, &d);

contador_negativo = 0;
contador_positivo = 0;

if (a >= 0) {
    contador_positivo += 1;
} else {
    contador_negativo += 1;
}

if (b >= 0) {
    contador_positivo += 1;
} else {
    contador_negativo += 1;
}

if (c >= 0) {
    contador_positivo += 1;
} else {
    contador_negativo += 1;
}

if (d >= 0) {
    contador_positivo += 1;
} else {
    contador_negativo += 1;
}

printf("São %d positivos e %d negativos", contador_positivo, contador_negativo);

*/
/*
5. Você vai fazer um programa para classificar os competidores segundo as suas posições. 
Foram criadas 5 classes: Top 5 (1-5), Top 10 (6-10), Top 20 (11-20), Top 30 (21-30) e Top 100 (outras posições). 
Faça um programa que peça a posição do competidor e indique a classe do mesmo. 
Exemplos de execução:
	Posição: 12		Posição: 5		Posição: 34
	Top 20			Top 5			Top 100
*/
/*
int position;

printf("Digite sua posição: \n");
scanf("%d", &position);

if (position <= 5 && position >= 1) {
    printf("Posição: %d\n", position);
    printf("Top 5");
}
if (position <= 10 && position >= 6) {
    printf("Posição: %d\n", position);
    printf("Top 10");
}
if (position <= 20 && position >= 11) {
    printf("Posição: %d\n", position);
    printf("Top 20");
}
if (position <= 30 && position >= 21) {
    printf("Posição: %d\n", position);
    printf("Top 30");
}
if (position >= 31) {
    printf("Posição: %d\n", position);
    printf("Top 100");
}
*/
/*
6. Sabendo que as faixas etárias para votação são: 18 a 70 anos voto obrigatório; 16, 17 e acima de 70 anos voto facultativo;
 outras idades (ou seja, menor que 16 anos) não pode votar, crie um programa que processa essa verificação. 
 Exemplos de execução:

	Idade: 20			Idade: 17			Idade: 12
	Voto obrigatório		Voto facultativo		Não pode votar
*/
/*
int age;

printf("Digite sua idade: \n");
scanf("%d", &age);

if (age >= 1 && age <= 15) {
    printf("Idade: %d\n", age);
    printf("Não pode votar");
}
if (age >= 16 && age <= 17 || age >= 71 ) {
    printf("Idade: %d\n", age);
    printf("Voto facultativo");
}
if (age >= 18 && age <= 70) {
    printf("Idade: %d\n", age);
    printf("Voto obrigatório");
}

*/

    return 0;
}