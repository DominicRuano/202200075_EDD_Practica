#include <iostream>
#include "./Objects/nodo.h"
#include <limits>
using namespace std;

/* Funcion que despliega el menu principal. */
int Menu();

int main(){
    int input; // Guarda el valor seleccionado por el usuario.
    int stop;
    while (input != 6){
        Menu();
        cin >> input;
        // Maneja errores.
        if (cin.fail() || cin.peek() != '\n' || input < '0' || input > '9') {
            cin.clear(); // Clear the error flag
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        switch (input){
        case 1:
            cout << "Se selecciono 1." << endl;
            // Funcion aqui.
            break;
        case 2:
            cout << "Se selecciono 2" << endl;
            // Funcion aqui.
            break;
        case 3:
            cout << "Se selecciono 3" << endl;
            // Funcion aqui.
            break;
        case 4:
            cout << "Se selecciono 4" << endl;
            // Funcion aqui.
            break;
        case 5:
            cout << "Se selecciono 5" << endl;
            // Funcion aqui.
            break;
        case 6:
            cout << "Se selecciono 6." << endl;
            // Funcion aqui.
            break;
        default:
            // Funcion aqui.
            break;
        }
    }
    return 0;
}

int Menu(){
    system("cls");
    cout << "------------ MENU --------------" << endl;
    cout << "1. Carga de Aviones." << endl;
    cout << "2. Carga de Pasajeros." << endl;
    cout << "3. Carga de Movimientos." << endl;
    cout << "4. Consulta Pasajeros." << endl;
    cout << "5. Visualizar Reportes." << endl;
    cout << "6. Salir." << endl;
}
