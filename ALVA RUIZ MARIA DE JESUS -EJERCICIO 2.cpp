#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main() {
    int notas[8], suma[90] = {0}, sumanotas[8] = {0}, i, cant = 0, no[90] = {0};
    float promedio[90], promgeneral = 0.0;
    char resp, respa;

    while (true) {
        system("cls");
        cout << "ALUMNO " << cant + 1 << ":" << endl;
        int sumaa = 0;
        
        for (i = 0; i < 8; i++) {
            cout << "ASISTIO AL EXAMEN DEL CURSO " << i + 1 << "?(s/n):  "; cin >> respa;
            if (respa == 's' || respa == 'S') {
                do {
                    cout << "DIGITE CALIFICACION VALIDA DE CURSO " << i + 1 << ": "; cin >> notas[i];
                } while (notas[i] < 0 || notas[i] > 20);
            } else {
                notas[i] = 0; 
                no[cant]++;
            }
            sumaa += notas[i];
            sumanotas[i] += notas[i];
        }

        promedio[cant] = (float)sumaa / 8; 
        promgeneral += promedio[cant];

        cout << "DESEA INGRESAR DATOS DE NUEVO ALUMNO (s/n)? "; cin >> resp;
        if (resp == 'n' or resp == 'N') {
            break;
        }

        cant++;
    }

    promgeneral /= (cant + 1);

    system("cls");
    for (int j = 0; j <= cant; j++) {
        cout << "DATOS DEL ALUMNO " << j + 1 << ":" << endl;
        cout << "PROMEDIO DEL ALUMNO: " << promedio[j] << endl;
        cout << "PORCENTAJE DE FALTAS DEL ALUMNO: " << ((float)no[j] / 8) * 100 << "%" << endl;
        cout << endl;
    }

    cout << "PROMEDIO GENERAL DE LA CLASE: " << promgeneral << endl;

    for (i = 0; i < 8; i++) {
        float promediocurso = (float)sumanotas[i] / (cant + 1);
        cout << "PROMEDIO DEL CURSO " << i + 1 << ": " << promediocurso << endl;
    }

    getch();
    return 0;
}

