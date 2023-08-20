#include <stdio.h> // biblioteca de comunica��o com usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel pelas strings

int registro() // Fun��o para registrar os usu�rios 
{
	// Inicio da cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: \n"); // colentando informa��o do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respons�vel pela copia dos valores da string
	
	FILE *file; // cria��o do arquivo
	file = fopen(arquivo, "w"); // cria��o do arquivo e "w" significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel 
	fclose(file); // fechamento do arquivo
	
	file = fopen(arquivo, "a"); // atualiza��o do arquivo e "a" � para atualizar o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n"); // colentando informa��o do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // atualiza��o do arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // atualiza��o do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n"); // colentando informa��o do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); // atualiza��o do arquivo
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // atualiza��o do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n"); // colentando informa��o do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); // atualiza��o do arquivo
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // pausa para a visualiza��o das informa��es
	
}

int consulta() // Fun��o para consultar os nomes
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa
	
	// Inicio da cria��o das vari�veis/strings
	char cpf[40];
	char conteudo[200];
	// Final da cria��o das vari�veis/strings
	
	printf("Digite o CPF a ser consultado: \n"); // colentando informa��o do usu�rio
	scanf("%s", cpf);
	
	FILE *file; // cria��o do arquivo
	file = fopen(cpf, "r"); // Leitura do arquivo criado e "r" significa ler
	
	if(file == NULL) // condi��o para que o usu�rio n�o consulte informa��es inexistentes
	{
		printf("N�o foi poss�vel abrir o arquivo! Arquivo n�o localizado!! \n\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL) // condi��o para a exibi��o das informa��es do usu�rio consultado
	{
		printf("\n Essas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa para a visualiza��o das informa��es
	
}

int deletar() // Fun��o para deletar os nomes
{
	// Inicio da cria��o das vari�veis/strings
	char cpf[40];
	// Final da cria��o das vari�veis/strings
	
	printf("Digite o CPF do usu�rio a ser deletado: \n"); // colentando informa��o do usu�rio a ser deletado
	scanf("%s", cpf);
	
	remove(cpf); // comando para a remo��o dos dados
	
	FILE *file; // cria��o do arquivo
	file = fopen(cpf, "r"); 
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!!! \n"); // Mensagem de conclus�o da remo��o do usu�rio
		system("pause");
	}
}


int main()
{
	int opcao=0; // Definindo as vari�veis
	int rep=1;
	
	for(rep=1;rep=1;)
	{
	
		system("cls"); // respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa
	
		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
	
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n\n"); 
		printf("Op��o:"); // Fim do menu 
		
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao) // Inicio da sele��o do menu
		{
			case 1:
			registro(); // chamada de fun��es
			break;
			
			case 2:
			consulta(); // chamada de fun��es
			break;
			
			case 3:
			deletar(); // chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!!!\n\n");
			system("pause");
			break;
		} // Fim da sele��o do menu
	
    }
}
