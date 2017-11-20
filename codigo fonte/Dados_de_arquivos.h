#pragma once
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include"Cliente.h"
#include<string.h>
#include"RAM.h"
typedef struct Dados_de_arquivos {
	char nome_arquivo_clientes[100];
	FILE* arquivo_clientes;
}Dados_de_arquivos;

void init(Dados_de_arquivos* n_a) {
	strcpy(n_a->nome_arquivo_clientes, "DATA_clientes.dat");
}

void close(Dados_de_arquivos* n_a) {

	fclose(n_a->arquivo_clientes);
	free(n_a->nome_arquivo_clientes);
	free(n_a);

}
/**
retorna 1 caso arquivo correto sucesso
retorna 0 caso o arquivo nao pode ser aberto
*/
int valida_arq_cliente(Dados_de_arquivos* dados_de_arquivo) {

	if (dados_de_arquivo->arquivo_clientes == NULL)
		return 0;
	else return 1;
}

/**
retorna 1 caso cliente gravado com sucesso
retorna 0 caso o arquivo nao pode ser aberto
*/
int DADOS_DE_ARQUIVO_grava_cliente(Cliente* cliente_a_ser_gravado, Dados_de_arquivos* dados_de_arquivo) {
	

	if (valida_arq_cliente(dados_de_arquivo) == TRUE) {
		fseek(dados_de_arquivo->arquivo_clientes, 0, SEEK_END);
		fwrite(cliente_a_ser_gravado, sizeof(Cliente), 1, dados_de_arquivo->arquivo_clientes);
		return 1;
	}
	else {
		printf("Arquivo %s nao pode ser aberto\n", dados_de_arquivo->nome_arquivo_clientes);
		return 0;

	}

}
/**

	retorna primeiro cliente do arquivo 
	caso de erro: retorna NULL
*/
Cliente* DADOS_DE_ARQUIVO_le_primeiro_cliente(Dados_de_arquivos* dados_de_arquivo) {
	if (valida_arq_cliente(dados_de_arquivo) == TRUE) {
		rewind(dados_de_arquivo->arquivo_clientes);
		Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
		int x = fread(novo, sizeof(Cliente), 1, dados_de_arquivo->arquivo_clientes);
		return novo;
	}
	return NULL;
	}

/**
retorna último cliente do arquivo
caso de erro: retorna NULL
*/
Cliente* DADOS_DE_ARQUIVO_le_ultimo_cliente(Dados_de_arquivos* dados_de_arquivo){
	if (valida_arq_cliente(dados_de_arquivo) == TRUE) {
		fseek(dados_de_arquivo->arquivo_clientes, -sizeof(Cliente), SEEK_END);
		Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
		int x = fread(novo, sizeof(Cliente), 1, dados_de_arquivo->arquivo_clientes);
		return novo;
	}
	return NULL;
}

void DADOS_DE_ARQUIVO_exibe_todos_os_clientes(Dados_de_arquivos* dados_de_arquivo) {	
	if (dados_de_arquivo->arquivo_clientes != NULL) {
		/* move o ponteiro pro comeco do arquivo para exibir*/
		rewind(dados_de_arquivo->arquivo_clientes);
		while (!feof(dados_de_arquivo->arquivo_clientes)) {
			Cliente* corrente = malloc(sizeof(Cliente));
			int x = fread(corrente, sizeof(Cliente), 1, dados_de_arquivo->arquivo_clientes);
			if(corrente!=NULL && x==1)
			CLIENTE_exibe_cliente(corrente);
		}
		rewind(dados_de_arquivo->arquivo_clientes);
	}

}

RAM* DADOS_DE_ARQUIVO_carrega(Dados_de_arquivos* dados_de_arquivo) {
	if (dados_de_arquivo->arquivo_clientes != NULL) {
		RAM* ram = malloc(sizeof(RAM));
		RAM_init(ram, 0);
		ram->tamanho = 0;
		/* move o ponteiro pro comeco do arquivo para exibir*/
		rewind(dados_de_arquivo->arquivo_clientes);
		while (!feof(dados_de_arquivo->arquivo_clientes)) {
			Cliente* corrente = malloc(sizeof(Cliente));
			
			int x = fread(corrente, sizeof(Cliente), 1, dados_de_arquivo->arquivo_clientes);
			
			if (x == 1) {
	
				RAM_adicionar_Cliente(ram, corrente);
			
			
			
			}
		}
		rewind(dados_de_arquivo->arquivo_clientes);
		fclose(dados_de_arquivo->arquivo_clientes);
		dados_de_arquivo->arquivo_clientes = fopen(dados_de_arquivo->nome_arquivo_clientes, "w+b");
		fclose(dados_de_arquivo->arquivo_clientes);
		dados_de_arquivo->arquivo_clientes = fopen(dados_de_arquivo->nome_arquivo_clientes, "a+b");
		return ram;
	}
	return NULL;
}
	