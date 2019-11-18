bool bstValido(Nodo* root){  
    static Nodo *prev = NULL;  
    
    if (root){  
        if (!bstValido(root->left))  
        return false;  
  
        if (prev != NULL && root->data <= prev->data)  
            return false;  
  
        prev = root;  
  
        return bstValido(root->right);  
    }  
  
    return true;  
} 