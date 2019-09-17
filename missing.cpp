#include <iostream>

using namespace std;

int partition (int arr[], int p, int r){
	int i, j, x, tmp;
	
	x = arr[r];
	i = p - 1;
	for (j = p; j < r; j++)	{
		if (arr[j] <= x){
			i++;
			
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	i++;
	tmp = arr[i];
	arr[i] = arr[r];
	arr[r] = tmp;
	
	return i;
}
 
void quicksort (int arr[], int p, int r){
	int q;
	
	if (p < r){
		q = partition (arr, p, r);
		quicksort (arr, p, q - 1);
		quicksort (arr, q + 1, r);
	}
}
 
int main (){
	int  t, n, p,data;
	
	cin>>t;
	for (int i = 0; i < t; i++){
		cin>>n;
		int arr [n];
		for (int j = 0; j < n; j++){
            		cin>>data;
			arr[j]=data;
		}
		quicksort(arr, 0, n - 1);
		
		p = 2;
		for (int x = 0; x < n; x++){
			if (arr[x] >= p){
				p += 2;
			}
		}
		
		cout<<p<<endl;
	}
	
	return 0;
}
