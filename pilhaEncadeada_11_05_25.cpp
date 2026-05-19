#include <iostream>
using namespace std;

struct No {
	int dado;
	struct No *ant;
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

int count(Pilha *p) {
	int i = 0;
	No *no;
	no = p->topo;
	while (no != NULL) {
		i++;
		no = no->ant;
	}
	return i;
}


void print(Pilha *p) {
	No *no;
	no = p->topo;
	cout << "--------------------------" << endl;
	cout << "-- Qtde: " << count(p) << "            --" << endl;
	cout << "--------------------------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->ant;
	}
	cout << "--------------------------" << endl;
}

void push(Pilha *p, int v) {
	No *no = new No;
	no->dado = v;
	no->ant = p->topo;
	p->topo = no;
}

int pop(Pilha *p) {
	int v = -1;
	int podeDesempilhar = (! isEmpty(p));
	if (podeDesempilhar) {
		No *no = p->topo;
		v = no->dado;
		p->topo = no->ant;
		delete(no);
	}
	return v;
}

void freePilha(Pilha *p) {
	No *no;
	no = p->topo;
	while (no != NULL) {
		No *temp = no->ant;
		delete(no);
		no = temp;
	}
	delete(p);
}

void adicionarNumero(Pilha *pPar, Pilha *pImpar){
	int i = 0;
	int numero;
	int maior = -__INT_MAX__;
	do
	{
		cout << "Numero a ser adicionado:" << endl;
		cin >> numero;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Numero invalido. Insira novamente." << endl;
			cout << endl;
			continue;
		}
		else {
			if (numero <= maior) {
				cout << "Numero invalido (menor ou igual a): " << maior << ". insira outro"<< endl;
				cout << endl;
			}
			else {
				maior = numero;
				if (numero % 2 == 0)
					(push(pPar, numero));

				else (push(pImpar, numero));

				cout << "Numero '" << numero << "' adicionado com sucesso!" << endl;
				cout << endl;
				i++;
			}


		}
	}
	while (i<5);
}

void desempilhar(Pilha *pPar, Pilha *pImpar) {

	while (!isEmpty(pPar) || !isEmpty(pImpar)) {
		double topoPar   = isEmpty(pPar)   ? -__INT_MAX__ : pPar->topo->dado;
		double topoImpar = isEmpty(pImpar) ? -__INT_MAX__ : pImpar->topo->dado;

		if (topoPar >= topoImpar)
			cout << pop(pPar) << endl;
		else
			cout << pop(pImpar) << endl;
	}
}

int main(int argc, char** argv)
{
	Pilha *pilhaPar;
	Pilha *pilhaImpar;
	pilhaPar = init();
	pilhaImpar = init();

	adicionarNumero(pilhaPar, pilhaImpar);

	cout << "LISTA EM ORDEM DECRESCENTE:" << endl;
	desempilhar(pilhaPar, pilhaImpar);

	freePilha(pilhaPar);
	freePilha(pilhaImpar);
}
