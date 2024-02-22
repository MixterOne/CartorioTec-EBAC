#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    int escolha = 1; // Inicializamos com 1 para entrar no loop pelo menos uma vez

    while (escolha == 1) {
        printf("Digite o CPF a ser cadastrado: ");
        scanf("%s", cpf);

        strcpy(arquivo, cpf);

        FILE *file;
        file = fopen(arquivo, "w");
        fprintf(file, cpf);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ",");
        fclose(file);

        printf("Digite o nome a ser cadastrado: ");
        scanf("%s", nome);

        file = fopen(arquivo, "a");
        fprintf(file, nome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ",");
        fclose(file);

        printf("Digite o sobrenome a ser cadastrado: ");
        scanf("%s", sobrenome);

        file = fopen(arquivo, "a");
        fprintf(file, sobrenome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ",");
        fclose(file);

        printf("Digite o cargo a ser cadastrado: ");
        scanf("%s", cargo);

        file = fopen(arquivo, "a");
        fprintf(file, cargo);
        fclose(file);

        printf("Deseja cadastrar mais um usu�rio? (1 - Sim, 0 - N�o): ");
        scanf("%d", &escolha);
        
        system("cls");
    }
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int opcao = 0; //Definindo as vari�veis
	int laco = 1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio Tec ### \n\n");
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0){
		for(laco=1; laco=1;){
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio Tec ### \n\n"); //Inicio do menu
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema \n\n");
			printf("Op��o que deseja: ");//Final do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls"); //responsavel por limpar a tela
		
		
			switch(opcao) //Inicio da sele��o do menu
			{
				case 1:
					registro(); //chamada de fun��es
				break;
			
				case 2:
					consulta(); //chamada de fun��es
				break;
			
				case 3:
					deletar(); //chamada de fun��es
				break;	
			
				case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
				break;	
			
				default:
					printf("Essa op��o n�o est� disponivel!\n");
					system("pause");
				break;
			} //Fim da sele��o
	
		}
	}
	else
		printf("Senha incorreta!");
}



