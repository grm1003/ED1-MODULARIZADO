O sistema feito é um sistema de restaurante no qual primeiramente nos reunimos para discutir como seria feito os pilares do trabalho, como: estruturas do pedidos , pessoas, funções para adicionar pedidos e mostrar cardapio etc...Após estas reuniões começamos a implementa-las e colocando algumas definições como existe uma fila invariavelmente grande , no caso colocamos 10 pessoas mas pode ser alterado para mais, com um cardápio de 10 itens , cada pessoa possui um pedido de 5 itens que são colocados no pedido da pessoa , por meio de um vetor de inteiros de id de pedidos que pegam os pedidos do cardápio e os coloca no pedido da pessoa , a pilha de chocolate é o mesmo esquema do pedido no sentido de um array de chocolates já feito e inserido na pilha de chocolate, quando a pessoa vai no caixa e paga , é escrito em um arquivo a pessoa e os pedidos delas junto ao total e o chocolate que acabou de ser desempilhado, de forma mais dinâmica existe um loop que retira todas as pessoas da fila e para cada uma colocando um chocolate da pilha, logo depois escrevendo elas no arquivo para salvar. O arquivo é um arquivo .dat em binário o qual se reinicia a cada compilação do programa, além disso ele pode ser lido mostrando as comandas das pessoas já pagas com os produtos, total, nome e chocolate. Em alguns casos como pilha de chocolate vazia , no começo da criação do pedido o chocolate recebe "Nenhum" tratar esses casos. 

Funções adicionais e parâmetros (fora do TAD):

void adicionapedido(cardapio a, pessoa *pessoa, int *idproduto);

void mostracardapio(cardapio a)

void mostrapedido(pessoa a)

void escreverPessoa(FILE *arq, pessoa a)

void lerArquivo(FILE *arq)

pessoa *criapessoa(char nome[20],int *pedido)

pilha *criarPChoco()

void pagamento(fila *f,pilha *p,FILE *arq)
