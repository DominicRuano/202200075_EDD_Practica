#include "../Objects/nodo.h"

template <class T>
class DoublyLinkedList{
private:
    Nodo<T> *head;
    int length = 0;
public:
    DoublyLinkedList(/* args */);
    ~DoublyLinkedList();

    void add(T &val);
    void Print();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(/* args */){
    head = nullptr;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    // Pendiente de implementar
}

template <class T>
void DoublyLinkedList<T>::add(T &val){
    Nodo<T> *NuevoNodo = new Nodo<T>(val);
    if (!head){
        head = NuevoNodo;
        head->next = head;
        head->prev = head;
    }
    else{
        Nodo<T> *current = head;
        while (current->data.getVuelo() > NuevoNodo->data.getVuelo())
            current = current->next;
        while ((current->data.getVuelo() == NuevoNodo->data.getVuelo())&&(current->data.getAsiento() > NuevoNodo->data.getAsiento()))
            current = current->next;
        current->prev->next = NuevoNodo;
        NuevoNodo->prev = current->prev;
        NuevoNodo->next = current;
        current->prev = NuevoNodo;
    }
}

template <class T>
void DoublyLinkedList<T>::Print(){
    if (!head)
        throw cout << "La lista esta vacia!" << endl;
    else {
        Nodo<T> *current = head;
        for (int i = 0; i < length; i++){
            current->data.print();
            cout << "----------------------------------" << endl;
            current = current->next;
        }
    }
}