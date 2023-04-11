#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	map <string, string> m;
	while(n--){
		string old, newn;
		bool flag = false;
		cin >> old >> newn;
		for (auto i : m) {
			if (old == i.second) {
				m[i.first] = newn;
				flag = true;
				break;
			}
		}
		if (!flag) {
			m[old] = newn;
		}
	}
	cout << m.size() << '\n';
	for (auto i : m) {
		cout << i.first << " " << i.second << endl;
	}
}