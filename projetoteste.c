#include <stdio.h> //biblioteca de entrada e saída
#include <stdlib.h> //para poder usar o system pause e cls
#include <locale.h> //para que acentos sejam exibidos normalmente

//case 1 e 2 adicionar coisas, fazer com que o sistema volte para o início
    int matricula[30];
    int faltas[30];
    int notas[30][4];
    int n=0;

int main(){ //onde vai estar todo nosso programa
    setlocale(LC_ALL, "Portuguese"); //define a linguagem do programa para portugues e lê os acentos

    while(n!=8){ //repete ate apertar a tecla sair
        printf(" \tMenu de opções \n\n");
        printf("1.Cadastro de aluno \n");
        printf("2.Remover aluno \n");
        printf("3.Atualizar dados de um aluno \n");
        printf("4.Listagem de alunos cadastrados \n");
        printf("5.Listagem de alunos aprovados \n");
        printf("6.Listagem de alunos reprovados por média \n");
        printf("7.Listagem de alunos reprovados por faltas \n");
        printf("8.Sair \n");
        scanf(" %d", &n);

    switch(n){//para criar opções sem precisar digitar o if varias vezes
        case 1: //Alertas de erro devem ser gerados (exemplos: número de alunos maior que o tamanho do vetor, alunos com matrículas iguais
        system("cls");//limpa a tela
            while(n==1){
            printf(" \t\tCadastro \n\n");
            printf("Matrícula do aluno: \n");
            scanf(" %d", &matricula);
            printf("Digite as faltas: \n");
            scanf(" %d",&faltas);

            printf("Digite a nota 1: \n");
            scanf(" %d",&notas[0]);
            printf("Digite a nota 2: \n");
            scanf(" %d",&notas[1]);
            printf("Digite a nota 3: \n");
            scanf(" %d",&notas[2]);
            printf("Digite a nota 4: \n");
            scanf(" %d",&notas[3]);

            for (int i=0; i<30; i++)
                int ativo;
                int matricula[30];
                int notas[30][4];
                int falta[30];
                int opcao;
            {
                if (matricula[i].ativo==0){
                    matricula[i].notas[0] = notas[0];
                    matricula[i].notas[1] = notas[1];
                    matricula[i].notas[2] = notas[2];
                    matricula[i].notas[3] = notas[3];
                    strcpy(matricula[i])
                }

            }

            printf(" \t\tCadastro feito com sucesso!\n");
            printf(" \nAperte 1 para continuar ou 8 para sair\n");
            scanf("%d", &n);
            }
            system("pause");

        case 2: //remover aluno
            //Alertas de erro: matrícula não encontrada, vetor vazio
            system("cls");
            int remover;
            printf("\t\tListagem de alunos cadastrados\n\n");
            printf("Matrícula: %d\n",matricula);
            printf(" \t\tRemover aluno\n\n");
            printf(" \t1 Remover\n \t2 Não remover\n");
            scanf("%d",&remover);
            if (remover == 1){
                memset(matricula,0,sizeof(matricula));//para preencher a memória com um determinado valor
                printf(" \n\tAluno removido\n\n");
            }
            else{
                printf(" \tMatrícula não encontrada\n");
            }
            system("pause");


        case 3:
            system("cls");
            int atualizar;
            int pesquisar;
            int y;
            printf(" \t\tAtualizar dados \n\n");
            printf("Digite a matrícula do aluno: \n\n");
            scanf("%d", &pesquisar);
            for (y=0;y<30;y++){
                if(matricula[y]==pesquisar){
                    printf(" \tMatrícula: %d", matricula);
                }
            }
            printf(" \t1. Atualizar as faltas \n");
                printf(" \t2. Atualizar as notas \n");
                scanf(" %d",&atualizar);
                if(atualizar==1){
                printf("Atualizar as faltas: \n");
                scanf("%d",&faltas);
            }
                else if(atualizar==2){
                printf("Atualizar as notas: \n");
                scanf("%d",&notas);
            }
                else{
                printf("\t\tERRO");
            }
            system("pause");

    struct aluno{
    int matricula;
    int faltas;
    int notas[5];
    };
    struct aluno alunos[30];

        case 4:
            system("cls");
            int i;
            printf("\t\tListagem de alunos cadastrados\n\n");
            for (i = 1; i <=30; i++) { //contador diferente para nao atrapalhar na contagem cadastros
                    if(i < n){
                        printf("Matrícula: %d\n",matricula[i]);
                        printf("Faltas: %d\n",faltas[i]);
                        printf("Notas: %d\n\n",notas[i]);
                    } else{
                        printf("\tERRO\n");
                    }
                }
                system("pause");
                break;

        case 5:
            system("cls");
            printf("\t\tListagem de alunos aprovados\n\n");
            for (int x = 0; x <= 30; x++) {
                    if(alunos[x].notas[4] >= 7 && alunos[x].faltas >= 60/100){
                        printf("Matrícula: %d\n", matricula);
                        printf("Nota: %d\n", alunos[x].notas);
                        printf("Faltas: %d\n\n", alunos[x].faltas);
                    }
                }
                system("pause");
                break;

        case 6:
            system("cls");
            printf("\t\tListagem de alunos reprovados por média\n\n");
            for (int x = 0; x <= 30; x++) {
                    if(alunos[x].notas[4] <= 7){
                        printf("Matrícula: %d\n", matricula);
                        printf("Nota: %d\n\n", alunos[x].notas);
                    }
                }
                system("pause");
                break;

        case 7:
            system("cls");
            printf("\t\tListagem de alunos reprovados por faltas\n\n");
            for (int x = 0; x <= 30; x++) {
                    if(alunos[x].faltas >= 60/100){
                        printf("Matrícula: %d\n", matricula);
                        printf("Faltas: %d\n\n", alunos[x].faltas);
                    }
                }
                system("pause");
                break;
    }
    }
    return 0;
}
