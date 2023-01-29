typedef struct Chocolate{
    int id;
    char sabor[20];
}chocolate;

struct Pilha {
    chocolate elementos[10];
    int topo;   // posicao onde esta o topo da pilha
};
typedef struct Pilha pilha;

typedef struct Produto{
    int id;
    char nome[20];
    float valor;

}produto;


typedef struct Pedido{
    produto produtos[5];
    float valor_acumulado;
    chocolate chocolate;

}pedido;

typedef struct Pessoa{
    char nome[20];
    pedido p;
}pessoa;

struct Fila {
    pessoa clientes[10]; // conjunto de elementos
    int n_elem;		 // numero de elementos
    int primeiro;	 // posicao do primeiro elem
    int final;		 // primeira posicao livre
};

typedef struct Fila fila;


pilha *criarP();
void destruiP(pilha *p);
bool Pvazia(pilha p);
bool Pcheia(pilha p);
bool empilharP(pilha *p, chocolate a);
bool desempilharP(pilha *p, chocolate *a);

fila *criarF();
void destruirF(fila *F);
bool Fvazia(fila *F);
bool Fcheia(fila *F);
bool insereF(fila *F, pessoa a);
bool retiraF(fila *F, pessoa *a);

