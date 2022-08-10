#include <stdio.h> //biblioteca de entrada e saída
#include <stdlib.h> //para poder usar o system pause e cls
#include <locale.h> //para que acentos sejam exibidos normalmente

int main(){ //onde vai estar todo nosso programa
    setlocale(LC_ALL, "Portuguese"); //define a linguagem do programa para portugues e lê os acentos
    //cadastrar aluno(matrícula), remover aluno, Atualizar dados de um aluno, Listar alunos cadastrados,
    // Listar alunos aprovados, Listar alunos reprovados por média,Listar alunos reprovados por faltas
    int n=0;
    int matricula[30];
    int faltas[30];
    int notas[30][4];

    while(n!=6){ //repete ate apertar a tecla sair
        system("cls"); //limpa a tela
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
            system("cls");
            printf(" \t\tCadastro \n\n");
            printf("Matrícula do aluno \n");
            fflush(stdin); //fflush: armazena os nomes, sem ele se você desse espaço ia entrar em outra variável
            scanf(" %[^n]s",matricula); // lê uma string até que o usuário insira um novo caractere de linha

            printf("Faltas \n");
            fflush(stdin);
            scanf(" %[^n]s",faltas);

            printf("Notas \n");
            fflush(stdin);
            scanf(" %[^n]s",notas);

            printf(" \n\n");
            printf(" \t\tCadastro feito com sucesso!\n");
            system("pause");
            break;

        case 2: //remover aluno case 4
            //Alertas de erro: matrícula não encontrada, vetor vazio
            system("cls");
            int remover;
            printf("\t\tListagem de alunos cadastrados\n\n");
            printf("Matrícula: %d\n",matricula);

            printf(" \t\tRemover aluno\n\n");
            printf(" \t1Remover\n \t2Não remover\n");
            scanf("%d",&remover);
            if (remover == 1){
                memset(matricula,0,sizeof(matricula));//para preencher a memória com um determinada valor
                printf(" \tAluno removido\n");
            }
            else{
                printf(" \tMatrícula não encontrada\n");
            }
            system("paause");
            break;


        case 3: //atualizar dados de um aluno, a matrícula deve ser informada e não pode ser alterada
            system("cls");
            int atualizar;
            printf(" \t\tAtualizar dados \n\n");
            printf("Matrícula do aluno: %d\n",matricula);
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
            break;

        case 4://Listagem de alunos cadastrados
            system("cls");
            for (i = 1; i <=30; i++) { //contador diferente para nao atrapalhar na contagem cadastros
                    if(i < n){
                        printf("\t\tListagem de alunos cadastrados\n\n");
                        printf("Matrícula: %d\n",matricula[i]);
                        printf("Faltas: %d\n",faltas[i]);
                        printf("Notas: %d\n",notas[i]);
                    } else{
                        i = 30;
                        printf("\tERRO\n");
                    }
                }
                system("pause");
                break;

        case 5://Listagem de alunos aprovados
            //Média igual ou superior a 7,0 E frequência acima ou igual ao 60%) - Imprimir matrículas, médias e frequências;
            system("cls");
            int i, medianotas, frequencia;
             medianotas = notas/4;
             frequencia = faltas*0.6;
            for (i = 1; i <=30; i++) {
                    if((i < n) && (medianotas>=7) && (faltas>=frequencia)){
                        printf("\t\tListagem de alunos aprovados\n\n");
                        printf("Matrícula: %d\n",matricula[i]);
                        printf("Faltas: %d\n",faltas[i]);
                        printf("Notas: %d\n",notas[i]);
                    } else{
                        i = 30;
                        printf("\tERRO\n");
                    }
                }
                system("pause");
                break;

        case 6://Listagem de alunos reprovados por média
            //Imprimir matrículas e médias
            system("cls");
            for (i = 1; i <=30; i++) {
                    if(i < n && (medianotas<7)){
                        printf("\t\tListagem de alunos reprovados por média\n\n");
                        printf("Matrícula: %d\n",matricula[i]);
                        printf("Notas: %d\n",notas[i]);
                    } else{
                        i = 30;
                        printf("\tERRO\n");
                    }
                }
                system("pause");
                break;

        case 7://Listagem de alunos reprovados por faltas
            //(frequência abaixo de 60%) - Imprimir matrículas e frequências
            system("cls");
            for (i = 1; i <=30; i++) {
                    if(i < n && (faltas<frequencia){
                        printf("\t\tListagem de alunos cadastrados\n\n");
                        printf("Matrícula: %d\n",matricula[i]);
                        printf("Faltas: %d\n",faltas[i]);
                    } else{
                        i = 30;
                        printf("\tERRO\n");
                    }
                }
                system("pause");
                break;
    }
    }
    return 0;
}
