#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream arq("nomes.txt");
    if (!arq) {
        std::cerr << "Erro ao abrir arquivo!" << std::endl;
        return 1;
    }

    std::string nome;
    while (std::getline(arq, nome)) {
        std::istringstream iss(nome);
        std::vector<std::string> partes;
        std::string p;
        while (iss >> p) partes.push_back(p);

        if (!partes.empty()) {
            std::cout << partes.back() << ", ";
            for (size_t i = 0; i < partes.size() - 1; i++)
                std::cout << partes[i] << " ";
            std::cout << std::endl;
        }
    }

    return 0;
}