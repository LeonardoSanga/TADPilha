#include "TADPilha.hpp"

#include <iostream>

void cria(Pilha& P) {

	Pilha Pvazia;
	Pvazia.topo = -1;
	P = Pvazia;

}

void empilha(Pilha& P, int elemento, bool& deuCerto) {

	if (cheia(P)) {

		deuCerto = false;

	}
	else {

		P.topo++;
		P.elementos[P.topo] = elemento;
		deuCerto = true;

	}

}
void desempilha(Pilha& P, int& elemento, bool& deuCerto) {

	if (vazia(P)) {

		deuCerto = false;

	}
	else {

		elemento = P.elementos[P.topo];

		int quantidadeDeElementos = P.topo + 1;
		int vetorElementosAux[TAMANHO];

		for (int i = 0; i < quantidadeDeElementos - 1; i++) {

			vetorElementosAux[i] = P.elementos[i];

		}

		cria(P);

		for (int j = 0; j < quantidadeDeElementos - 1; j++) {

			P.elementos[j] = vetorElementosAux[j];
			P.topo++;

		}

		deuCerto = true;

	}

}

bool vazia(Pilha& P) {

	if (P.topo == -1) {

		return true;

	}

	return false;

}
bool cheia(Pilha& P) {

	if (P.topo == TAMANHO - 1) {

		return true;

	}

	return false;

}