#include "../Objects/nodo.h"
using namespace std;


template <typename T>
class CircularDoublyLinkedList{
private:
    Nodo<T> *head;
    int length = 0;
    //Nodo<T> *current;
public:
    CircularDoublyLinkedList(/* args */);
    ~CircularDoublyLinkedList();

    void insert(T &value);
    T remove(string vuelo);
    int getLength(){return length;}
    void Print();
};

template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(/* args */){
    head = nullptr;
}
template <typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList(){
    // Pendiente de implementar
}

template <typename T>
void CircularDoublyLinkedList<T>::insert(T &Value){
    Nodo<T>* nuevoNodo = new Nodo<T>(Value);
    if (!head){
        head = nuevoNodo;
        head->next = head;
        head->prev = head;
    }else{
        Nodo<T>* ultimoNodo = head->prev;
        ultimoNodo->next = nuevoNodo;
        nuevoNodo->prev = ultimoNodo;
        nuevoNodo->next = head;
        head->prev = nuevoNodo;
    }
    length++;
}

template <typename T>
T CircularDoublyLinkedList<T>::remove(string vuelo) {
    if (length == 0)
        throw std::out_of_range("Lista vacía.");

    Nodo<T>* current = head;

    // Encontrar el nodo con el vuelo especificado
    do {
        if (current->data.getVuelo() == vuelo) {
            T data = current->data;
            // Caso de un solo elemento en la lista
            if (length == 1) {
                head = nullptr;
            } else {
                Nodo<T>* prev = current->prev;
                Nodo<T>* next = current->next;
                prev->next = next;
                next->prev = prev;
                if (current == head) {
                    head = next;
                }
            }
            delete current;
            length--;
            return data;
        }
        current = current->next;
    } while (current != head);

    throw std::out_of_range("Vuelo no encontrado.");
}


template <typename T>
void CircularDoublyLinkedList<T>::Print(){
    Nodo<T>* current = head;
    if (length > 0)
        for (int i = 0; i < length; i++){
            current->data.print();
            cout << "---------------------------" << endl;
            current = current->next;
        }
    else 
        out_of_range("Lista vacia.");

}