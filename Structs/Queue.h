#include "../Objects/nodo.h"

template <class T>
class Queue{
private:
    Nodo<T> *head;
    int length = 0;
public:
    Queue();
    ~Queue();

    void enqueue(T &value); 
    T dequeue();
    int getLength(){return length;}
    void print();
};

template <class T>
Queue<T>::Queue(){
    head = nullptr;
}

template <class T>
Queue<T>::~Queue(){
    // Pendiente de implementar
}

template <class T>
void Queue<T>::enqueue(T &value){
    Nodo<T> *NuevoNodo = new Nodo<T>(value);
    if (!head){
        head = NuevoNodo;
    }else{
        Nodo<T> *current = head;
        while (current->next){
            current = current->next;
        }
        current->next = NuevoNodo;
    }
    length++;
}

template <class T>
T Queue<T>::dequeue(){
    if (!head)
        throw cout << "La cola esta vacia." << endl;
    T val = head->data;
    Nodo<T> *temp = head;
    head = head->next;
    delete temp;
    length --;
    return val;
}

template <class T>
void Queue<T>::print(){
    Nodo<T> *current = head;
    if (length > 0)
        for (int i = 0; i < length; i++){
            current->data.print();
            cout << "---------------------------" << endl;
            current = current->next;
        }
    else 
        cout << "La cola esta vacia!" << endl;
}