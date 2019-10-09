#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n=3;
int f1[3];
int f2[3];
string r1;
string r2;

int fastestWay(int a[2][3],int t[2][2],int e[2], int x[2]){
    f1[0]=e[0]+a[0][0];
    f2[0]=e[1]+a[1][0];
    for (int j=1;j<n;j++){
        if ((f1[j-1]+a[0][j]) <= (f2[j-1]+t[1][j-1] + a[0][j])){
            f1[j]=f1[j-1]+a[0][j];
            stringstream s;
            s<<j;
            string str =s.str();
            r1=r1+",a1"+str;

        }else{
            f1[j]=f2[j-1]+t[1][j-1]+a[0][j];
            stringstream ss;
            ss<<j-1;
            string str =ss.str();
            r1=r1+",a2"+str+",t2"+str;
        }
        if((f2[j-1]+a[1][j]) <= (f1[j-1]+t[0][j-1]+a[1][j])){
            f2[j]=f2[j-1]+a[1][j];
            stringstream s;
            s<<j;
            string str =s.str();
            r2=r2+",a2"+str;
        }else{
            f2[j]=f1[j-1]+t[0][j-1]+a[1][j];
            stringstream ss;
            ss<<j-1;
            string str =ss.str();
            r2=r2+",a1"+str+",t1"+str;
        }
    }
    cout<<"Respuesta 1: "<<r1<<endl;
    cout<<"Respuesta 2: "<<r2<<endl;
    cout<<"Costo: ";
    return min(f1[n-1]+x[0],f2[n-1]+x[1]);

}


int main(){
    int a [2][3]={{3,2,4},
                  {4,2,5}};
    int t[2][2]={{3,3},
                {2,4}};

    int e [2]={2,3};
    int x [2]={1,2};

    cout<<fastestWay(a,t,e,x)<<"\n";
    
    return 0;
}
