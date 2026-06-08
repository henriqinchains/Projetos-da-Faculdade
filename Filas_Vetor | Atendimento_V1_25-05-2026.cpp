#include <iostream>
#include <windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define MAX 6

struct Fila {
    int ini;
    int fim;
    int nos[MAX];
};

Fila* init() {
    Fila *f = new Fila;
    f->ini = 0;
    f->fim = 0;
    return f;
}

int isEmpty(Fila *f) {
    return (f->fim == f->ini);
}

int incrementa(int i) {
    return (i==MAX-1 ? 0 : i+1);
}

int count (Fila *f) {
    int k=0;
    int i = f->ini;
    while(i!=f->fim) {
        k++;
        i = incrementa(i);
    }
    return k;
}

void print (Fila *f) {
    int i = f->ini;
    while (i != f->fim) {
        cout << f->nos[i] << endl;
        i = incrementa(i);
    }
    cout << "-------------------" << endl;
}


int enqueue(Fila *f) {
    static int senha = 0;
    int podeEnfileirar = (incrementa(f->fim) != f->ini);
    if (podeEnfileirar) {
        f->nos[f->fim] = ++senha;
        f->fim = incrementa (f->fim);
    }
    return podeEnfileirar;
}

void consumirSenha (Fila *f, int valor) {
    int podeEnfileirar = (incrementa(f->fim) != f->ini);
    if (podeEnfileirar) {
        f->nos[f->fim] = valor;
        cout << "" << endl;
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Senha consumida: " << f->nos[f->fim] << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "" << endl;
        f->fim = incrementa (f->fim);
    }
}

int dequeue(Fila *f, Fila *consumidas) {
    int ret;
    if (isEmpty(f)) {
        ret = -1;
    }
    else {
        ret = f->nos[f->ini];
        f->ini = incrementa (f->ini);
        consumirSenha(consumidas, ret);
    }
    return ret;
}

void freeFila (Fila *f) {
    delete f;
}

int main(int argc, char** argv) {
    Fila *senhasGeradas = init();
    Fila *senhasAtendidas = init();

    int opcao;

    do  {
        cout << " _______________________________ " << endl;
        cout << "|                                \\\\" << endl;

        cout << "|";
        SetConsoleTextAttribute(hConsole, 12);
        cout << " SENHAS A SEREM ATENDIDAS: " << count(senhasGeradas);
        SetConsoleTextAttribute(hConsole, 7);
        cout << "     ||" << endl;
        cout << "|                                 ||" << endl;
        cout << "| 0. SAIR                         ||" << endl;
        cout << "| 1. GERAR SENHA                  ||" << endl;
        cout << "| 2. REALIZAR ATENDIMENTO         ||" << endl;
        cout << "|_______________________________ //  " << endl;
        cout << "" << endl;

        cout << "O que deseja fazer?: ";
        cin >> opcao;

        if(cin.fail())
        {
            cout << "|" << endl;
            cout << "|";
            SetConsoleTextAttribute(hConsole, 12);

            cout << " Opção inválida. Selecione alguma entre '0' e '2', por gentileza." << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "|" << endl;


            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch(opcao)
        {
            case 1:
                enqueue(senhasGeradas);
                break;
            case 2:
                dequeue(senhasGeradas, senhasAtendidas);;
                break;
        }

        if(opcao < 0 || opcao > 2)
        {
            cout << "" << endl;
            cout << "---------------------------------------------------------------------" << endl;
            cout << "|";
            SetConsoleTextAttribute(hConsole, 12);
            cout << " Opção inválida. Selecione alguma entre '0' e '2', por gentileza." << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "---------------------------------------------------------------------" << endl;
            cout << "" << endl;
        }

        if (opcao == 0 || !isEmpty(senhasGeradas)) {
            cout << "" << endl;
            cout << "Erro ao finalizar. Ainda ha senhas na fila. " << endl;
            cout << "" << endl;
        }
    }
    while (opcao != 0 || !isEmpty(senhasGeradas));
}
