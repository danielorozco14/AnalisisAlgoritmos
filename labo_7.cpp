#include <iostream>
#include <string>
using namespace std;


int cortarCuerda(int precio[], int n)
{
	int T[n + 1];

	for (int i = 0; i <= n; i++)
		T[i] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			T[i] = max(T[i], precio[j - 1] + T[i - j]);
      cout<<T[i]<<endl;

	}
	return T[n];

}



int main()
{
	int precio [] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

	int n = 4;

	cout << cortarCuerda(precio, n);

	return 0;
}
