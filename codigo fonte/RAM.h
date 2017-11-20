#pragma once
#include<stdio.h>
#include"Cliente.h"
#include<stdlib.h>
#include<string.h>
#include"Dados_de_arquivos.h"
#include"Cliente.h"
typedef struct RAM {
	Cliente* vetor;
	int tamanho;
}RAM;

void RAM_init(RAM* ram,int num) {

	if (ram != NULL) {
		
			ram->tamanho = num;
			ram->vetor = NULL;
			return;
			
	}

	printf("Voce nao alocou a RAM");
}
/**
	retorna 1 se sucesso e 0 se falso

*/
int RAM_exclui(RAM* ram,int index) {

	if (index >= ram->tamanho || index<0 )
		return 0;
	
	Cliente* aux;
	int j=index;
	for (j = index; j < ram->tamanho; j++) {
	
			strcpy(ram->vetor[j].nome, ram->vetor[j + 1].nome);
			strcpy(ram->vetor[j].carro, ram->vetor[j + 1].carro);
			strcpy(ram->vetor[j].data_nascimento, ram->vetor[j + 1].data_nascimento);
			strcpy(ram->vetor[j].cpf, ram->vetor[j + 1].cpf);
			ram->vetor[j].sexo = ram->vetor[j + 1].sexo;
			ram->vetor[j].cod = ram->vetor[j + 1].cod-1;

}
	ram->tamanho--;
	ram->vetor = (Cliente*)realloc(ram->vetor, (ram->tamanho) * sizeof(Cliente));

	//free(&ram->vetor[ram->tamanho - 1]);
	system("PAUSE");
	
	return 1;
}

void RAM_adicionar_Cliente(RAM* ram,Cliente* cliente) {
		cliente->cod = ram->tamanho;
		ram->vetor = (Cliente*)realloc(ram->vetor, (ram->tamanho + 1) * sizeof(Cliente));
		ram->tamanho++;
		ram->vetor[ram->tamanho - 1] = *cliente;
		return;
}

void RAM_exibe(RAM* ram) {
	if (ram == NULL) {

		printf("RAM null");
		return;


	}
	if (ram->vetor == NULL)
		return;
	
	int i;
	for (i = 0; i < ram->tamanho; i++)
		CLIENTE_exibe_cliente(&ram->vetor[i]);

}
	
Cliente* RAM_busca_por_codigo(RAM* ram, int codigo) {
	int i;
	Cliente* referencia =NULL;

	for (i = 0; i < ram->tamanho; i++) {
		if (ram->vetor[i].cod == codigo) {
			referencia = &ram->vetor[i];
			break;
		}
	}
	return referencia;
}

RAM* RAM_copia(RAM* ram) {

	RAM* nova_ram =(RAM*) malloc(sizeof(RAM));
	RAM_init(nova_ram,0);
	int i;
	Cliente* copia=NULL;

	for (i = 0; i < ram->tamanho; i++) {
		copia =CLIENTE_copia(&ram->vetor[i]);
		if(copia!=NULL)
			RAM_adicionar_Cliente(nova_ram,copia);
	}
	free(copia);
	return nova_ram;
}





