#include <iostream>
#include <iomanip>
#include <locale.h>
#include <windows.h>

using namespace std;

#define COL 40
#define LIN 15
#define PRECO 10

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int reservas15 = 0;
int reservas610 = 0;
int reservas1115 = 0;


void reservar(int cinema[LIN][COL])
{
	int fileira, poltrona;
	
	cout << "| Selecione a fileira (1-15): ";
	cin >> fileira;
	
	cout << "| Selecione a poltrona (1-40): ";
	cin >> poltrona;
	
	if (fileira <1 || fileira >LIN || poltrona <1 || poltrona >COL)
	{
		cout << "|";
		SetConsoleTextAttribute(hConsole, 12);
		cout << " Lugar inválido!" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		return; 
	}


if(cinema [fileira -1][poltrona -1] == 0)
{
	if (fileira -1 < 5)
	{
	cout << "|Reserva realizada com sucesso!" << endl;
	reservas15++;	
	cinema [fileira -1][poltrona -1] = 1;
	}
	else if (fileira -1 < 10){
		cout << "|Reserva realizada com sucesso!" << endl;
		reservas610++;
		   cinema [fileira -1][poltrona -1] = 1	;
	}
	else {
		cout << "|Reserva realizada com sucesso!" << endl;
	reservas1115++;
	cinema [fileira -1][poltrona -1] = 1;
	}
}
else
{
	cout << "|";
	SetConsoleTextAttribute(hConsole, 12);
	cout << "Esta poltrona já foi reservada. Tente outra ou verifique as disponíveis pressionando '3'." << endl;	
	SetConsoleTextAttribute(hConsole, 7);
}
}
void poltronas(int cinema[LIN][COL])
{
	cout << " __________________" << endl;
	cout <<"| MAPA DE OCUPAÇÃO |" << endl;
	cout << " ------------------" << endl;
	
	int exibirfileira = 1;
	
	//exibir coluna das poltronas
	cout << "   ";
	for(int coluna=1; coluna<=COL;coluna++)
	{
		cout << setw(3) << coluna;
	}
	cout << endl;
	
    for(int i=0;i<LIN;i++)
    {
    	//exibir fileira das poltronas
		cout << setw(3) << exibirfileira++  <<"|" ;	
		
        for(int j=0;j<COL;j++)
        {	
        	
            if(cinema[i][j] == 0)
                cout << setw(3) << ". ";
            else							
                cout << setw(3) << "# ";	   
        }
        
        cout << endl;
    }
	
	cout << " _______________________" << endl;
	cout << "| Legenda               |" << endl;
	cout << "| . = Poltrona vaga     |" << endl;
	cout << "| # = Poltrona ocupada  |" << endl;
	cout << " -----------------------" << endl;
}

void faturamento()
{
	int faturamento = (reservas15 * (PRECO * 5)) + (reservas610 * (PRECO * 3)) + (reservas1115 * (PRECO * 3/(2)));
	
	cout << "|" << endl;
	cout << "|  Quantidade de poltronas ocupadas: " << reservas15 + reservas610 + reservas1115 << endl;
	cout << "|  Faturamento atual: R$" << fixed<<setprecision(2) << faturamento << endl;
	cout << "|" << endl;
}


int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int cinema[LIN][COL] = {0};
	int opcao;

	do {
		
	cout << " _______________________________________ " << endl;
	cout << "|                  MENU              || |" << endl;					
	cout << "|------------------------------------|| |" << endl;
	cout << "|                                    || |" << endl;
	cout << "|0 - Finalizar                       || |" << endl;
	cout << "|1 - Reservar uma poltrona           || |" << endl;
	cout << "|2 - Verificar poltronas disponíveis || |" << endl;
	cout << "|3 - Verificar faturamento atual     || |" << endl;
	cout << "|                                    || /" << endl;
	cout << " ===================================== /" << endl;
	cout << "|Escolha uma opção : ";
	cin >> opcao;
	
	//verificar se a entrada foi um numero inteiro
	if(cin.fail())
	{
		cout << "|" << endl;
		cout << "|";
		SetConsoleTextAttribute(hConsole, 12);
	
		cout << " Opção inválida. Selecione alguma entre '0' e '3', por gentileza." << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "|" << endl;

		
		cin.clear();
		cin.ignore(1000, '\n');
		continue;
	}
	
	switch(opcao)
	{
	case 1:
		reservar(cinema);
		break;
	case 2:
		poltronas(cinema);
		break;
	case 3:
		faturamento();
		break;
	}
	
	//verificar se o numero inteiro foi entre 0 e 3
	if(opcao < 0 || opcao > 3)
	{
		cout << "|" << endl;
		cout << "|";
		SetConsoleTextAttribute(hConsole, 12);
		cout << " Opção inválida. Selecione alguma entre '0' e '3', por gentileza." << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "|" << endl;
	}
	
	}
	while (opcao != 0);
}