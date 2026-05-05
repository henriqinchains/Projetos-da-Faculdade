#include <iostream>
#include <string>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

struct Lista {
    int prontuario;
    string nome;
    double salario;
    Lista *prox;    
};

Lista* init() {
    return NULL;
}

int isEmpty(Lista* lista) {
    return (lista == NULL);
}

Lista* encontrar(Lista* lista, int prontuario) {
    Lista* aux = lista;
    while(aux != NULL && aux->prontuario != prontuario) {
        aux = aux->prox;
    }   
    return aux;
}

Lista* incluir(Lista* lista, int prontuario, string nome, double salario) {\
    if (encontrar(lista, prontuario) != NULL) {
        cout << "Já existe funcionário com prontuário " << prontuario << "." << endl;
        return lista;
    }
    Lista* novo = new Lista();
    novo->prontuario = prontuario;
    novo->nome = nome;
    novo->salario = salario;
    novo->prox = lista;
    return novo;
}

Lista* excluir(Lista* lista, int prontuario)
{
	Lista* ant = NULL;
    Lista* aux;
	aux = lista;
    while(aux != NULL && aux->prontuario != prontuario)
	{
		ant = aux;
		aux = aux->prox;
	}	
	if (aux == NULL)
	{
		return lista;
	}	
	if (ant == NULL) // era o primeiro
	{
		lista = aux->prox;
	}
	else // estava no meio
	{
		ant->prox = aux->prox;
	}
	delete aux;
	return lista;
}

void listar(Lista* lista) {
    if (lista == NULL) {
        cout << "Nenhum funcionario cadastrado." << endl;
        return;
    }

    Lista* aux = lista;
    double total = 0;

    cout << "__________________________" << endl;
    while(aux != NULL) {
        cout << "PRONTUARIO: " << aux->prontuario << endl; 
        cout << "NOME: " << aux->nome << endl;
        cout << "SALARIO: " << aux->salario << endl;
        cout << "--------------------------" << endl;

        total += aux->salario;
        aux = aux->prox;
    }
    cout << "TOTAL DOS SALARIOS: " << total << endl;
    cout << "__________________________" << endl;
}

void freeLista(Lista* lista) {
    Lista* aux = lista;
    while(aux != NULL) {
        Lista* ant = aux->prox;
        delete aux;
        aux = ant;
    }   
}

int main(int argc, char** argv) {
    int prontuario, opcao;
    double salario;
    string nome;
    
    Lista *funcionarios = init();
    
    do {
        cout << " ____________________________ " << endl;
        cout << "|          MENU          ||  |" << endl;                   
        cout << "|------------------------||  |" << endl;
        cout << "|                        ||  |" << endl;
        cout << "|0 - Sair                ||  |" << endl;
        cout << "|1 - Incluir             ||  |" << endl;
        cout << "|2 - Excluir             ||  |" << endl;
        cout << "|3 - Pesquisar           ||  |" << endl;
        cout << "|4 - Lista               ||  /" << endl;
        cout << "|                        || / " << endl;
        cout << "|_________________________|/" << endl;
        cout << "|Escolha uma opção : ";
        cin >> opcao;
        
        if(cin.fail()) {
            SetConsoleTextAttribute(hConsole, 12);
            cout << " Opção inválida. Selecione alguma entre '0' e '4'." << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        
        switch(opcao) {
        case 1: {
            cout << "Digite o prontuario: ";
            cin >> prontuario;
            if (cin.fail()) {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Digite apenas números inteiros para o prontuário." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }

            cout << "Digite o nome: ";
            cin >> nome;
            if (cin.fail()) {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Digite apenas caracteres alfabéticos." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }

            cout << "Digite o salario: ";
            cin >> salario;
            if (cin.fail()) {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Não é possível digitar símbolos ou letras aqui." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }

            if (encontrar(funcionarios, prontuario) != NULL) {
                cout << "Já existe funcionário com prontuário " << prontuario << "." << endl;
            } else {
                funcionarios = incluir(funcionarios, prontuario, nome, salario);
            }
            break;
        }
        case 2: {
            cout << "Digite o prontuario do funcionario a ser desligado: ";
            cin >> prontuario;
            if (cin.fail()) {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Digite apenas números inteiros para o prontuário." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            funcionarios = excluir(funcionarios, prontuario);
            break;
        }
        case 3: {
            cout << "Digite o prontuario do funcionario que deseja pesquisar: ";
            cin >> prontuario;
            if (cin.fail()) {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Digite apenas números inteiros para o prontuário." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            Lista* procurado = encontrar(funcionarios, prontuario);
            if (procurado == NULL) {
                cout << "Funcionario nao encontrado." << endl;
            } else {
                cout << "Funcionario pesquisado: " << procurado->prontuario << endl;
                cout << "NOME: " << procurado->nome << endl;
                cout << "SALARIO: " << procurado->salario << endl;
            }
            break;
        }
        case 4: {
            listar(funcionarios);
            break;
        }
        }
        
        if(opcao < 0 || opcao > 4) {
            SetConsoleTextAttribute(hConsole, 12);
            cout << " Opção inválida. Selecione alguma entre '0' e '4'." << endl;
            SetConsoleTextAttribute(hConsole, 7);
        }
    } while (opcao != 0);

    freeLista(funcionarios);
    return 0;
}
