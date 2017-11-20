#pragma once
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<string.h>
#include"validacao.h"
enum {
	TAMANHO_NOME = 200,
	TAMANHO_DATA = 20,
	TAMANHO_RG = 20,
	TAMANHO_CARRO = 200
};



typedef struct cliente{
	int cod;
	char nome[200];
    char data_nascimento[20];
    char cpf[20];
    char carro[200];
    char sexo;
}Cliente;

void CLIENTE_exibe_cliente(Cliente* c) {
	if (c != NULL) {
		printf("\nCOD: %d \n", c->cod);
		printf("\nNOME: %s \n", c->nome);
		printf("DATA NASCIMENTO: %s\n", c->data_nascimento);
		printf("CPF: %s \n", c->cpf);
		printf("CARRO: %s\n", c->carro);
		printf("Sexo: %c\n", c->sexo);
		return;
	}
	printf("\n O cliente eh NULL\n");
}

/**
	entrada de cliente via TECLADO
*/
Cliente* CLIENTE_entrada_de_cliente() {
	char lixo;
	Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
	novo->cod = -1;
	int controle_validacao = 0;
	printf(" Entre com o NOME do cliente:(string)\n");
	while (controle_validacao == 0) {
		fflush(stdin);
		int x = gets(novo->nome);
		controle_validacao= VALIDACAO_entrada_caractere(novo->nome,x);
		if(controle_validacao==0)
			printf("\n entrada invalida: A ENTRADA DEVE CONTER APENAS CARACTERES\n");
	}
	controle_validacao = 0;
	printf(" Entre com o CARRO do cliente:(string)\n");
	while (controle_validacao == 0) {
		fflush(stdin);
		int x = gets(novo->carro);
		controle_validacao = VALIDACAO_entrada_caractere(novo->carro, x);
		if (controle_validacao == 0)
			printf("\n entrada invalida: A ENTRADA DEVE CONTER APENAS CARACTERES\n");
	}

	printf("\n Entre com A DATA DE NASCIMENTO do cliente:\n");
	fflush(stdin);
	gets(novo->data_nascimento);
	printf("\n Entre com o CPF do cliente:(apenas numeros, tamanho 17)\n");
	controle_validacao = 0;
	while (controle_validacao == 0) {
		fflush(stdin);
		int x = gets(novo->cpf);
		controle_validacao = VALIDACAO_entrada_CPF(novo->cpf);
		if (controle_validacao == 0)
			printf("\n entrada invalida: A ENTRADA DEVE CONTER APENAS NUMEROS E SER UM CPF VALIDO\n");
	}
	printf("\n Entre com o SEXO do cliente:(m/f)\n");
	scanf("%c", &(novo->sexo));
	return novo;
}


Cliente* CLIENTE_copia(Cliente* cliente) {

	Cliente * novo = malloc(sizeof(Cliente));
	novo->cod = cliente->cod;
	novo->sexo = cliente->sexo;
	strcpy(novo->carro, cliente->carro);
	strcpy(novo->cpf, cliente->cpf);
	strcpy(novo->data_nascimento, cliente->data_nascimento);
	strcpy(novo->nome, cliente->nome);
	return novo;
}


int valido(Cliente* cliente) {

	if (cliente != NULL)
		return TRUE;
	return FALSE;
}

void CLIENTE_copy(Cliente* Destination, Cliente* Source, int change_code) {

	if (Destination == NULL || Source == NULL) {
		printf("nao foi possivel copiar cliente %d para o cliente %d pois nao sao validos\n");
		return;
	}
	strcpy(Destination->carro, Source->carro);
	strcpy(Destination->data_nascimento, Source->data_nascimento);
	strcpy(Destination->nome, Source->nome);
	strcpy(Destination->cpf, Source->cpf);
	if (change_code == 1)
		Destination->cod = Source->cod;
	Destination->sexo = Source->sexo;

}

