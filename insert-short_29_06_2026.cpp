#include <iostream>
using namespace std;

int main() {

    int v[] = {49, 38, 58, 87, 34, 93, 26, 13};

    int i = sizeof(v) / sizeof(v[0]);

    cout << "vetor antes da ordenacao: ";
    for (int n : v) {
        cout << " " << n;
    }
    cout << endl;

    int auxComparador;
    

    for (int k = 1; k < i; k++) {
        int comparado = v[k];
        auxComparador = k - 1;

        while (auxComparador >= 0 && v[auxComparador] > comparado) {
            v[auxComparador + 1] = v[auxComparador];
            auxComparador--;
        }

        v[auxComparador + 1] = comparado;
    }

    cout << "valor depois da ordenacao: ";
    for (int n : v) {
        cout << " " << n;
    }

}
