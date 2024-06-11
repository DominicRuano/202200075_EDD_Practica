#include "./nodo.h"
#include "./avion.h"
#include "./Pasajero.h"
#include "../Structs/CircularDoublyLinkedList.h"
#include "../Structs/Queue.h"
#include "../Structs/Stack.h"
#include "../Structs/DoublyLinkedList.h"

class Agencia{
private:
    CircularDoublyLinkedList<avion> *listaAvionesDisponibles;    /*Guarda aviones disponibles.*/
    CircularDoublyLinkedList<avion> *listaAvionesMantenimiento;  /*Guarda aviones en mantenimiento.*/
    Queue<Pasajero> *colaPasajeros;                              /*Guarda en una cola a los pasajeros. */
    Stack<Pasajero> *pilaPasajeros;                              /*Guarda en una pila a los pasajeros. */
    DoublyLinkedList<Pasajero> *listaPasajeros;                  /*Guarda en una lista a los pasajeros. */
public:
    Agencia(/* args */);
    ~Agencia();

    CircularDoublyLinkedList<avion> &getListAvionesDisponibles(){return *listaAvionesDisponibles;}
    CircularDoublyLinkedList<avion> &getListAvionesMantenimiento(){return *listaAvionesMantenimiento;}
    Queue<Pasajero> &getQueuePasajeros(){return *colaPasajeros;}
    Stack<Pasajero> &getStackPasajeros(){return *pilaPasajeros;}
    DoublyLinkedList<Pasajero> &getListPasajeros(){return *listaPasajeros;}
    void GraficarAvionesDisponibles();

};

Agencia::Agencia(/* args */){
    this->listaAvionesDisponibles = new CircularDoublyLinkedList<avion>();
    this->listaAvionesMantenimiento = new CircularDoublyLinkedList<avion>();
    this->colaPasajeros = new Queue<Pasajero>();
    this->pilaPasajeros = new Stack<Pasajero>();
    this->listaPasajeros = new DoublyLinkedList<Pasajero>();
}
Agencia::~Agencia(){
    delete listaAvionesDisponibles;
    delete listaAvionesMantenimiento;
    delete colaPasajeros;
    delete pilaPasajeros;
    delete listaPasajeros;
}

void Agencia::GraficarAvionesDisponibles(){
    ofstream file;
    file.open("AvionesDisponibles.dot");
    file << "digraph G {" << endl;
    file << "node [shape=record];" << endl;
    file << "rankdir=LR;" << endl;
    file << "label=\"Grafico de todas las estructuras de datos.\";" << endl;
    file << "labelloc=t;" << endl;
    file << "labeljust=l;" << endl;
    file << "node [shape=record];" << endl;
    this->listaAvionesDisponibles->graph(file, "A", "Lista circular de aviones disponibles");
    this->listaAvionesMantenimiento->graph(file, "B", "Lista circular de aviones en mantenimiento");
    //file << "struct1 [label=\"{Avion | Numero de Vuelo: 1234 | Numero de Registro: 1234 | Modelo: 1234 | Fabricante: 1234 | Anio de Fabricacion: 1234 | Capacidad: 1234 | Peso Maximo: 1234 | Aerolinea: 1234 | Estado: 1234}\"];" << endl;
    file << "}" << endl;
    file.close();
    system("dot -Tpng AvionesDisponibles.dot -o AvionesDisponibles.png");
    system("AvionesDisponibles.png");
}