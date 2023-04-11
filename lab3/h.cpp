#include <bits/stdc++.h>
using namespace std;

int bs(int a[], int n, int target){
	int left = 0, right = n-1;
    int mid;
    int result = -1;

	while(left <= right){
		mid = (left + right) / 2;

		if(target <= a[mid]){
			result = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}

	return result;
}

int main(){
	vector <int> v;
	int n, m, val = 1;
	cin >> n >> m;

	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(i)
			a[i] += a[i-1];
	}

	for(int i=0; i<m; i++){
		int x;
		cin >> x;

		cout << bs(a, n, x) + 1 << '\n';
	}
}