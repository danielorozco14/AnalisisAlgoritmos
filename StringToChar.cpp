#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    
    string s="Hello World!";

    char cstr[s.size()+1];
    
    copy(s.begin(),s.end(),cstr);
    
    cstr[s.size()]='\0';
    
    cout<<cstr<<"\n";
    
    return 0;
}