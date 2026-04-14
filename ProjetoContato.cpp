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
	Contato contato[5];
	
	for(int i=0; i<5 ;i++){
    cout << "Digite o nome do contato: " << endl;
	cin >> input;
	contato[i].setNome(input);
	cout << "Digite o email do contato: " << endl;
	cin >> input;
	contato[i].setEmail(input);
	cout<< "Digite o telefone do contato: " << endl;
	cin >> input;
	contato[i].setTelefone(input);
	cout << "Digite a data de nascimento: (dd/mm/aaaa/)" << endl;
	cin >> dia >> mes >> ano;
	contato[i].setDtNasc(Data(dia, mes, ano));
	cin.clear();
	}

	
	
	cout << " _____________________________________  " << endl;
	cout << "|      Contatos cadastrados: 5        |  " << endl;					
	cout << "|-------------------------------------|  " << endl;
    cout << "|                                     | " << endl;
    for(int i=0; i<5 ;i++){
    cout << "|_____________________________________| " << endl;
	cout << "| Nome: " << contato[i].getNome() << "        " << endl;
	cout << "|                                     |" << endl;
	cout << "| Email: " << contato[i].getEmail() << endl;
    cout << "| Telefone: " << contato[i].getTelefone() << endl;
    cout << "| Nascimento: " << contato[i].getDtNasc().getDia() << "/" << contato[i].getDtNasc().getMes() << "/" << contato[i].getDtNasc().getAno() << endl;
	cout << " =====================================|" << endl;
}


	
}
