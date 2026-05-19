#include <iostream>
using namespace std;

#define MAX 30

struct Pilha {
	int qtde;
	int elementos[MAX];
};

Pilha* init()
{
	Pilha *p = new Pilha();
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p)
{
	return (p->qtde == 0);
}

int count(Pilha *p)
{
	return (p->qtde);
}

int push(Pilha *p, int v)
{
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar)
	{
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

int pop(Pilha *p)
{
	int podeDesempilhar = (p->qtde > 0);
	int v = -1;
	if (podeDesempilhar)
	{
		v = p->elementos[p->qtde - 1];
		p->qtde--;
	}
	return v;
}

void print(Pilha *p)
{
	cout << "--------------------------" << endl;
	cout << "-- Qtde: " << count(p) << " ------------" << endl;
	cout << "--------------------------" << endl;
	for(int i=p->qtde-1; i>=0; --i)
	{
		cout << p->elementos[i] << endl;
	}
	cout << "--------------------------" << endl;
}

void freePilha(Pilha *p)
{
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
		continue;
	}
	else {
		if (numero <= maior) {
			cout << "Numero invalido (menor ou igual a): " << maior << ". insira outro"<< endl;
		}
		else {
			maior = numero;
			if (numero % 2 == 0)
				(push(pPar, numero));

			else (push(pImpar, numero));

			cout << "Numero '" << numero << "' adicionado com sucesso!" << endl;
			i++;
		}


	}
}
while (i<MAX);
}

void desempilhar(Pilha *pPar, Pilha *pImpar) {

	while (!isEmpty(pPar) || !isEmpty(pImpar)) {
		double topoPar   = isEmpty(pPar)   ? -__INT_MAX__ : pPar->elementos[pPar->qtde - 1];
		double topoImpar = isEmpty(pImpar) ? -__INT_MAX__ : pImpar->elementos[pImpar->qtde - 1];

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

	cout << "PILHA EM ORDEM DECRESCENTE:" << endl;
    desempilhar(pilhaPar, pilhaImpar);

	freePilha(pilhaPar);
	freePilha(pilhaImpar);
}
