#include <iostream>
#include <conio.h>  // Para getch()
#include "./Structs/CircularDoublyLinkedList.h"
#include "./Objects/avion.h"
#include <limits>
#include <fstream>
#include "./librerias/json.hpp"
using namespace std;

using json = nlohmann::json;



/*Funcion que recibe un puntero de tipo generico.*/
template <typename T>
void GetOp(T &input);

/* Funcion que despliega el menu principal.
    Recibe como parametro una direccion en la cual se guardara la opcion seleccionada.*/
void Menu(int &input);

/* Funcion que lee un json. 
    Recibe como parametro un string con el path del json y dos lista, aviones disponibles, aviones en mantenimiento*/
void ReadJson(string filePath, CircularDoublyLinkedList<avion> &listaAviones, CircularDoublyLinkedList<avion> &listaAviones2);

/*Funcion para la opcion cargar Aviones.*/
bool CargaAviones(CircularDoublyLinkedList<avion> &listaAviones, CircularDoublyLinkedList<avion> &listaAviones2);

int main(){
    int input;      // Guarda el valor seleccionado por el usuario.
    bool cond;   // Condicion para salir del ciclo.

    CircularDoublyLinkedList<avion> listaAvionesDisponibles;    /*Guarda aviones disponibles.*/
    CircularDoublyLinkedList<avion> listaAvionesMantenimiento;  /*Guarda aviones en mantenimiento.*/

    while (input != 6){
        cond = false;

        Menu(input);
        switch (input){
        case 1:
            do
                cond = CargaAviones(listaAvionesDisponibles,listaAvionesMantenimiento);
            while (cond == false);
            break;
        case 2:
            // Funcion aqui.
            break;
        case 3:
            // Funcion aqui.
            break;
        case 4:
            // Funcion aqui.
            break;
        case 5:
            cout << "\n - Lista de Aviones En mantenimiento: " << endl;
            listaAvionesMantenimiento.print();
            cout << "\n - Lista de Aviones Disponibles: " << endl;
            listaAvionesDisponibles.print();

            cout << "Presiona Enter para continuar...";
            _getch();  // Espera a que el usuario presione cualquier tecla
            break;
        case 6:
            break;
        default:
            break;
        }
    }
    return 0;
}

bool CargaAviones(CircularDoublyLinkedList<avion> &listaAviones, CircularDoublyLinkedList<avion> &listaAviones2){
    string path;
    cout << "\tIngrese la ruta del archivo JSON: ";
    GetOp(path);
    try{
        ReadJson(path,listaAviones,listaAviones2);
    }catch(const std::exception& e){
        return false;
    }
    cout << "\n\tSe tienen (" << listaAviones.getLength() << ") aviones en la lista de aviones disponibles." << endl;
    cout << "\tSe tienen (" << listaAviones2.getLength() << ") aviones en la lista de aviones en mantenimiento." << endl;

    cout << "Presiona Enter para continuar...";
    _getch();  // Espera a que el usuario presione cualquier tecla
    return true;

}

void ReadJson(string filePath, CircularDoublyLinkedList<avion> &listaAviones, CircularDoublyLinkedList<avion> &listaAviones2){
    //string filePath = "./ArchivosEntrada/Aviones.json"; // Ruta del archivo JSON

    // Leer el archivo JSON
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cout << "\tError al cargar el archivo JSON." << endl;
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

void Menu(int &input){
    system("cls");
    cout << "------------ MENU --------------" << endl;
    cout << "1. Carga de Aviones." << endl;
    cout << "2. Carga de Pasajeros." << endl;
    cout << "3. Carga de Movimientos." << endl;
    cout << "4. Consulta Pasajeros." << endl;
    cout << "5. Visualizar Reportes." << endl;
    cout << "6. Salir." << endl;

    cout << "Seleccione una opcion: ";
    GetOp(input);
}

template <typename T>
void GetOp(T &input){
    cin >> input;
    // Maneja errores.
    if (cin.fail() || cin.peek() != '\n') {
        cin.clear(); // Clear the error flag
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}
