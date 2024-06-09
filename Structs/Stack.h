#include "../Objects/nodo.h"

template <class T>
class Stack{
private:
    Nodo<T> *Top;
    int length = 0;
public:
    Stack(/* args */);
    ~Stack();

    void push(T &value);
    T pop();
    int getLength(){return length;}
    void Print();
};

template <class T>
Stack<T>::Stack(/* args */){
    Top = nullptr;
}

template <class T>
Stack<T>::~Stack(){
    // Pendiente de implementar
}

template<class T>
void Stack<T>::push(T &value){
    Nodo<T> *NuevoNodo = new Nodo<T>(value);
    if (Top)
        Top = NuevoNodo;
    else{
        Nodo<T> *current = Top;
        Top = NuevoNodo;
        NuevoNodo->prev = current;
    }
}

template<class T>
T Stack<T>::pop(){
    if (!Top)
        throw cout << "La pila esta vacia!" << endl;
    T val = Top->data;
    Nodo<T> *Temp = Top;
    Top = Top->prev;
    delete Temp;
    length --;
    return val;
}

template<class T>
void Stack<T>::Print(){
    if (!Top)
        throw cout << "La pila esta vacia!" << endl;
    
    Nodo<T> *Current = Top;
    for (int i = 0; i < length; i++){
        Current->data.print();
        cout << "----------------------------------" << endl;
        Current = Current->prev;
    }
}