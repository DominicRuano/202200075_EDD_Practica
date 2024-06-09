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