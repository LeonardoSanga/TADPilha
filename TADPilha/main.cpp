#include "TADPilha.hpp"
#include "operacoesNaoPrimitivas.hpp"

#include <string>
#include <iostream>

using namespace std;

void paraImprimirElementos(Pilha& P1, Pilha& P2, bool& deuCerto) {

	std::cout << "Elementos da Pilha 1 : " << std::endl;
	imprimeElementos(P1, deuCerto);
	cout << endl;

	std::cout << "Elementos da Pilha 2 : " << std::endl;
	imprimeElementos(P2, deuCerto);
	cout << endl;

}

void paraEmpilhar(Pilha& P1, Pilha& P2) {

	int elemento;
	string P;
	bool deuCerto;

	cout << "Qual elemento deseja empilhar ? ";
	cin >> elemento;
	cout << "Em qual pilha deseja empilha-lo ? Pilha 1 (P1) ou Pilha 2 (P2)";
	cin >> P;

	if (P == "P1") {

		empilha(P1, elemento, deuCerto);

		if (!deuCerto) {
			cout << "A Pilha 1 ja esta cheia" << endl;
		}

		cout << "Elementos da Pilha 1: ";
		imprimeElementos(P1, deuCerto);
		cout << endl;

	}
	else {

		empilha(P2, elemento, deuCerto);

		if (!deuCerto) {
			cout << "A Pilha 2 ja esta cheia" << endl;
		}

		cout << "Elementos da Pilha 2: ";
		imprimeElementos(P2, deuCerto);
		cout << endl;

	}

}

void paraDesempilhar(Pilha& P1, Pilha& P2) {
	int elemento;
	string P;
	bool deuCerto;

	cout << "Em qual pilha deseja desempilhar ? Pilha 1 (P1) ou Pilha 2 (P2) ";
	cin >> P;

	if (P == "P1") {

		desempilha(P1, elemento, deuCerto);

		if (!deuCerto) {

			cout << "A Pilha 1 ja esta vazia" << endl;

		}
		else {

			cout << "Elemento desempilhado: " << elemento << endl;
			cout << "Elementos da Pilha 1: ";
			imprimeElementos(P1, deuCerto);
			cout << endl;

		}

	}
	else {

		desempilha(P2, elemento, deuCerto);

		if (!deuCerto) {

			cout << "A Pilha 2 ja esta vazia" << endl;

		}
		else {

			cout << "Elemento desempilhado: " << elemento << endl;
			cout << "Elementos da Pilha 2: ";
			imprimeElementos(P2, deuCerto);
			cout << endl;

		}

	}

}

int main() {

	Pilha P1;
	Pilha P2;

	bool deuCerto;
	int elemento;

	string P;

	cria(P1);
	cria(P2);

	for (int i = 1; i < 5; i++) {

		empilha(P1, i, deuCerto);

	}

	for (int i = 5; i > 3; i--) {

		empilha(P2, i, deuCerto);

	}

	paraImprimirElementos(P1, P2, deuCerto);
	char operacaoARealizar;

	do {

		cout << endl;
		cout << "O que deseja realizar ? Empilhar (E), desempilhar (D) ou finalizar(F) ";
		cin >> operacaoARealizar;
		cout << endl;

		if (operacaoARealizar == 'E') {

			paraEmpilhar(P1, P2);

		}
		else if (operacaoARealizar == 'D') {

			paraDesempilhar(P1, P2);

		}

	} while (operacaoARealizar != 'F');

	cout << "(BUSCA) Qual elemento deseja buscar ? ";
	cin >> elemento;

	if (verificaPresencaDeElemento(P1, elemento)) {

		cout << "O elemento " << elemento << " esta contido na Pilha 1" << endl;

	}
	else {

		cout << "O elemento " << elemento << " nao esta contido na Pilha 1" << endl;

	}

	if (verificaPresencaDeElemento(P2, elemento)) {

		cout << "O elemento " << elemento << " esta contido na Pilha 2" << endl;

	}
	else {

		cout << "O elemento " << elemento << " nao esta contido na Pilha 2" << endl;

	}

	cout << endl;
	retornaElementoDoTopo(P1, deuCerto);

	if (deuCerto) {

		cout << "Elemento no topo da Pilha 1: " << retornaElementoDoTopo(P1, deuCerto) << endl;

	}
	else {

		std::cout << "Nao ha elementos na Pilha 1!";

	}

	retornaElementoDoTopo(P2, deuCerto);
	if (deuCerto) {

		cout << "Elemento no topo da Pilha 2: " << retornaElementoDoTopo(P2, deuCerto) << endl;

	}
	else {

		std::cout << "Nao ha elementos na Pilha 2!";

	}

	return 0;

}