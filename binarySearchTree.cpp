#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>

using namespace std;

struct node{ 
    int key; 
    struct node *left, *right; 
}; 
  
// Estructura para crear nodos de un arbol.
struct node *nuevoNodo(int item){ 
    struct node *temp =  new node;
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Funcion para imprimir datos del arbol, en orden(izquierdo,root,derecho).
void inorder(struct node *root){ 
    if (root != NULL){ 
        inorder(root->left); 
        cout<<root->key<<" ";
        inorder(root->right); 
    } 
} 
//Funcion para imprimir datos del arbol, en preorder(root,izquierdo,derecho)
void preorder(struct node *root){ 
    if (root != NULL){ 
        //preorder(root); 
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right); 
    } 
} 
//Funcion para imprimir datos del arbol, en postorder(izquierdo,derecho,root)

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

/* Funcion para insertar un nuevo nodo al BST, dada una llave*/
struct node* insert(struct node* node, int key){ 
    /* Si el arbol esta vacio, retorna un nuevo nodo*/
    if (node == NULL) return nuevoNodo(key); 
  
    /* De lo contrario, se recorre el arbol*/
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
  
    /* retorna el puntero del nodo (sin cambio)*/
    return node; 
} 
  
/* Dado un arbol no vacio, retorna el nodo con el valor de llave minimo encontrado en ese arbol.
El arbol entero no necesita ser recorrido */
struct node * minValueNode(struct node* node){ 
    struct node* current = node; 
  
    /* Recorre el arbol hasta encontrar la hoja mas a la izquierda */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
/* Dado un BST y una llave, elimina la llave y retorna el nuevo root  */
struct node* deleteNode(struct node* root, int key){ 
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
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL){ 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        }   
        // Nodo con dos hijos: Obtener el sucesor en orden (el mas pequeño en el sub arbol derecho)
        struct node* temp = minValueNode(root->right);   
        // Copiar el contenido del sucesor en orden a este nodo
        root->key = temp->key;   
        // Eliminar el nodo sucesor
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
  

int main(){ 
    /* Creamos el siguiente arbol
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
    //root=insert (root,100);
    //root =insert (root,1);
  
    cout<<("En orden transversal del arbol dado: \n"); 
    inorder(root); 

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
    cout<<endl;
    return 0; 
} 
