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