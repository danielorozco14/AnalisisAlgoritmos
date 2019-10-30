#include<bits/stdc++.h> 
#include<iostream>

using namespace std; 

int lcs(string X, string Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
    int i, j;  
    int maximo=-1;

    for (i = 0; i <= m; i++){  
        for (j = 0; j <= n; j++){  
        if (i == 0 || j == 0)  //llena los casos triviales
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] =0;// max(L[i - 1][j], L[i][j - 1]);  
        }
        if(L[i][j] > maximo){
			maximo = L[i][j];
        }
    } 

    for(int i=0; i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
    return L[m][n-1];  
}  


int main()  
{  
    string X = "POKERTZB";  
    string Y = "AWPOKERWBARONES";  
      
    int m = X.length();  
    int n = Y.length();  
      
    cout<<"ans"<< lcs( X, Y, m, n )<<"\n";  
      
    return 0;  
}  