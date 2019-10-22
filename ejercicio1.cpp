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
        void ordenarLista(Nodo*);
        void prueba();
        void cambiarLugar();
        void mostrar();
    //private:
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
        nuevo->sig = nullptr;
    }
}
void Lista::ordenarLista(Nodo *lista){
    Nodo *salto;
    Nodo *temp=nullptr;
    bool flag;
    do{        
        flag=false;
        salto=lista;
        while(salto->sig!=temp){
           if(salto->dato > salto->sig->dato){
                flag=true;
                int tmp=salto->dato;
                salto->dato=salto->sig->dato;
                salto->sig->dato=tmp;                 
            }            
            salto=salto->sig;
        }        
        temp=salto;
    }while(flag);
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
    Nodo *lista;
    ls.insertarFinal(3);
    ls.insertarFinal(2);
    ls.insertarFinal(1);
    ls.mostrar();
    cout<<"------\n";
    ls.ordenarLista(ls.pInicio);
    ls.mostrar();

    return 0;
}
