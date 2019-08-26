#include <iostream>
using namespace std;


struct Nodo
{
    int dato;
    Nodo *sig;
};


class Lista
{
    private:
        Nodo *pInicio;
    public:
        Lista();
        void insertarInicio(int);
        void insertarFinal(int);
        double media();
        void mostrar();
        void mostrarR(Nodo *);
        void eliminar(int);
        int contarMultiplo(int);
        void eliminarMultiplos(int);

};

Lista::Lista()
{
    pInicio = NULL;
}


void Lista::insertarInicio(int dato)
{
    Nodo *nuevo = new Nodo();
    nuevo->dato=dato;

    nuevo->sig=this->pInicio;
    this->pInicio=nuevo;
}

void Lista::mostrar()
{
    /*Nodo *salto = this->pInicio;
    while(salto)
    {
        cout << salto->dato << " ";
        salto=salto->sig;
    }*/
    mostrarR(this->pInicio);
}

void Lista::mostrarR(Nodo *nodo)
{
    if(nodo)
    {
        cout << nodo->dato << " ";
        mostrarR(nodo->sig); 
    }
}

void Lista::insertarFinal(int dato)
{
    Nodo *nuevo = new Nodo();
    nuevo->dato=dato;

    Nodo *salto = this->pInicio;

    if(!this->pInicio)
    {
        insertarInicio(dato);
    }
    else{
        while(salto->sig)
        {
            salto=salto->sig;
        }
        salto->sig = nuevo;
        nuevo->sig = NULL;
    }
}

double Lista::media()
{
    Nodo *salto = this->pInicio;
    int cont=0, sum=0;
    while(salto)
    {
        sum = sum + salto->dato;
        cont++;
        salto = salto->sig;
    }
    return sum/cont;
}

void Lista::eliminar(int n)
{
    Nodo *ant = NULL, *salto =this->pInicio;
    if(this->pInicio->dato % n == 0)
    {
        this->pInicio = salto->sig;
        salto->sig=NULL;
        delete(salto);
    }
    else
    {
        while(salto && (salto->dato % n)!=0){
            ant = salto;
            salto=salto->sig;
        } 
        if(salto)
        {
            ant->sig =salto->sig;
            salto->sig = NULL;
            delete(salto);
        }
    }
}

int Lista::contarMultiplo(int n)
{
    Nodo *salto = this->pInicio;
    int cont=0;
    while(salto)
    {
        if(salto->dato % n == 0)
        {
            cont++;
        }
        salto = salto->sig;
    }
    return cont;
}


void Lista::eliminarMultiplos(int n)
{
    int numMultiplos = contarMultiplo(n);
    cout << numMultiplos << endl;
    if(numMultiplos ==0)
    {
        cout << "No hay multiplos" << endl;
        mostrar();
    }
    else{
        for(int i=0 ; i<numMultiplos ; i++ )
        {
            eliminar(n);
        }
        //mostrar();
    }
}

int main()
{
    Lista l;
    int num = 10;
   for(int i=0 ; i<10 ; i++)
   {
       l.insertarFinal(i+1);
   }

    l.eliminarMultiplos(2);
    //l.eliminar(3);
    l.mostrar();
    return 0;
}