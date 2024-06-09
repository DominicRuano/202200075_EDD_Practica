#include <iostream>
#include <conio.h>  // Para getch()
#include <limits>
#include <fstream>
#include "./librerias/json.hpp"
#include "./Objects/Agencia.h"
using namespace std;

using json = nlohmann::json;



template <typename T>
void GetOp(T &input);
void Menu(int &input);
json ReadJson(string filePath);
bool CargaAviones(CircularDoublyLinkedList<avion> &listaAviones, CircularDoublyLinkedList<avion> &listaAviones2);
bool EncolarClientes(Queue<Pasajero> &colaPasajeros);
bool CargarMovimientos();

int main(){
    int input;      // Guarda el valor seleccionado por el usuario.
    bool cond;   // Condicion para salir del ciclo.

    Agencia *agencia = new Agencia();
    

    while (input != 6){
        cond = false;

        Menu(input); /*Recibe el apuntador para recibir un input usado como seleccion en el menu*/
        switch (input){
        case 1:
            while (!CargaAviones(agencia->getListAvionesDisponibles(), agencia->getListAvionesMantenimiento()));
            break;
        case 2:
            while (!EncolarClientes(agencia->getQueuePasajeros()));
            break;
        case 3:
            while (!CargarMovimientos());
            break;
        case 4:
            // Funcion aqui.
            break;
        case 5:
            /*
            cout << "\n - Lista de Aviones En mantenimiento: " << endl;
            agencia->getListAvionesMantenimiento().print();
            cout << "\n - Lista de Aviones Disponibles: " << endl;
            agencia->getListAvionesDisponibles().print();
            cout << "\n - La cola de pasajero es: " << endl;
            agencia->getQueuePasajeros().print();
            */
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

/*
Funcion para cargar los movimientos.
aun no recibe parametros.
Retorna un booleano, true si se cargaron los movimientos correctamente, false si hubo un error.
*/
bool CargarMovimientos(){
    string path;

    cout << "\tIngrese la ruta del archivo TXT de Movimientos: ";
    GetOp(path);
    try{
        std::ifstream inputFile(path); // Abrir el archivo

        // Verificar si el archivo se abrió correctamente
        if (!inputFile.is_open()) {
            std::cerr << "No se pudo abrir el archivo." << std::endl;
            return false; 
        }

        string line;
        // Leer el archivo línea por línea
        while (std::getline(inputFile, line)) {
            if (line.compare("IngresoEquipajes;") == 0){
                cout << "Se detecto Ingreso de Equipajes" << endl;
                // Aqui se debe hacer algo con la cola de pasajeros.
                
            }else if (line.compare(0, 29, "MantenimientoAviones,Ingreso,") == 0){
                cout << "Se detecto ingreso a mantenimiento de Aviones" << endl;
                // Aqui se debe hacer algo con la lista de aviones.
            }else if (line.compare(0, 28, "MantenimientoAviones,Salida,") == 0){
                cout << "Se detecto salida de Mantenimiento de Aviones" << endl;
                // Aqui se debe hacer algo con la lista de aviones.
            }   
        }

        inputFile.close(); // Cerrar el archivo
    }catch(const std::exception& e){
        cout << "Se detecto un error: por favor verifique el path del archivo." << endl;
        return false;
    }

    cout << "Presiona Enter para continuar...";
    _getch();  // Espera a que el usuario presione cualquier tecla
    return true;
}

/*
Funcion para cargar los clientes.
Recibe una cola de pasajeros.
Retorna un booleano, true si se cargaron los clientes correctamente, false si hubo un error.
*/
bool EncolarClientes(Queue<Pasajero> &colaPasajeros){
    string path;
    cout << "\tIngrese la ruta del archivo JSON de Clientes: ";
    GetOp(path);
    try{
        json jsonData = ReadJson(path);

        // Acceder a los datos
        for (const auto& item : jsonData) { // Cambiar todo esto por una append a la estructura.
            Pasajero PasajeroActual(item["nombre"], item["nacionalidad"], item["numero_de_pasaporte"], item["vuelo"], item["asiento"], item["destino"], item["origen"], item["equipaje_facturado"]);
            colaPasajeros.enqueue(PasajeroActual);
        }
    }catch(const std::exception& e){
        cout << "Se detecto un error: por favor verifique el path del archivo." << endl;
        return false;
    }
    cout << "\n\tSe tienen (" << colaPasajeros.getLength() << ") Pasajeros en la cola." << endl;

    cout << "Presiona Enter para continuar...";
    _getch();  // Espera a que el usuario presione cualquier tecla
    return true;
}

/*
Funcion para cargar los aviones.
Recibe dos listas de aviones, una para aviones disponibles y otra para aviones en mantenimiento.
Retorna un booleano, true si se cargaron los aviones correctamente, false si hubo un error.
*/
bool CargaAviones(CircularDoublyLinkedList<avion> &listaAviones, CircularDoublyLinkedList<avion> &listaAviones2){
    string path;
    cout << "\tIngrese la ruta del archivo JSON De Aviones: ";
    GetOp(path);
    try{
        json jsonData = ReadJson(path);

        // Acceder a los datos
        for (const auto& item : jsonData) { // Cambiar todo esto por una append a la estructura.
            avion avionActual(item["vuelo"], item["numero_de_registro"], item["modelo"], item["fabricante"], item["ano_fabricacion"], item["capacidad"], item["peso_max_despegue"], item["aerolinea"], item["estado"]);
            if (item["estado"] == "Disponible")
                listaAviones.insert(avionActual);
            else
                listaAviones2.insert(avionActual);
        }
    }catch(const std::exception& e){
        return false;
    }
    cout << "\n\tSe tienen (" << listaAviones.getLength() << ") aviones en la lista de aviones disponibles." << endl;
    cout << "\tSe tienen (" << listaAviones2.getLength() << ") aviones en la lista de aviones en mantenimiento." << endl;

    cout << "Presiona Enter para continuar...";
    _getch();  // Espera a que el usuario presione cualquier tecla
    return true;
}

/* 
Funcion que recibe la ruta(String) de un archivo JSON y retorna un objeto JSON.
*/
json ReadJson(string filePath){
    //string filePath = "./ArchivosEntrada/Aviones.json"; // Ruta del archivo JSON

    // Leer el archivo JSON
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cout << "\tError al cargar el archivo JSON." << endl;
    }

    // Parsear el JSON
    json jsonData;
    inputFile >> jsonData;

    return jsonData;
}

/* 
Funcion que imprime el menu de opciones.
Recibe como parametro un puntero de tipo int, el cual se encarga de recibir el valor del input del usuario.
*/
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

/*
Recibe como parametro un puntero de tipo T, el cual se encarga de recibir el valor del input del usuario.
Retorna el valor del input del usuario en el puntero recibido.
*/
template <typename T>
void GetOp(T &input){
    cin >> input;
    // Maneja errores.
    if (cin.fail() || cin.peek() != '\n') {
        cin.clear(); // Clear the error flag
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}
