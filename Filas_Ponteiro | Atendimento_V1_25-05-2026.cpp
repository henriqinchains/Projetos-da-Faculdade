#include <iostream>
#include <windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct No {
    int valor;
    No *prox;
};

struct Fila {
    No *ini;
    No *fim;
};

Fila* init() {
    Fila *f = new Fila;
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int isEmpty(Fila *f) {
    return (f->ini == NULL);
}

int count (Fila *f) {
    int k=0;
    No *no = f->ini;
    while(no != NULL) {
        k++;
        no = no->prox;
    }
    return k;
}

void print (Fila *f) {
    No *no = f->ini;
    while (no != NULL) {
        cout << no->valor << endl;
        no = no->prox;
    }
    cout << "-------------------" << endl;
}


void enqueue(Fila *f) {
    static int senha = 0;
    No *no = new No;
    no->valor = senha++;
    no->prox = NULL;
    if (isEmpty(f)) {
        f->ini = no;
    }
    else {
        f->fim->prox = no;
    }
    f->fim = no;
}

int dequeue(Fila *f, Fila *consumidas) {
    int ret;
    if (isEmpty(f)) {
        ret = -1;
    }
    else {
        No *no = f->ini;
        ret = no->valor;
        f->ini = no->prox;
        if (f->ini == NULL) {
            f->fim = NULL;
        }
        delete no;
    }
    return ret;
}

void consumirSenha (Fila *geradas, Fila *consumidas) {
    int ret = (dequeue(geradas, consumidas));

    if (ret != -1){
    No *no = new No;
    no->valor = ret;
    no->prox = NULL;

    if (isEmpty(consumidas)) {
        consumidas->ini = no;
        cout << "Todas as senhas foram consumidas." << endl;
    }
    else {
        consumidas->fim->prox = no;
    }
    consumidas->fim = no;

    cout << "" << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "Senha consumida: " << ret << endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout << "" << endl;
    } else {
        cout << "Nenhuma senha para ser consumida" << endl;
    }
}


void freeFila (Fila *f) {
    No *no;
    no = f->ini;
    while (no != NULL) {
        No *temp= no->prox;
        delete no;
        no = temp;
    }
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
                consumirSenha(senhasGeradas, senhasAtendidas);
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

        if (opcao == 0 && !isEmpty(senhasGeradas)) {
            cout << "" << endl;
            cout << "Erro ao finalizar. Ainda ha senhas na fila. " << endl;
            cout << "" << endl;
        }
    }
    while (opcao != 0 || !isEmpty(senhasGeradas));
}
