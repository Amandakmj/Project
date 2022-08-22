#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno
{
    int matricula[30];
    int notas[30][4];
    int falta[30];
    int ativo;
    int opcao;
    int media;
}; struct aluno alunos[30];

void menu();
void cadastro();
void remover();
void atualizar();
void cadastrados();
void aprovados();
void mreprovados();
void freprovados();

int main(int argc, int const *argv[])
{
    setlocale(LC_ALL,"portuguese");
    menu();
    return 0;
}

void menu()
{
    system ("cls");
    int opcao;
    do
    {
        printf(" \tMenu de opções \n");
        printf(" \n1 Cadastro de aluno");
        printf(" \n2 Remover aluno");
        printf(" \n3 Atualizar dados de um aluno");
        printf(" \n4 Listagem de alunos cadastrados");
        printf(" \n5 Listagem de alunos aprovados");
        printf(" \n6 Listagem de alunos reprovados por média");
        printf(" \n7 Listagem de alunos reprovados por faltas");
        printf(" \n0 Sair \n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                cadastro();
            break;
            case 2:
                remover();
            break;
            case 3:
                atualizar();
            break;
            case 4:
                cadastrados();
            break;
            case 5:
                aprovados();
            break;
            case 6:
                mreprovados();
            break;
            case 7:
                freprovados();
            break;
            default:
                 printf(" \n ERRO ");
            break;
        }
    }
    while(opcao!=0);
}

    void cadastro()
    {
        system("cls");
        int matricula[30];
        int notas[30][4];
        int falta[30];
        int ativo;
        int opcao;
        int i;

        do
        {
            printf("\nMatrícula: \n\n");
            scanf("%d", alunos[i]);
            printf("Faltas: \n");
            scanf("%d", falta);
            printf(" Primeira nota:");
            scanf("%d", notas[0]);
            printf(" Segunda nota:");
            scanf("%d", notas[1]);
            printf(" Terceira nota:");
            scanf("%d", notas[2]);
            printf(" Quarta nota:");
            scanf("%d", notas[3]);

            printf(" \n1 - Continuar \n0 - Sair \n");
            scanf("%d", &opcao);
        } while (opcao != 0);
    }

    void remover()
    {
        system("cls");
        int matricula;
        int i;
        printf("\n Digite a matricula do aluno a ser removido: ");
        scanf("%d", &alunos[i]);
        alunos[matricula].ativo = 0;
        printf("\n Aluno foi excluido com sucesso\n");

    }
    void atualizar()
    {
        system("cls");
        int atualizar, pesquisar;
        int matricula[30];
        int notas[30][4];
        int falta[30];

            printf(" \t\tAtualizar dados \n\n");
            printf("Digite a matrícula do aluno: \n\n");
            scanf("%d", &pesquisar);

            for (int i=0;i<30;i++){
                if(matricula[i]==pesquisar){
                    printf(" \tMatrícula: %d", matricula);
                }
            }
            printf(" \t1. Atualizar as faltas \n");
            printf(" \t2. Atualizar as notas \n");
            scanf(" %d",&atualizar);

            if(atualizar==1){
                printf("Atualizar as faltas: \n");
                scanf("%d",&falta);
            }
            else if(atualizar==2){
                printf("Atualizar as notas: \n");
                scanf("%d",&notas);
            }
            else{
                printf("\t\tERRO");
            }
            system("pause");
    }

    void cadastrados(){
        system("cls");
        int matricula;
        printf("\n Lista de alunos cadastrados\n");
        for (int i = 0; i < 30; i++)
        {
            {
                printf("\nMatrícula: %d\n", alunos[i],matricula);
                printf("Faltas: %d\n", alunos[i].falta);
                printf("Nota 1: %d \n", alunos[i].notas[0]);
                printf("Nota 2: %d\n", alunos[i].notas[1]);
                printf("Nota 3: %d\n", alunos[i].notas[2]);
                printf("Nota 4: %d\n\n", alunos[i].notas[3]);
            }
        }
    }

    void aprovados()
    {
        system("cls");
        int soma, media;
        int notas[4];
        soma = notas[0] + notas[1] + notas[2] + notas[3];
        media = soma/4;
        printf("\t\tListagem de alunos aprovados\n\n");
            for (int i = 0; i <= 30; i++) {
                    if(alunos[i].media >= 7 && alunos[i].falta >= 21){
                        printf("Matrícula: %d\n", alunos[i].matricula);
                        printf("Nota final: %d\n", alunos[i].media);
                        printf("Faltas: %d\n\n", alunos[i].falta);
                    }
                }
                system("pause");
    }
    void mreprovados()
    {
        system("cls");
        int soma, media;
        int notas[4];
        soma = notas[0] + notas[1] + notas[2] + notas[3];
        media = soma/4;
        printf("\t\tListagem de alunos reprovados por média\n\n");
            for (int i = 0; i <= 30; i++) {
                    if(alunos[i].media < 7){
                        printf("Matrícula: %d\n", alunos[i].matricula);
                        printf("Nota final: %d\n\n", alunos[i].media);
                    }
                }
                system("pause");
    }
    void freprovados()
    {
        system("cls");
            printf("\t\tListagem de alunos reprovados por faltas\n\n");
            for (int i = 0; i <= 30; i++) {
                    if(alunos[i].falta > 21){
                        printf("Matrícula: %d\n", alunos[i].matricula);
                        printf("Faltas: %d\n\n", alunos[i].falta);
                    }
                }
                system("pause");
    }

