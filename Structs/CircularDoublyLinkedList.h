#include "../Objects/nodo.h"
using namespace std;


template <typename T>
class CircularDoublyLinkedList{
private:
    Nodo<T> *head;
    //Nodo<T> *current;
public:
    CircularDoublyLinkedList(/* args */);
    ~CircularDoublyLinkedList();

    void insert(T &value);
    void print();
};

template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(/* args */){
    head = nullptr;
}
template <typename T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList(){
    
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
}

template <typename T>
void CircularDoublyLinkedList<T>::print(){
    Nodo<T>* current = head;
    do{
        current->data.print();
        cout << "-------------------------------------------" << endl;
        current = current->next;
    }while(current != head);
}