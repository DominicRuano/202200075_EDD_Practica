#include <iostream>
#include "./Objects/nodo.h"
#include <limits>
#include <fstream>
#include "./json.hpp"
using namespace std;

using json = nlohmann::json;

/* Funcion que despliega el menu principal. */
int Menu();
/* Funcion que lee un json. */
void ReadJson();

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
            ReadJson();
            // Funcion aqui.
            break;
        default:
            // Funcion aqui.
            break;
        }
    }
    return 0;
}

void ReadJson(){
    string filePath = "Aviones.json"; // Ruta del archivo JSON

    // Leer el archivo JSON
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
    }

    // Parsear el JSON
    json jsonData;
    inputFile >> jsonData;

    // Acceder a los datos
    for (const auto& item : jsonData) { // Cambiar todo esto por una append a la estructura.
        std::cout << "Vuelo: " << item["vuelo"] << std::endl;
        std::cout << "Numero de Registro: " << item["numero_de_registro"] << std::endl;
        std::cout << "Modelo: " << item["modelo"] << std::endl;
        std::cout << "Fabricante: " << item["fabricante"] << std::endl;
        std::cout << "Ano de Fabricacion: " << item["ano_fabricacion"] << std::endl;
        std::cout << "Capacidad: " << item["capacidad"] << std::endl;
        std::cout << "Peso Max Despegue: " << item["peso_max_despegue"] << std::endl;
        std::cout << "Aerolinea: " << item["aerolinea"] << std::endl;
        std::cout << "Estado: " << item["estado"] << std::endl;
        std::cout << "---------------------------" << std::endl;
    }

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
