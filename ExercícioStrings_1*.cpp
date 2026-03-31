#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>

void limparTela() {
     system("cls");
}

int main() {
    std::string mensagem;
    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, mensagem);

    int larguraTela = 80;
    int pos = (larguraTela - mensagem.size()) / 2;

    for (int linha = 5; linha <= 20; linha++) {
        limparTela();
        for (int i = 0; i < linha; i++) std::cout << "\n";
        std::cout << std::string(pos, ' ') << mensagem << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    return 0;
}