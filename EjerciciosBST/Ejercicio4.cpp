vector <int> Arbol_2;

void llenarVector(struct Nodo *root){
    if (root != NULL){
        //preorder(root);
        Arbol_2.push_back(root->key);
        Arbol_2.push_back(root->key2;

        llenarVector(root->left);
        llenarVector(root->right);
    }
}

struct Nodo *balance(vector <int> &Arbol, int inicio, int Final){
    if (inicio > Final)
        return NULL;
    int mid=(inicio + Final)/2;
    Nodo *root = nuevoNodo(Arbol[mid]);

    root->left= balance(Arbol,inicio,mid-1);
    root->right= balance(Arbol,mid+1,Final);

    return root;
}


struct Nodo *insertarAlArbol(int arr[],int tam, Nodo *root){
    
    for(int i=0;i<tam;i++){
        root=insert(root,arr[i]);
    }    
    return root;
}