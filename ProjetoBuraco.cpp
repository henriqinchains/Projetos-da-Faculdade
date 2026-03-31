#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int main() {
    string baralho[2][52];  
    string mao[4][11];      

    
    for (int b = 0; b < 2; b++) { 
        int idx = 0;
        for (int n = 1; n <= 4; n++) {     
            for (int c = 1; c <= 13; c++) {  
                char buffer[10];
                sprintf(buffer, "%d-%02d-%d", n, c, b+1);
                baralho[b][idx++] = buffer;
            }
        }
    }

   
    string monte[104];
    for (int i = 0; i < 52; i++) {
        monte[i] = baralho[0][i];
        monte[i+52] = baralho[1][i];
    }

    
    srand(time(nullptr));
    shuffle(monte, monte+104, default_random_engine(rand()));

    
    int pos = 0;
    for (int j = 0; j < 4; j++) {
        for (int c = 0; c < 11; c++) {
            mao[j][c] = monte[pos++];
        }
    }

    
    for (int j = 0; j < 4; j++) {
        cout << "\nJogador " << j+1 << ":\n";
        for (int c = 0; c < 11; c++) {
            cout << " - " << mao[j][c] << "\n";
        }
    }

    return 0;
}