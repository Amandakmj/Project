#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno
{
    int matricula;
    float notas[4];
    int faltas;
    int ativo;
    int turma;
    char nome[50];
    int media;
};
struct aluno;

struct aluno alunos[30];

void menu();
void cadastro();
void remover();
void atualizar();
void cadastrados();
void aprovados();
void mreprovados();
void freprovados();

FILE *farq;

int main(int argc, int const *argv[])
{

    farq = fopen("aluno.txt", "wb");


    for (int i = 0; i < 30; i++)
    {
        alunos[i].matricula = -1;
        alunos[i].ativo = 0;
    }
    setlocale(LC_ALL, "portuguese");
    menu();

    savefile();
    return 0;
}

void menu()
{
    system("cls");
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

        switch (opcao)
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
            if(opcao!=0){
                printf(" \n ERRO\n ");
            }
            break;
        }
    } while (opcao != 0);
}

void cadastro()
{
    system("cls");

    struct aluno alunoNovo;
    int index = -1;

    printf("\nMatrícula: ");
    scanf("%d", &alunoNovo.matricula);

    printf("Turma: ");
    scanf("%d", &alunoNovo.turma);

     printf("Nome: ");
    scanf("%s", alunoNovo.nome);

    for (int i = 0; i < 30; i++)
    {
        if (alunos[i].matricula == alunoNovo.matricula && alunos[i].ativo != 0)
        {
            printf("Matrícula já cadastrada!");

            break;
        }
        else
        {
            if (alunos[i].ativo == 0)
            {
                index = i;
            }

        }
    }
    if (index != -1)
    {
        printf("\nFaltas: ");
        scanf("%d", &alunoNovo.faltas);

        for (int i = 0; i < 4; i++)
        {
            printf("Nota %d: ", i+1);
            scanf("%f", &alunoNovo.notas[i]);
        }
        alunoNovo.ativo = 1;
        alunos[index] = alunoNovo;
        printf("\nAluno cadastrado!\n");
    }
}

void remover()
{
    system("cls");
    int index=0;
    int matricula;

    printf("\n Digite a matricula do aluno a ser removido: ");
    scanf("%d", &matricula);

    for (int i = 0; i < 30; i++)
    {
        if (matricula == alunos[i].matricula && alunos[i].ativo != 0)
        {
            alunos[i].ativo = 0;
            printf("\nAluno foi excluido com sucesso!\n");
            index=1;
        }
    }
         if(index==0)
        {
            printf("\nAluno nao encontrado!\n");
        }
}
void atualizar()
{
    system("cls");
    int matricula;
    int index = -1;
    int opt;

    printf(" \t\tAtualizar dados \n\n");
    printf("Digite a matrícula do aluno: \n\n");
    scanf("%d", &matricula);

    for (int i = 0; i < 30; i++)
    {
        if (alunos[i].matricula == matricula && alunos[i].ativo != 0)
        {
            index = i;
        }
    }
    if (index != -1)
    {
        printf(" \t1. Atualizar as faltas \n");
        printf(" \t2. Atualizar as notas \n");
        scanf("%d", &opt);

        if (opt == 1)
        {
            printf("Atualizar as faltas: \n");
            int faltas;
            scanf("%d", &faltas);
            alunos[index].faltas = faltas;
        }
        else if (opt == 2)
        {
            printf("Atualizar as notas: \n");
            for (int i = 0; i < 4; i++)
            {
                printf("Nota %d:", i + 1);
                float nota;
                scanf("%f", &nota);
                alunos[index].notas[i] = nota;
            }
        }

    } else {
        printf("/n Aluno não encontrado");
        system("pause");
    }
}

void cadastrados()
{
    system("cls");
    printf("\n Lista de alunos cadastrados\n");
    for (int i = 0; i < 30; i++)
    {
        if (alunos[i].ativo != 0)
        {
            printf("\n--------------------------");
            printf("\nMatrícula: %d\n", alunos[i].matricula);
            printf("Turma: %d\n", alunos[i].turma);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Faltas: %d\n", alunos[i].faltas);
            for (int j = 0; j < 4; j++)
            {
                printf("Nota %d: %0.2f \n", j+1, alunos[i].notas[j]);
            }
            printf("\n--------------------------");
        }
    }
}

void aprovados()
{
    system("cls");
    float soma, media;
    printf("\t\tListagem de alunos aprovados\n\n");
    for (int i = 0; i <= 30; i++)
    {
        soma = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3];
        media = soma / 4;
        if (media >= 7 && alunos[i].faltas <= 15  && alunos[i].matricula!=-1)
        {
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Turma: %d\n", alunos[i].turma);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Nota final: %0.2f\n", media);
            printf("Faltas: %d\n\n", alunos[i].faltas);
        }
    }
    system("pause");
}
void mreprovados()
{
    system("cls");
    float soma, media;
    printf("\t\tListagem de alunos reprovados por média\n\n");
    for (int i = 0; i <= 30; i++)
    {
        soma = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3];
        media = soma / 4;
        if (media < 7 && alunos[i].matricula!=-1)
        {
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Turma: %d\n", alunos[i].turma);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Nota final: %0.2f\n\n", media);
        }
    }
    system("pause");
}
void freprovados()
{
    system("cls");
    printf("\t\tListagem de alunos reprovados por faltas\n\n");
    for (int i = 0; i <= 30; i++)
    {
        if (alunos[i].faltas > 15 && alunos[i].matricula!=-1)
        {
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Turma: %d\n", alunos[i].turma);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Faltas: %d\n\n", alunos[i].faltas);
        }
    }
    system("pause");
}

int savefile(){

    for (int i = 0; i < 30; i++){
        //Matricula, notas[4], faltas, ativo, turma, nome, média(apenas se a função que calcula a média for chamada)
        fprintf(farq, "%d.%f.%f.%f.%f.%d.%d.%d.%s.%d;\n",
                alunos[i].matricula,
                alunos[i].notas[0],
                alunos[i].notas[1],
                alunos[i].notas[2],
                alunos[i].notas[3],
                alunos[i].faltas,
                alunos[i].ativo,
                alunos[i].turma,
                alunos[i].nome,
                alunos[i].media);
    }

    fclose(farq);
}
