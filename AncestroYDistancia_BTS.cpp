#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>

using namespace std;

struct Nodo{ 
    int key; 
    struct Nodo *left, *right; 
}; 
  
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
    if (key < Nodo->key) 
        Nodo->left  = insert(Nodo->left, key); 
    else
        Nodo->right = insert(Nodo->right, key); 
  
    /* retorna el puntero del nodo (sin cambio)*/
    return Nodo; 
} 


int ancestro(struct Nodo*root,int a,int b){//Retorna el nodo padre de cualquier hoja
   
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

/* Dado un arbol no vacio, retorna el nodo con el valor de llave minimo encontrado en ese arbol.
El arbol entero no necesita ser recorrido */
struct Nodo * minValueNode(struct Nodo* Nodo){ 
    struct Nodo* current = Nodo; 
  
    /* Recorre el arbol hasta encontrar la hoja mas a la izquierda */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
/* Dado un BST y una llave, elimina la llave y retorna el nuevo root  */
struct Nodo* deleteNode(struct Nodo* root, int key){ 
    // Caso base
    if (root == NULL) return root;   
    // Si la llave a eliminar es mas pequeña que el root, entonces el valor esta en el sub arbol izquierdo    
    if (key < root->key) 
        root->left = deleteNode(root->left, key);   
    // Si la llave a eliminar es mas grande que el root, entonces el valor esta en el sub arbol derecho
    else if (key > root->key) 
        root->right = deleteNode(root->right, key);   
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
        root->right = deleteNode(root->right, temp->key); 
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
        */
    struct Nodo *root = NULL; 
    root = insert(root, 8); 
    root = insert(root, 3); 
    root = insert(root, 1); 
    root = insert(root, 6); 
    root = insert(root, 4); 
    root = insert(root, 7); 
    root = insert(root, 10); 
    root = insert(root, 14); 
    root = insert(root, 13); 
  
    cout<<distanciaEntreNodos(root,1,7)<<endl;
    
/*
cout<<("En orden transversal del arbol dado: \n"); 
    preorder(root); 
    cout<<"\nEn preorder:\n";
    preorder(root);

    cout<<"\nEn postorder:\n";
    postorder(root);

    cout<<"\nEn forma de preorder: \n";
    preorder(root);
  
    cout<<("\nEliminando 20:\n"); 
    root = deleteNode(root, 20); 
    cout<<("En orden transversal del arbol modificado \n"); 
    inorder(root); 
  
    cout<<("\nEliminando 30:\n"); 
    root = deleteNode(root, 30); 
    cout<<("En orden transversal del arbol modificado \n"); 
    inorder(root); 
  
    cout<<("\nEliminando 50:\n"); 
    root = deleteNode(root, 50); 
    cout<<("En orden transversal del arbol modificado \n"); 
    inorder(root); 
    cout<<endl;*/
    return 0; 
} 
