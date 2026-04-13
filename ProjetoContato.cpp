/* Desenvolva um programa que permita a digitação (e posterior exibição), dos dados relativos à classe "Contato" abaixo descrita:

---------------------
| Data              |
|-------------------|
| - dia: int        |
| - mes: int        |
| - ano: int        |
---------------------
-----------------------
| Contato             |
|---------------------|
| - email: string     |
| - nome: string      |
| - telefone: string  |
| - dtnasc: Data      |
|---------------------|
| + idade(): int      |
-----------------------

Implementar construtores, getter's e setter's.

OBSERVAÇÕES:

Utilizar a classe Data implementada durante os exemplos da aula;
Utilizar o ano de 2026 para o cálculo da idade ou buscar alternativa para pegar, de forma automática, o ano do sistema operacional.
Implementar uma solução que permita cadastrar e exibir uma estrutura com 5 contatos (ao exibir, informar nome, e-mail, telefone e idade). */

#include <iostream>
#include <locale.h>
#include <ctime>
#include <string>

using namespace std;

class Data 
{
	private:
	   int dia;
   	   int mes;
	   int ano;
     public:
     	Data(int dia, int mes, int ano)
     	{
		 	this->dia = dia;
		 	this->mes = mes;
		 	this->ano = ano;
        }
        Data()
        {
			time_t agora = time(0);
		 	tm *local = localtime(&agora);
		 	dia = local->tm_mday;
		 	mes = local->tm_mon + 1;
		 	ano = local->tm_year + 1900;
		}
		void setDia(int dia)
		{
			this->dia = dia;
		}
		void setMes(int mes)
		{
			this->mes = mes;
		}
		void setAno(int ano)
		{
			this->ano = ano;			
		}
		int getDia()
		{
			return this->dia;
		}
		int getMes()
		{
			return this->mes;
		}
		int getAno()
		{
			return this->ano;
		}	
};		

class Contato
{
	private:
		string email;
		string nome;
		string telefone;
		Data dtNasc;
	public:
		Contato(string email, string nome, string telefone, Data dtNasc){
		this->email = email;
		this->nome = nome;
		this->telefone = telefone;
		this->dtNasc = dtNasc;	
		}
		void setEmail(string email)
		{
			this->email = email;
		}
		void setNome(string nome)
		{
			this->nome = nome;
		}
		void setTelefone(string telefone)
		{
			this->telefone = telefone;			
		}
		void setDtNasc(Data dtNasc)
		{
			this->dtNasc = dtNasc;
		}
		string getEmail()
		{
			return this->email;
		}
		string getNome()
		{
			return this->nome;
		}
		string getTelefone()
		{
			return this->telefone;
		}	
		Data getDtNasc()
		{
			return this->dtNasc;
		}
		Contato(){}
};	


