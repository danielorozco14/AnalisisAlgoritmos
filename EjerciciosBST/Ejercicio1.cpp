//FUNCION PARA BORRAR NODOS REPETIDOS

void llenarVector(struct Nodo *root){
    if (root != NULL){
        //preorder(root);
        Aux.push_back(root->key);
        llenarVector(root->left);
        llenarVector(root->right);
    }
}

void borrarRepetidos(vector<int> &Aux,int N,struct Nodo *root){
    llenarVector(root);    
    //BORRA TODAS LAS OCURRENCIAS DEL ARBOL
    Aux.erase(remove(Aux.begin(), Aux.end(), N), Aux.end());      
}