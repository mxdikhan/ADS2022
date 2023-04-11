#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > x;
vector<int> p;

int ds_get(int v) {
	if (v == p[v]) {
		return v;
	} else {
		return p[v] = ds_get(p[v]);
	}
}

void ds_unite(int a, int b) {
	a = ds_get(a);
	b = ds_get(b);
	if (a != b)
		p[a] = b;
}

int main() {

	int v, e;
	cin >> v >> e;
	p.resize(v);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		x.push_back({ a, b });
	}

	for (int i = 0; i < v; i++)
		p[i] = i;

	for (int i = 0; i < x.size(); i++) {
		int a = x[i].first;
		int b = x[i].second;
		ds_unite(a, b);
	}

	for (int i = 0; i < v; i++) { 
		unordered_set<int> s;
		for (int j = i + 1; j < v; j++) { 
			s.insert(p[j]); 
		}
		cout << s.size() << "\n";
	} 


	return 1;

}