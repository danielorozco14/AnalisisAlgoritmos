#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct Nodo{
    int key;
    struct Nodo *left, *right;
};

vector <int> Arbol_1;
vector <int> Arbol_2;

vector<int>::iterator it;
// Estructura para crear nodos de un arbol.
struct Nodo *nuevoNodo(int item){
    struct Nodo *temp =  new Nodo;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Funcion para imprimir datos del arbol, en orden(izquierdo,root,derecho).
void inorder(struct Nodo *root){
    if (root != NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        //contArbol.push_back(root->key);
        inorder(root->right);
    }
}

//Funcion para imprimir datos del arbol, en preorder(root,izquierdo,derecho)
void preorder(struct Nodo *root){
    if (root != NULL){
        //preorder(root);
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
//Funcion para imprimir datos del arbol, en postorder(izquierdo,derecho,root)

void postorder(struct Nodo *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

/* Funcion para insertar un nuevo nodo al BST, dada una llave*/
struct Nodo* insert(struct Nodo* Nodo, int key){
    /* Si el arbol esta vacio, retorna un nuevo nodo*/
    if (Nodo == NULL) return nuevoNodo(key);

    /* De lo contrario, se recorre el arbol*/
    if (key <= Nodo->key)
        Nodo->left  = insert(Nodo->left, key);
    else
        Nodo->right = insert(Nodo->right, key);

    /* retorna el puntero del nodo (sin cambio)*/
    return Nodo;
}

//Retorna el nodo padre de cualquier hoja
int ancestro(struct Nodo*root,int a,int b){

    if(root!=NULL){
        if(a < root->key && b < root->key){
            return ancestro(root->left,a,b);
        }
        else if( a > root->key && b > root->key){
            return ancestro(root->right,a,b);
        }
    }
    return root->key;
}

int suma(struct Nodo * root,int n){

    if(root!=nullptr){
        if(n < root->key ){
            return 1 + suma(root->left,n);
        }
        else if( n > root->key ){
            return 1 + suma(root->right,n);
        }
        if(root->key == n)
            return 1;
    }
    return 0;
}
//FUNCION PARA OBTENER LA DISTANCIA ENTRE DOS NODOS
int distanciaEntreNodos(struct Nodo *root, int a, int b){

    if(root!=nullptr){

        if(a < root->key && b < root->key){
            return distanciaEntreNodos(root->left,a,b);
        }
        else if( a > root->key && b > root->key){
            return distanciaEntreNodos(root->right,a,b);
        }
    }
    return suma(root->left,a) + suma(root->right,b);
}
//FUNCION PARA MANTENER BALANCEADO EL ARBOL
struct Nodo *balance(vector <int> &contArbol, int inicio, int Final){
    if (inicio > Final)
        return NULL;
    int mid=(inicio + Final)/2;
    Nodo *root = nuevoNodo(contArbol[mid]);

    root->left= balance(contArbol,inicio,mid-1);
    root->right= balance(contArbol,mid+1,Final);

    return root;
}

/* Dado un arbol no vacio, retorna el nodo con el valor de llave minimo encontrado en ese arbol.
El arbol entero no necesita ser recorrido */
struct Nodo * minValueNode(struct Nodo* Nodo){
    struct Nodo* current = Nodo;

    /* Recorre el arbol hasta encontrar la hoja mas a la izquierda (el dato mas pequeño) */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Dado un BST y una llave, elimina la llave y retorna el nuevo root  */
struct Nodo* borrarNodo(struct Nodo* root, int key){
    // Caso base
    if (root == NULL) return root;
    // Si la llave a eliminar es mas pequeña que el root, entonces el valor esta en el sub arbol izquierdo
    if (key < root->key)
        root->left = borrarNodo(root->left, key);
    // Si la llave a eliminar es mas grande que el root, entonces el valor esta en el sub arbol derecho
    else if (key > root->key)
        root->right = borrarNodo(root->right, key);
    // Si la llave a eliminar es igual que el root, entonces el valor a eliminar es el root
    else{
        //Nodo con solamente un hijo, o ningun hijo
        if (root->left == NULL){
            struct Nodo *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct Nodo *temp = root->left;
            free(root);
            return temp;
        }
        // Nodo con dos hijos: Obtener el sucesor en orden (el mas pequeño en el sub arbol derecho)
        struct Nodo* temp = minValueNode(root->right);
        // Copiar el contenido del sucesor en orden a este nodo
        root->key = temp->key;
        // Eliminar el nodo sucesor
        root->right = borrarNodo(root->right, temp->key);
    }
    return root;
}

//FUNCION PARA BORRAR NODOS REPETIDOS

void llenarVector(struct Nodo *root){
    if (root != NULL){
        //preorder(root);
        Arbol_1.push_back(root->key);
        Arbol_1.push_back(root->key2;

        llenarVector(root->left);
        llenarVector(root->right);
    }
}

void borrarRepetidos(vector<int> &Arbol_1,int N,struct Nodo *root){
    llenarVector(root);    
    //BORRA TODAS LAS OCURRENCIAS DEL ARBOL
    Arbol_1.erase(remove(Arbol_1.begin(), Arbol_1.end(), N), Arbol_1.end());      
    Arbol_1.erase(remove(Arbol_1.begin(), Arbol_1.end(), N), Arbol_1.end());    2 

}

bool bstValido(Nodo* root){  
    static Nodo *prev = NULL;  
    //RECORRIDO EN INORDER
    if (root){  
        if (!bstValido(root->left))  
            return false;  
  
        if (prev != NULL && root->key <= prev->key)  
            return false;  
  
        prev = root;  
  
        return bstValido(root->right);  
    }  
  
    return true;  
} 

struct Nodo *insertarAlArbol(int arr[],int tam, Nodo *root){
    
    for(int i=0;i<tam;i++){
        root=insert(root,arr[i]);
    }    
    return root;
}


int main(){
    /* Creamos el siguiente arbol
              8
           /     \
          3      10
        /  \       \
       1    6      14
           /  \    /
          4    7  13
                  /
                 13 
    */
    struct Nodo *root = NULL, *root2=NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 13);
    root = insert(root, 13);
      
    postorder(root);
    cout<<endl;
    /*
     EJERCICIO 1
    */
    borrarRepetidos(Arbol_1,13,root);
    borrarRepetidos(Arbol_1,13,root2;

    root=balance(Arbol_1,0,Arbol_1.size()-1);
    root=balance(Arbol_1,0,Arbol_1.size()-12;

    postorder(root);
    cout<<endl;
    /*
     EJERCICIO 2
    */
    if(bstValido(root)){
       cout<<"Si es BST\n";
    }
    else{
       cout<<"No es BST\n";
    }

    /*
     EJERCICIO 3
    */   
    int arr[5]={1,5,6,3,7};
    root2=insertarAlArbol(arr,5,root2);
    inorder(root2);
    cout<<endl;

    return 0;
}
