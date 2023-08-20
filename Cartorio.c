#include <stdio.h> // biblioteca de comunicação com usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável pelas strings

int registro() // Função para registrar os usuários 
{
	// Inicio da criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: \n"); // colentando informação do usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsável pela copia dos valores da string
	
	FILE *file; // criação do arquivo
	file = fopen(arquivo, "w"); // criação do arquivo e "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável 
	fclose(file); // fechamento do arquivo
	
	file = fopen(arquivo, "a"); // atualização do arquivo e "a" é para atualizar o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n"); // colentando informação do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); // atualização do arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // atualização do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n"); // colentando informação do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); // atualização do arquivo
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // atualização do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n"); // colentando informação do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); // atualização do arquivo
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // pausa para a visualização das informações
	
}

int consulta() // Função para consultar os nomes
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa
	
	// Inicio da criação das variáveis/strings
	char cpf[40];
	char conteudo[200];
	// Final da criação das variáveis/strings
	
	printf("Digite o CPF a ser consultado: \n"); // colentando informação do usuário
	scanf("%s", cpf);
	
	FILE *file; // criação do arquivo
	file = fopen(cpf, "r"); // Leitura do arquivo criado e "r" significa ler
	
	if(file == NULL) // condição para que o usuário não consulte informações inexistentes
	{
		printf("Não foi possível abrir o arquivo! Arquivo não localizado!! \n\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL) // condição para a exibição das informações do usuário consultado
	{
		printf("\n Essas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa para a visualização das informações
	
}

int deletar() // Função para deletar os nomes
{
	// Inicio da criação das variáveis/strings
	char cpf[40];
	// Final da criação das variáveis/strings
	
	printf("Digite o CPF do usuário a ser deletado: \n"); // colentando informação do usuário a ser deletado
	scanf("%s", cpf);
	
	remove(cpf); // comando para a remoção dos dados
	
	FILE *file; // criação do arquivo
	file = fopen(cpf, "r"); 
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!!! \n"); // Mensagem de conclusão da remoção do usuário
		system("pause");
	}
}


int main()
{
	int opcao=0; // Definindo as variáveis
	int rep=1;
	
	for(rep=1;rep=1;)
	{
	
		system("cls"); // responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem do programa
	
		printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
	
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n\n"); 
		printf("Opção:"); // Fim do menu 
		
		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls"); // responsável por limpar a tela
		
		switch(opcao) // Inicio da seleção do menu
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
			consulta(); // chamada de funções
			break;
			
			case 3:
			deletar(); // chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponível!!!\n\n");
			system("pause");
			break;
		} // Fim da seleção do menu
	
    }
}
