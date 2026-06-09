
#include <stdio.h>

void listarNotas(float notas[], int quantidade);
float calculaMedia(float notas[], int quantidade);

int main()
{
    float notas[10];
    int quantidade = 0;
    int opcao;

    do
    {
        printf("\n==================\n");
        printf("-Sistema de notas-\n");
        printf("=====================\n");
        printf("-1. Adicionar nota-\n");
        printf("-2. Exibir notas-\n");
        printf("-3. Média da Turma-\n");
        printf("-4. Mostrar maior nota-\n");
        printf("-5. Mostrar menor nota-\n");
        printf("-6. Alunos aprovados-\n");
        printf("-7. Alunos reprovados-\n");
        printf("-8. Notas acima da média-\n");
        printf("-0. Sair-\n");
        printf("======================\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (quantidade < 10)
            {
                printf("Digite a nota: ");
                scanf("%f", &notas[quantidade]);
                quantidade++;
            }
            else
            {
                printf("\nLimite de notas atingido.\n\n");
            }
            break;
        case 2:
            listarNotas(notas, quantidade);
            break;
        case 3:
            if (quantidade > 0)
            {
                printf("Média: %.2f\n", calculaMedia(notas, quantidade));
            }
            else
            {
                printf("Nenhuma nota cadastrada ainda.\n");
            }
            break;
        case 4:
            if (quantidade > 0)
            {
                float maior = notas[0];
                for (int i = 1; i < quantidade; i++)
                {
                    if (notas[i] > maior)
                    {
                        maior = notas[i];
                    }
                }
                printf("Maior nota: %.1f\n", maior);
            }
            else
            {
                printf("Nenhuma nota cadastrada ainda.\n");
            }
            break;
        case 5:
            if (quantidade > 0)
            {
                float menor = notas[0];
                for (int i = 1; i < quantidade; i++)
                {
                    if (notas[i] < menor)
                    {
                        menor = notas[i];
                    }
                }
                printf("Menor nota: %.1f\n", menor);
            }
            else
            {
                printf("Nenhuma nota cadastrada ainda.\n");
            }

            break;
        case 6:
            if (quantidade > 0)
            {
                int aprovados = 0;
                for (int i = 0; i < quantidade; i++)
                {
                    if (notas[i] >= 6.0)
                    {
                        aprovados++;
                    }
                }
                printf("Alunos aprovados: %d\n", aprovados);
            }
            else
            {
                printf("Nenhuma nota cadastrada ainda.\n");
            }
            break;
        case 7:
            if (quantidade > 0)
            {
                int reprovados = 0;
                for (int i = 0; i < quantidade; i++)
                {
                    if (notas[i] < 60.0)
                    {
                        reprovados++;
                    }
                }
                printf("Alunos reprovados: %d\n", reprovados);
            }
            else
            {
                printf("Nenhuma nota cadastrada ainda.\n");
            }
            break;
        case 8:
            if (quantidade > 0)
            {
                float media = calculaMedia(notas, quantidade);
                printf("Notas acima da média:\n");
                for (int i = 0; i < quantidade; i++)
                {
                    if (notas[i] > media)
                    {
                        printf("%.1f\n", notas[i]);
                    }
                }
            }
            else
            {
                printf("Nenhuma nota cadastrada ainda.\n");
            }
            break;
        }
    } while (opcao != 0);

    return 0;
} // FIM DA CHAVE MAIN

void listarNotas(float notas[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("%.1f\n", notas[i]);
    }
}

float calculaMedia(float notas[], int quantidade)
{
    float soma = 0;
    for (int i = 0; i < quantidade; i++)
    {
        soma += notas[i];
    }
    return soma / quantidade;
}