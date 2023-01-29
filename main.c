#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "td.c"

//cria estrutura cardápio
typedef struct Cardapio{
   produto produtos[10];
}cardapio;

//criar cardapio para uso
cardapio *criacardapio(){

  cardapio *a = malloc(sizeof(cardapio));

//coloca o id de produto no cardápio
  for(int i=0; i<10; i++){
    a->produtos[i].id = i;

    }

//adiciona os nomes dos produtos
  strcpy(a->produtos[0].nome, "Suco");
  a->produtos[0].valor = 5.00;

  strcpy(a->produtos[1].nome, "Cafe");
  a->produtos[1].valor = 2.00;

  strcpy(a->produtos[2].nome, "Vitamina");
  a->produtos[2].valor = 8.00;

  strcpy(a->produtos[3].nome, "Refrigerante");
  a->produtos[3].valor = 4.00;

  strcpy(a->produtos[4].nome, "Agua");
  a->produtos[4].valor = 2.00;

  strcpy(a->produtos[5].nome, "Batata Frita");
  a->produtos[5].valor= 16.00;

  strcpy(a->produtos[6].nome, "Jantinha");
  a->produtos[6].valor= 18.00;

  strcpy(a->produtos[7].nome, "Hamburguer");
  a->produtos[7].valor= 23;

 strcpy(a->produtos[8].nome, "Parmegiana");
  a->produtos[8].valor= 32.00;

 strcpy(a->produtos[9].nome, "File Mignon");
  a->produtos[9].valor= 45.00;


  return a;

}

//criar array de chocolate
chocolate *criachocolate(){

   chocolate *a = malloc(sizeof(chocolate)*10);

//coloca o id do chocolate
  for(int i=0; i<10; i++){
     a[i].id= i;

    }

//adiciona os nomes dos chocolates
  strcpy(a[0].sabor, "Bubble");
  strcpy(a[1].sabor, "Suflair");
  strcpy(a[2].sabor, "Serenata");
  strcpy(a[3].sabor, "Ouro Branco");
  strcpy(a[4].sabor, "Sonho de Valsa");
  strcpy(a[5].sabor, "KitKat");
  strcpy(a[6].sabor, "Bis");
  strcpy(a[7].sabor, "Snickers");
  strcpy(a[8].sabor, "Diamante Negro");
  strcpy(a[9].sabor, "Laka Oreo");

  return a;
}





void adicionapedido(cardapio a, pessoa *pessoa, int *idproduto){
    //adiciona todos items pedidos para pessoa ja calculando seu valor total
    pessoa->p.valor_acumulado = 0;
     for(int i=0; i<5; i++){
        for(int j=0; j<10; j++){
            if(a.produtos[j].id == idproduto[i]){
                pessoa->p.produtos[i].id = a.produtos[j].id;
                strcpy(pessoa->p.produtos[i].nome, a.produtos[j].nome);
                pessoa->p.produtos[i].valor = a.produtos[j].valor;
                float conta = (a.produtos[j].valor);
                //tratamento de erro, padrão nenhum de chocolate para pedido
                strcpy(pessoa->p.chocolate.sabor,"Nenhum");
                pessoa->p.valor_acumulado += conta;
            }
        }
    }
}
void mostracardapio(cardapio a){//printa todos itens cadastrados no cardapio
    for(int i=0; i<10; i++){
    printf("%d.%s - R$%.2f \n", a.produtos[i].id, a.produtos[i].nome, a.produtos[i].valor);
    }


}

void mostrapedido(pessoa a){//mostra todos pedidos feitos pelo cliente alem de mostrar o valor total a ser pago

 
printf("COMANDA - %s\n",a.nome);
 
 printf("---------------------------------\n");
    for(int i=0; i<5; i++){
        printf("%s............%.2f\n",a.p.produtos[i].nome, a.p.produtos[i].valor);
    }

    printf("valor total: %.2f\n", a.p.valor_acumulado);
    printf("chocolate: %s\n", a.p.chocolate.sabor);
    printf("---------------------------------\n");
    printf("\n");
}

