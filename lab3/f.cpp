#include <bits/stdc++.h>
using namespace std;

int bs(int a[], int n, int target){
	int left = 0,right = n - 1;
	int mid;
	int result = -1;

	while(left <= right){
		mid = left + (right - left)/ 2;

		if(target < a[mid]){
			result = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return result;
}

int ts(int a[], int pos){
	int sum = 0;
	for(int i=0; i<pos; i++)
		sum += a[i];
	return sum;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a + n);

	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		int target;
		cin >> target;

		if(target < a[0]){
			cout << 0 << ' ' << 0 << endl;
			continue;
		}
		if(target >= a[n-1]){
			cout << n << ' ' << ts(a, n) << endl;
			continue;
		}

		int cnt = bs(a, n, target);
		int sum = ts(a, cnt);
		cout << cnt << ' ' << sum << endl;
	} 
return 0; 
}