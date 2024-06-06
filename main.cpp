#include <iostream>
#include "./Structs/CircularDoublyLinkedList.h"
#include "./Objects/avion.h"
#include <limits>
#include <fstream>
#include "./librerias/json.hpp"
using namespace std;

using json = nlohmann::json;

/* Funcion que despliega el menu principal. */
int Menu();
/* Funcion que lee un json. */
void ReadJson(CircularDoublyLinkedList<avion> &listaAviones,CircularDoublyLinkedList<avion> &listaAviones2);

int main(){
    int input; // Guarda el valor seleccionado por el usuario.
    int stop;
    CircularDoublyLinkedList<avion> listaAvionesDisponibles;
    CircularDoublyLinkedList<avion> listaAvionesMantenimiento;
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
            ReadJson(listaAvionesDisponibles,listaAvionesMantenimiento);
            cout << "\n - Lista de Aviones En mantenimiento: " << endl;
            listaAvionesMantenimiento.print();
            cout << "\n - Lista de Aviones Disponibles: " << endl;
            listaAvionesDisponibles.print();
            break;
        default:
            // Funcion aqui.
            break;
        }
    }
    return 0;
}

void ReadJson(CircularDoublyLinkedList<avion> &listaAviones,CircularDoublyLinkedList<avion> &listaAviones2){
    string filePath = "./ArchivosEntrada/Aviones.json"; // Ruta del archivo JSON

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
        avion avionActual(item["vuelo"], item["numero_de_registro"], item["modelo"], item["fabricante"], item["ano_fabricacion"], item["capacidad"], item["peso_max_despegue"], item["aerolinea"], item["estado"]);
        if (item["estado"] == "Disponible")
            listaAviones.insert(avionActual);
        else
            listaAviones2.insert(avionActual);
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