int main(int argc, char** argv)
{
	string input;
	int dia, mes, ano;
	

		
	Contato um;
	Contato dois;
	Contato tres;
	Contato quatro;
	Contato cinco;
	
	cout << "Digite o email do contato: " << endl;
	cin >> input;
	um.setEmail(input);
	cout << "Digite o nome do contato: " << endl;
	cin >> input;
	um.setNome(input);
	cout<< "Digite o telefone do contato: " << endl;
	cin >> input;
	um.setTelefone(input);
	cout << "Digite a data de nascimento: (dd/mm/aaaa/)" << endl;
	cin >> dia >> mes >> ano;
	Data nasc1(dia, mes, ano);
	um.setDtNasc(nasc1);
	cin.clear();
	
	cout << "Digite o email do segundo contato: " << endl;
	cin >> input;
	dois.setEmail(input);
	cout << "Digite o nome do segundo contato: " << endl;
	cin >> input;
	dois.setNome(input);
	cout<< "Digite o telefone do segundo contato: " << endl;
	cin >> input;
	dois.setTelefone(input);
	cout << "Digite a data de nascimento do segundo contato: (dd/mm/aaaa/)" << endl;
	cin >> dia >> mes >> ano;
	Data nasc2(dia, mes, ano);
	dois.setDtNasc(nasc2);
	
	cout << "Digite o email do terceiro contato: " << endl;
	cin >> input;
	tres.setEmail(input);
	cout << "Digite o nome do terceiro contato: " << endl;
	cin >> input;
	tres.setNome(input);
	cout<< "Digite o telefone do terceiro contato: " << endl;
	cin >> input;
	tres.setTelefone(input);
	cout << "Digite a data de nascimento do terceiro contato: (dd/mm/aaaa/)" << endl;
	cin >> dia >> mes >> ano;
	Data nasc3(dia, mes, ano);
	tres.setDtNasc(nasc3);
	cin.clear();
	
	cout << "Digite o email do quarto contato: " << endl;
	cin >> input;
	quatro.setEmail(input);
	cout << "Digite o nome do quarto contato: " << endl;
	cin >> input;
	quatro.setNome(input);
	cout<< "Digite o telefone do quarto contato: " << endl;
	cin >> input;
	quatro.setTelefone(input);
	cout << "Digite a data de nascimento do quarto contato: (dd/mm/aaaa/)" << endl;
	cin >> dia >> mes >> ano;
	Data nasc4(dia, mes, ano);
	quatro.setDtNasc(nasc4);
	
	cout << "Digite o email do quinto contato: " << endl;
	cin >> input;
	cinco.setEmail(input);
	cout << "Digite o nome do quinto contato: " << endl;
	cin >> input;
	cinco.setNome(input);
	cout<< "Digite o telefone do quinto contato: " << endl;
	cin >> input;
	cinco.setTelefone(input);
	cout << "Digite a data de nascimento do quinto contato: (dd/mm/aaaa/)" << endl;
	cin >> dia >> mes >> ano;
	Data nasc5(dia, mes, ano);
	cinco.setDtNasc(nasc5);
	
	
	cout << " _____________________________________  " << endl;
	cout << "|      Contatos cadastrados: 5        |  " << endl;					
	cout << "|-------------------------------------|  " << endl;
    cout << "|                                     | " << endl;
	cout << "|_____________________________________| " << endl;
	cout << "| Nome: " << um.getNome() << "        " << endl;
	cout << "|-------------------------------------|" << endl;
	cout << "|Email: " << um.getEmail() << endl;
    cout << "|Telefone: " << um.getTelefone() << endl;
    cout << "|Nascimento: " << um.getDtNasc().getDia() << "/" << um.getDtNasc().getMes() << "/" << um.getDtNasc().getAno() << endl;
	cout << " =====================================|" << endl;
    cout << "|                                     | " << endl;
    cout << "|_____________________________________| " << endl;
	cout << "| Nome: " << dois.getNome() << "        " << endl;
	cout << "|-------------------------------------|" << endl;
	cout << "|Email: " << dois.getEmail() << endl;
    cout << "|Telefone: " << dois.getTelefone() << endl;
    cout << "|Nascimento: " << dois.getDtNasc().getDia() << "/" << dois.getDtNasc().getMes() << "/" << dois.getDtNasc().getAno() << endl;
	cout << " ===================================== |" << endl;
    cout << "|                                     | " << endl;
    cout << "|_____________________________________| " << endl;
	cout << "| Nome: " << tres.getNome() << "        " << endl;
	cout << "|-------------------------------------|" << endl;
	cout << "|Email: " << tres.getEmail() << endl;
    cout << "|Telefone: " << tres.getTelefone() << endl;
    cout << "|Nascimento: " << tres.getDtNasc().getDia() << "/" << tres.getDtNasc().getMes() << "/" << tres.getDtNasc().getAno() << endl;
	cout << " ===================================== |" << endl;
    cout << "|                                     | " << endl;
    cout << "|_____________________________________| " << endl;
	cout << "| Nome: " << quatro.getNome() << "        " << endl;
	cout << "|-------------------------------------|" << endl;
	cout << "|Email: " << quatro.getEmail() << endl;
    cout << "|Telefone: " << quatro.getTelefone() << endl;
    cout << "|Nascimento: " << quatro.getDtNasc().getDia() << "/" << quatro.getDtNasc().getMes() << "/" << quatro.getDtNasc().getAno() << endl;
	cout << " ===================================== |" << endl;
    cout << "|                                     | " << endl;
    cout << "|_____________________________________| " << endl;
	cout << "| Nome: " << cinco.getNome() << "        " << endl;
	cout << "|-------------------------------------|" << endl;
	cout << "|Email: " << cinco.getEmail() << endl;
    cout << "|Telefone: " << cinco.getTelefone() << endl;
    cout << "|Nascimento: " << cinco.getDtNasc().getDia() << "/" << cinco.getDtNasc().getMes() << "/" << cinco.getDtNasc().getAno() << endl;
	cout << " ===================================== |" << endl;


	
}
