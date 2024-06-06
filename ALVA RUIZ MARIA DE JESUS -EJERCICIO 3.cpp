#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;

struct CLIENTE {
    char nombre[50];
    int numunidades;
    float preciounidad;
    char estado[90];    
} clientenum[50];

int main() {
    int cant = 0, mor0so = 0, guesscant,unidadespe=0, i;
    float totalfactura = 0.0, sumafacturas = 0.0, promedio = 0.0;
    char resp;
    
    while (true) {
        system("cls");
        fflush(stdin);
        cout << "INGRESE EL NOMBRE DEL CLIENTE " << cant + 1 << " : ";
        cin.getline(clientenum[cant].nombre, 50, '\n');
        cout << "INGRESE EL NUMERO UNIDADES REQUERIDAS POR CLIENTE " << cant + 1 << " : ";
        cin >> clientenum[cant].numunidades;
        cout << "\n";
        cout << "INGRESE EL PRECIO DE LA UNIDAD : ";
        cin >> clientenum[cant].preciounidad;
        fflush(stdin);
        
        do {
            cout << "INGRESE EL ESTADO DEL CLIENTE (MOROSO, ATRASADO, PAGADO) " << cant + 1 << " : ";
            cin.getline(clientenum[cant].estado, 90, '\n');
            strupr(clientenum[cant].estado);
        } while (strcmp(clientenum[cant].estado, "MOROSO") != 0 && strcmp(clientenum[cant].estado, "ATRASADO") != 0 && strcmp(clientenum[cant].estado, "PAGADO") != 0);
        
        if (strcmp(clientenum[cant].estado, "MOROSO") == 0) {
           mor0so++;
        }

        cout << "\nDESEA INGRESAR UN NUEVO CLIENTE? (s/n)" << endl;
        cin >> resp;
        resp = toupper(resp);
        if (resp == 'N') {
            break;
        }

        cant++;
    }

    system("cls");
    for (i = 0; i <= cant; i++) {
        totalfactura = clientenum[i].numunidades * clientenum[i].preciounidad;
        sumafacturas += totalfactura;

        cout << "FACTURA DE CLIENTE " << i + 1 << endl;
        cout << "NOMBRE: " << clientenum[i].nombre << endl;
        cout << "UNIDADES COMPRADAS: " << clientenum[i].numunidades << endl;
        cout << "MONTO A PAGAR: " << totalfactura << endl;
        cout << "ESTADO DEL CLIENTE: " << clientenum[i].estado << endl;
        cout << "\n";
    }

    promedio = sumafacturas / (cant + 1);

    cout << "INGRESE UNA CANTIDAD DE UNIDADES : ";
    cin >> guesscant;
    cout << "HAY"<< unidadespe<< "CLIENTES QUE PIDIERON MAS O IGUAL CANTIDAD DE UNIDADES: " << endl;
    for (i = 0; i <= cant; i++) {
        if (clientenum[i].numunidades >= guesscant) {
            cout << clientenum[i].nombre << " (" << clientenum[i].numunidades << " unidades)" << endl;
            unidadespe++;
        }
    }

    cout << mor0so << " CLIENTES EN ESTADO MOROSO:" << endl;
    for(i=0;i<=cant;i++){
    	if(strcmp(strupr(clientenum[i].estado),"MOROSO")==0){
     cout << clientenum[i].nombre << endl;

    	}
    }
    cout << "PROMEDIO DE LAS FACTURAS: " << promedio << endl;

    getch();
    return 0;
}

