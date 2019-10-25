#include <iostream>

using namespace std;


int activity(int inicio[],int final[],int L[]){
  int n=11;//Tamaño del arreglo
  
  for(int i=0; i<n;i++){
    for(int j=0; j<i; j++){
      if(final[j]<inicio[i] && L[i]<L[j]){
        L[i]=L[j];
      }
    }
    L[i]++;
  }
  
  return L[n-1];

}


int main(){
  int inicio[11]={0,1,2,3,3,5,5,6,8,8,12};
  int final [11]={6,4,13,5,8,7,9,10,11,12,14};
  int L [11]={0,0,0,0,0,0,0,0,0,0,0};
  cout<<activity(inicio,final,L); 
  
  return 0;
}
