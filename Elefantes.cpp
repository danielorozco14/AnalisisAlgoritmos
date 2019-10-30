#include<bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;


int LIS(int arr[],int lis[],int n){
	int maxi=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i] && lis[i] < lis[j]+1){
                lis[i]=lis[j]+1;
                if(lis[i]>maxi)
                maxi=lis[i];
            }
        }
    }

    return maxi;
}
int main(){

    vector< pair<int ,int> > v;
    int wt,iq;
    while(cin>>wt>>iq){
        v.push_back({wt,iq});
    }

    sort(v.begin(),v.end());
    int n=v.size();
    int arr[n],lis[n];
    for(int i=0;i<n;i++){
        arr[n-i-1]=v[i].second;
        lis[i]=1;
    }
    cout<<"arr[]=";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nLIS[]=";
    for(int i=0;i<n;i++){
        cout<<lis[i]<<" ";
    }
    cout<<endl<<LIS(arr,lis,n)<<endl;

}
