#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
    int sum = 0;
	cin >> n;
	int ar[n];
	int minim = 1e6;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		minim = min(minim, ar[i]);
		sum += ar[i];
	}
	sum -= minim;
	cout << (n - 1) * minim + sum;
	return 0;
}