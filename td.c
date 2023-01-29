
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "td.h"


fila *criarF(){
	fila *F;

	F = (fila *) malloc(sizeof(fila));
	if (F != NULL) { // alocou corretamente
		F->n_elem = 0;
		F->primeiro = 0;
		F->final = 0;
	}

	return F;
}

void destruirF(fila *F){
    if (F != NULL) free(F);
}

bool Fvazia(fila *F){
    if (F->n_elem == 0) return true;
    else return false;
}

bool Fcheia(fila *F){
    if (F->n_elem == 10) return true;
    else return false;
}

bool insereF(fila *F, pessoa a){
	bool deuCerto;

	if (Fcheia(F) == true) {
		deuCerto = false;
		return deuCerto;
	}

	// senao:
	deuCerto = true;
	F->clientes[F->final] = a;

	F->n_elem = F->n_elem + 1;

	if (F->final == (10-1)) F->final = 0;
	else F->final = F->final + 1;

	return deuCerto;
}

bool retiraF(fila *F, pessoa *a){
	bool deuCerto;

	if (Fvazia(F) == true) {
		deuCerto = false;
		return deuCerto;
	}

	// senao:
	deuCerto = true;
	*a = F->clientes[F->primeiro];
	F->n_elem = F->n_elem - 1;

	if (F->primeiro == (10 - 1)) F->primeiro = 0;
	else F->primeiro = F->primeiro + 1;

	return deuCerto;
}




pilha *criarP(){
    pilha *p;

    p = (pilha *) malloc(sizeof(pilha));
	if (p != NULL) { // alocou corretamente
		 p->topo = -1;
	}

    return p;

}

void destruiP(pilha *p){
    if (p != NULL) free(p);
}

bool Pvazia(pilha p){
    if (p.topo == -1) return true;
    else return false;

//    return ((p.topo == -1) ? true : false);
//    return (p.topo == -1);
}

bool Pcheia(pilha p){
    if (p.topo == 9) return true;
    else return false;

    // 10 eh o total de elementos (no caso, 10)
    // o Topo vai de -1 (vazia) a 9 (cheia)
    // entao, eh cheia se Topo == 9
}

bool empilharP(pilha *p, chocolate a){
    bool deuCerto;

    if (Pcheia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        p->topo = p->topo + 1;
        p->elementos[ p->topo ] = a;
        deuCerto = true;
        return deuCerto;
    }
}

bool desempilharP(pilha *p, chocolate *a){
    bool deuCerto;

    if (Pvazia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        *a = p->elementos[ p->topo ];
        p->topo = p->topo - 1;
        deuCerto = true;
        return deuCerto;
    }
}
