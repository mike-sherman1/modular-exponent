#include <iostream>
#include <vector>

using namespace std;

vector<int> binaryK(int k)
{
	vector<int> K; 
	int tmp = k;
	int i = 0;
	while (tmp > 0)
	{
		K.push_back(tmp % 2);
		tmp = (tmp - K[i]) / 2;
		i++;
	}
	return K;
}

int modularExpo(int a, vector<int> K, int n, int k)
{
	if (n == 1)
		return 0;
	int b = 1;
	if (k == 0)
		return b;
	int A = a;
	if (K[0] == 1)
		b = a;
	for (int i = 1; i <= K.size() - 1; i++)
	{
		A = A*A % n;
		if (K[i] == 1)
			b = A*b % n;
	}
	return b;
}

int main()
{
	int a, k, n;
	vector<int> K;
	
	cout << "Enter value for a: ";
	cin >> a;
	cout << "Enter value for k: ";
	cin >> k;
	cout << "Enter value for n: ";
	cin >> n;
	
	K = binaryK(k);
	cout << a << "^" << k << " mod " << n << " = " << modularExpo(a, K, n, k) << endl;

	return 0;
}