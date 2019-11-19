struct Nodo *insertarAlArbol(int arr[],int tam, Nodo *root){
    
    for(int i=0;i<tam;i++){
        root=insert(arr[i]);
    }    
    return root;
}