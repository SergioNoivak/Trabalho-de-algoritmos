# Trabalho-de-algoritmos
Breve descrição
O sistema é responsável para guardar dados dos clientes em disco e, durante a execução, armazenar esses mesmos dados na memoria volátil da máquina. Para tanto foi utilizado um vetor dinâmico e também o conhecimento de arquivos em c para tal tarefa.
## 1.	Arquivo `Dados de arquivo`.
 De modo geral, as funções desse arquivo retornam:

<table>
<tr>
<td><b>Retorno</b></td>
<td><b>Status</b></td>
</tr>
<tr>
<td>1</td>
<td>caso arquivo correto sucesso</td>
</tr>
<tr>
<td>0</td>
<td>caso o arquivo não pode ser aberto
</td>
</tr>	
</table>

### 1.1 Detalhes:
O Procedimento init `void init(Dados_de_arquivos* n_a)`, recebe como parâmetro um ponteiro do tipo `Dados_de_arquivo`, esse ponteiro recebe o nome do arquivo que será aberto `("DATA_clientes.dat”)`.
Procedimento close `void close(Dados_de_arquivos* n_a)`, recebe como parâmetro um ponteiro do tipo `Dados_de_arquivo`, fecha o arquivo por meio da função `fclose` e libera o espaço de memória alocado para o ponteiro por meio da função `free`.
Função Valida_arq_cliente `int valida_arq_cliente(Dados_de_arquivos* dados_de_arquivo)`, verifica se o arquivo é valido por meio da condicional, retorna 1 caso arquivo correto ou retorna 0 caso o arquivo não possa ser aberto.

A função `DADOS_DE_ARQUIVO_grava_cliente `
`int DADOS_DE_ARQUIVO_grava_cliente(Cliente* cliente_a_ser_gravado, Dados_de_arquivos* dados_de_arquivo)`, recebe como parâmetro um ponteiro para o cliente e outro com os dados a serem gravados e faz a gravação dos dados no arquivo.

O procedimento DADOS_DE_ARQUIVO_exibe_todos_os_clientes 
`void DADOS_DE_ARQUIVO_exibe_todos_os_clientes(Dados_de_arquivos* dados_de_arquivo)`, recebe um ponteiro do tipo `Dados_de_arquivos`, e exibe na tela os dados que o cliente inseriu no sistema.

A funcao `RAM* DADOS_DE_ARQUIVO_carrega(Dados_de_arquivos* dados_de_arquivo)` recebe um arquivo do tipo Dados_de_arquivo grava os dados do arquivo em um ponteiro do tipo` RAM` e retorna esse ponteiro.

## 2.	Arquivo `CLIENTE.H`

O procedimento void `CLIENTE_exibe_cliente(Cliente* c)`, recebe um ponteiro do tipo cliente e exibe na tela os dados dos clientes.

A função `Cliente* CLIENTE_entrada_de_cliente()` recebe do usuário os dados do cliente que ele deseja cadastrar e retorna um ponteiro do tipo `Cliente*`.

A funcao `Cliente* CLIENTE_copia(Cliente* cliente)`, recebe um ponteiro do tipo `Cliente*`, armazena os dados dele em um novo ponteiro do tipo cliente, chamado `Cliente *novo` e retorna esse novo ponteiro com os dados copiados.

A funcao `int valido(Cliente* cliente)` recebe um ponteiro do tipo `Cliente*` e verifica se ele é diferente de NULL, ou seja, se é valido, se sim retorna TRUE que vale 1, senão retorna FALSE que vale 0.

O procedimento void `CLIENTE_copy(Cliente* Destination, Cliente* Source, int change_code)` recebe dois ponteiros do tipo `Cliente*`, um que contem os dados, chamado Source e outro que irá receber os dados, chamado Destination, o change code serve para validar se o codigo sera copiado, se for igual a 1 ele é copiado.

## 3.	Arquivo `Origem.c`

A funcao `int menu_cliente_exibicao()` exibe na tela as opções que o usuario tem para interagir com o programa, recebe um número do usuário de 1 a 7 e retorna esse valor para a main.
A funcao `int main()` é responsavel pela chamada da funcao que inicia o ponteiro `(Dados_de_arquivos* dados)` dados do tipo Dados_de_arquivo, e ele receberá as informações que estão armazenadas no arquivo. Nela temos um while que contém um switch case, que contém as opções que o cliente pode escolher e de acordo com a escolha executa uma determinada função, pode inserir um usuário(1), alterar(2), consultar(3), excluir(4), listar(5), gravar(6), sair sem salvar(7), e dentro de cada case ocorre a execução de cada uma dessas tarefas. 

## 4.	Arquivo `validação.h`
A enumeração enum status faz com que sejam apenas dois os possíveis para a validação da string, toda vez que a função dada for chamada.


<table>
<tr>
<td><b>Nome</b></td>
<td><b>Valor</b></td>
</tr>
<tr>
<td>1</td>
<td>status_valido</td>
</tr>
<tr>
<td>0</td>
<td>status_invalido 	
</td>
</tr>	
</table>
