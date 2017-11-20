#pragma once
#include<Windows.h>
#include<stdio.h>
#include"Dados_de_arquivos.h"
#include"Cliente.h"
#include<stdlib.h>
#include"RAM.h"
#define CLIENTE 1
#define CADASTRAR_CLIENTE 1
#define EXIBIR_CLIENTE 2
enum modo {
	INCLUIR = 1,
	ALTERAR = 2,
	CONSULTAR = 3,
	EXCLUIR = 4,
	LISTAR = 5,
	GRAVAR = 6,
	SAIR_SEM_SALVAR = 7
		
}modo;



int menu_cliente_exibicao() {

	printf(" =========  CLIENTE =============  \n");
	printf("          1.incluir               \n");
	printf("          2.alterar               \n");
	printf("          3.consultar             \n");
	printf("          4.excluir               \n");
	printf("          5.listar                \n");
	printf("          6.gravar                \n");
	printf("          7.sair sem salvar       \n");

	int resultado;
	scanf("%d", &resultado);
	fflush(stdin);
	getchar();
	system("cls");
	return resultado;
}


int main() {
	Dados_de_arquivos* dados = malloc(sizeof(Dados_de_arquivos));
	Cliente* auxiliar=NULL;
	Cliente* c;
	init(dados);
	int i;
	int cod;
	RAM* ram=NULL;
	int controle;
	
	dados->arquivo_clientes = fopen(dados->nome_arquivo_clientes, "a+b");
	ram = DADOS_DE_ARQUIVO_carrega(dados);
	
	RAM* ram_copia = RAM_copia(ram);
	
	fclose(dados->arquivo_clientes);
	
	while (1) {
		switch (menu_cliente_exibicao())
		{
	
		case INCLUIR:
			c = NULL;
			c = CLIENTE_entrada_de_cliente();
			if (c != NULL) {
				RAM_adicionar_Cliente(ram, c);
				printf("Incluido com sucesso");

			}
			else {
				printf("cliente nulll");

			}
			system("PAUSE");
			system("cls");
			break;
		case LISTAR:
			system("cls");
			RAM_exibe(ram);
			printf("\n");
			system("PAUSE");
			system("cls");

			break;
		case CONSULTAR:
			auxiliar = NULL;
			system("cls");
			printf("Digite o codigo a ser buscado\n");
			fflush(stdin);
			scanf("%d", &i);
			auxiliar = RAM_busca_por_codigo(ram, i);
			if (auxiliar == NULL) {

				printf("Esse codigo nao esta cadastrado\n");
				system("PAUSE");
				system("cls");
			}
			else {
				system("cls");
				printf("Cliente de codigo %d encontrado!!\n", i);
				CLIENTE_exibe_cliente(auxiliar);

				printf("\n");
				system("PAUSE");
				system("cls");
			}
			auxiliar = NULL;
			break;
		case ALTERAR:
			auxiliar = NULL;
			system("cls");
			printf("Digite o codigo a ser buscado para a ALTERACAO\n");
			fflush(stdin);
			scanf("%d", &i);
			auxiliar = RAM_busca_por_codigo(ram, i);
			if (auxiliar == NULL) {

				printf("Esse codigo nao esta cadastrado\n");
				system("PAUSE");
				system("cls");
			}
			else {
				system("cls");
				printf("Cliente de codigo %d encontrado!!\n", i);
				Cliente* novo = CLIENTE_entrada_de_cliente();
				printf("Deseja mudar o codigo do cliente a se alterar?(s/n)\n");
				fflush(stdin);
				scanf("%c", &cod);
				if (cod == 's')
					i = 1;
				else
					i = 0;
				CLIENTE_copy(auxiliar, novo, i);
				printf("\n");
				printf("CLIENTE ALTERADO COM SUCESSO");
				system("PAUSE");
				system("cls");
			}
			auxiliar = NULL;
			break;
		
		case EXCLUIR:
			fclose(dados->arquivo_clientes);
			system("cls");
			printf("Digite o codigo do cliente a ser removido\n");
			fflush("stdin");
			scanf("%d", &i);
		
			int retorno = RAM_exclui(ram,i);
			
			if (retorno == 1)
				printf("\n Cliente excluido com sucesso !!");
			else
				printf("\nImpossivel excluir");
			printf("\n");
			system("PAUSE");
			fclose(dados->arquivo_clientes);
			system("cls");
		break;


		case GRAVAR:
			fclose(dados->arquivo_clientes);
			dados->arquivo_clientes = NULL;
			dados->arquivo_clientes = fopen(dados->nome_arquivo_clientes, "w+");

			if (dados->arquivo_clientes != NULL) {

				fwrite(ram->vetor, sizeof(Cliente), ram->tamanho, dados->arquivo_clientes);
				fclose(dados->arquivo_clientes);
				printf("\nDados salvos com sucesso\n");
				system("PAUSE");
				return 0;

			}
			else {
				printf("Arquivo de clientes nao pode ser aberto\n");

			}
			fclose(dados->arquivo_clientes);
			break;

		case SAIR_SEM_SALVAR:
			ram = ram_copia;
			fclose(dados->arquivo_clientes);
			dados->arquivo_clientes = NULL;
			dados->arquivo_clientes = fopen(dados->nome_arquivo_clientes, "w+");

			if (dados->arquivo_clientes != NULL) {

				fwrite(ram->vetor, sizeof(Cliente), ram->tamanho, dados->arquivo_clientes);
				fclose(dados->arquivo_clientes);
				printf("\nDados nao salvos\n");
				system("PAUSE");
				return 0;

			}
			else {
				printf("Arquivo de clientes nao pode ser aberto\n");

			}
			fclose(dados->arquivo_clientes);
			break;


		
		}

}

}