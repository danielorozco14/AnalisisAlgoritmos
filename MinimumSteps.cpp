#include <iostream>

using namespace std;

int minimumSteps(int n){
    if(n==1)
        return 0;
    else if(n%2==0){
        return 1 + minimumSteps(n/2);
    }else if(n%3==0){
        return 1 + minimumSteps(n/3);
    }else{
        return (n-1);
    }    
}

int main(){
    int n=12;
    cout<<minimumSteps(n)<<"\n";    
    return 0;
}