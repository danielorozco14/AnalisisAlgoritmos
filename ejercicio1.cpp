#include <iostream>
#include <stdlib.h>

using namespace std;


struct Nodo {
    int dato;
    Nodo *sig;
};

class Lista{
    public:
        Lista();
        void insertarInicio(int);
        void insertarFinal(int);
        void Ordenar();
        void mostrar();
    private:
        Nodo *pInicio;

};

Lista::Lista(){
    pInicio=nullptr;
}
void Lista::insertarInicio(int dato){
    Nodo *nuevo=new Nodo();
    nuevo->dato=dato;
    nuevo->sig=this->pInicio;
    this->pInicio=nuevo;
}
void Lista::insertarFinal(int dato){
    Nodo *nuevo = new Nodo();
    nuevo->dato=dato;

    Nodo *salto = this->pInicio;

    if(!this->pInicio){
        insertarInicio(dato);
    }
    else{
        while(salto->sig){
            salto=salto->sig;
        }
        salto->sig = nuevo;
        cout<<"Antes de nuevo->sig";
        nuevo->sig = nullptr;
        cout<<"\nDespues de nuevo->sig";
    }
}
void Lista::mostrar(){
    Nodo *salto = this->pInicio;
    while(salto){
        cout << salto->dato << " ";
        salto=salto->sig;
    }
    cout<<"\n";
}
int main(){

    Lista ls;

    ls.insertarFinal(1);
    ls.insertarFinal(2);
    ls.insertarFinal(3);
    ls.mostrar();

    return 0;
}