//--------------------------------------------PAGAMENTO E OUTRAS FUN??ES------------------------------------------------------------------------------

//Escrever no arquivo dados de uma pessoa
void escreverPessoa(FILE *arq, pessoa a){
    fwrite(&a, sizeof(a), 1, arq);
}

//Ler arquivo e printar os pedidos salvos
void lerArquivo(FILE *arq){
    pessoa a;
    rewind(arq);
    while (fread(&a, sizeof(pessoa), 1, arq) > 0){
            mostrapedido(a);
    }
}

//Criar pessoa mais facilmente ja colocando o nome e o pedido
pessoa *criapessoa(char nome[20],int *pedido){
    pessoa *a = malloc(sizeof(pessoa));
    //copiando o nome para a pessoa
    strcpy(a->nome,nome);
    cardapio *p = criacardapio();
    //adiciona o pedido
    adicionapedido(*p,a,pedido);
    return a;

}

//Cria a pilha inserindo os chocolates automaticamente
pilha *criarPChoco(){
    chocolate *choco = criachocolate();
    pilha *pilha = criarP();
    //copiando do array de cholocates para pilha
    for(int i = 0; i<10;i++){
        empilharP(pilha,choco[i]);
    }
    return pilha;
}


//Pagamento com gerente
void pagamento(fila *f,pilha *p,FILE *arq){
    pessoa a;
    if(Fvazia(f)){
        printf("Sem clientes hoje");
    }
    //enquanto fila nao esta vazia ele retira o cliente adiciona o chocolate e mostra o pedido
    while(!Fvazia(f)){
        //pessoa retirada da fila ? colocada na pessoa a
       retiraF(f,&a);
       desempilharP(p,&(a.p.chocolate));
       escreverPessoa(arq,a);
    }
    //dando free e destruindo a fila e pilha
    destruirF(f);
    destruiP(p);

}


int main(){

   
    FILE *a;
    a = fopen("pedidos.dat", "wb+");
    if (a == NULL){
            printf("Erro no arquivo\n");
    }


    pilha *pilha = criarPChoco();

    //criando os pedidos
    int z[5] = {0,2,2,8,9};
    int f[5] ={0,4,3,7,5};
    int g[5] ={2,9,8,7,6};
    int d[5] = {0,2,3,9,6};
    int h[5] = {7,8,2,6,4};
    int i[5] = {9,1,2,3,4};
    int k[5] = {5,2,7,8,1};

    //criando as pessoas
    pessoa *gabriel = criapessoa("Gabriel",g);
    pessoa *carlos = criapessoa("Carlos",z);
    pessoa *ana = criapessoa("Ana",f);
    pessoa *guilherme = criapessoa("Guilherme",h);
    pessoa *matheus= criapessoa("Matheus",d);
    pessoa *henrique = criapessoa("Henrique",d);
    pessoa *amanda = criapessoa("Amanda",z);
    pessoa *murilo = criapessoa("Murilo",k);
    pessoa *cleber= criapessoa("Cleber",h);
    pessoa *renata = criapessoa("Renata",i);
    pessoa *clara = criapessoa("Clara",i);


    //inserindo as pessoas na fila
    fila *fila = criarF();
    insereF(fila,*carlos);
    insereF(fila,*ana);
    insereF(fila,*gabriel);
    insereF(fila,*guilherme);
    insereF(fila,*matheus);
    insereF(fila,*henrique);
    insereF(fila,*amanda);
    insereF(fila,*murilo);
    insereF(fila,*cleber);
    insereF(fila,*renata);
    //erro, não vai inserir
    insereF(fila,*clara);

    //pessoas pagando e saindo do restaurante
    pagamento(fila,pilha,a);
    lerArquivo(a);




    return 0;
}

