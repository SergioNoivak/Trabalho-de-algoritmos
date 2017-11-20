#pragma once

enum status{
	status_valido = 1,
	status_invalido = 0
}status;

int VALIDACAO_entrada_CPF(char* string) {
	int i;
	if (strlen(string) != 11) {
		printf("\n deve possuir tamanho 11, tamanho digitado: %d\n", strlen(string));
		return status_invalido;
	}
	for (i = 0; i < strlen(string); i++) {
		if (string[i]<'0' || string[i]>'9') {
			return status_invalido;
		}
	}
	return status_valido;
}

int VALIDACAO_entrada_caractere(char* string, int size_s) {
	int i;
	for (i = 0; i < strlen(string); i++) {
		if ((string[i] < 65 || string[i]>90) && (string[i] < 97 || string[i]>122) && string[i] != '\n'&& string[i] != '\0')

			return status_invalido;
	
	
	}
	return status_valido;
}

int VALIDACAO_entrada_data(char* string, int size_s) {

	//  25-12-2005
	if (strlen(string) != 9) {
		printf("Tamanho da string menor que 10 : tamanho %d ",strlen(string));

		return status_invalido;
	}
	int numero_ifem = 0;
	int i;
	for (i = 0; i < strlen(string); i++) {
		if (string[i] != '\0' && string[i]>9 && string[i]!='-')
			return status_invalido;
		if (string[i] == '/') {
			numero_ifem++;
			printf("\n numero hifem: %d", numero_ifem);
		}
	}
	if(numero_ifem==2)
	return status_valido;
	else return status_invalido;
}



