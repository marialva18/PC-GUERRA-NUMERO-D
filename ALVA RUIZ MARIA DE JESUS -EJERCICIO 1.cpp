#include<iostream>
#include<conio.h>
using namespace std;

int main() {
    int Matriz[3][3];
    int sumafila[3] = {0, 0, 0};
    int sumacolumna[3] = {0, 0, 0};
    int i, j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cout << "DIGITE UN NUMERO [" << i << "][" << j << "] : ";
            cin >> Matriz[i][j];
        }        
    }

    cout << "\nLA MATRIZ PRINCIPAL ES:\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cout << Matriz[i][j] << "\t";    
        }
        cout << "\n";        
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            sumafila[i] += Matriz[i][j];
        }
    }

    for(j = 0; j < 3; j++) {
        for(i = 0; i < 3; i++) {
            sumacolumna[j] += Matriz[i][j];
        }
    }

    cout << "\nLA SUMA DE CADA FILA ES:\n";
    for(i = 0; i < 3; i++) {
        cout << "Fila " << i << ": " << sumafila[i] << endl;
    }

    cout << "\nLA SUMA DE CADA COLUMNA ES:\n";
    for(j = 0; j < 3; j++) {
        cout << "Columna " << j << ": " << sumacolumna[j] << endl;
    }

    getch();
    return 0;
}

