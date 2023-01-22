#pragma once

const int TAMANHO = 5;

struct Pilha {

	int elementos[TAMANHO];
	int topo;

};

void cria(Pilha& P);

void empilha(Pilha& P, int elemento, bool& deuCerto);

void desempilha(Pilha& P, int& elemento, bool& deuCerto);

bool vazia(Pilha& P);

bool cheia(Pilha & P);