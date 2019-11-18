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