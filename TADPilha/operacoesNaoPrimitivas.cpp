#include "operacoesNaoPrimitivas.hpp"

#include <iostream>

int retornaElementoDoTopo(Pilha& P, bool& deuCerto) {

	int elementoDoTopo;

	if (vazia(P)) {

		deuCerto = false;
		return 0;

	}
	else {

		desempilha(P, elementoDoTopo, deuCerto); // encontrando o elemento do topo da pilha
		empilha(P, elementoDoTopo, deuCerto); // deixando a pilha como encontrada
		deuCerto = true;
		return elementoDoTopo;

	}

}
bool verificaPresencaDeElemento(Pilha& P, int elementoEmBusca) {

	int elementoDaPilha;
	bool estaPresente = false;
	bool deuCerto;

	Pilha Paux;
	cria(Paux);

	while (!vazia(P)) {

		desempilha(P, elementoDaPilha, deuCerto);
		empilha(Paux, elementoDaPilha, deuCerto);

		if (elementoDaPilha == elementoEmBusca) {

			estaPresente = true;

		}

	}

	while (!vazia(Paux)) { // deixando a pilha como encontrada

		desempilha(Paux, elementoDaPilha, deuCerto);
		empilha(P, elementoDaPilha, deuCerto);

	}

	if (estaPresente) {

		return true;

	}

	return false;
}

void imprimeElementos(Pilha& P, bool& deuCerto) {

	if (vazia(P)) {

		deuCerto = false;

	}
	else {

		int elementoDaPilha;

		Pilha Paux;
		cria(Paux);

		while (!vazia(P)) {

			desempilha(P, elementoDaPilha, deuCerto);
			empilha(Paux, elementoDaPilha, deuCerto);
			std::cout << elementoDaPilha << " ";

		}

		while (!vazia(Paux)) { // deixando a pilha como encontrada

			desempilha(Paux, elementoDaPilha, deuCerto);
			empilha(P, elementoDaPilha, deuCerto);

		}

		deuCerto = true;

	}

}