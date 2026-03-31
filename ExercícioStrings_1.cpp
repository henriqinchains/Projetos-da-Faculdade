#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string msg, limpa;
    std::cout << "Digite a mensagem: ";
    std::getline(std::cin, msg);

    for (char c : msg) {
        if (c != ' ') limpa += std::toupper(c);
    }

    std::string rev = limpa;
    std::reverse(rev.begin(), rev.end());

    if (limpa == rev)
        std::cout << "É palíndromo!" << std::endl;
    else
        std::cout << "Não é palíndromo!" << std::endl;

    return 0;
}