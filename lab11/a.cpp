#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > g;
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

	int f, q, tcost = 0;
	cin >> f >> q;
	p.resize(f);
	while (q--) {
		int l, x, c;
		cin >> l >> x >> c;
		l--; x--;
		for (int i = l; i < x; i++) {
			for (int j = i + 1; j <= x; j++) {
				if (i != j) {
					g.push_back({ c, {i, j} });
				}
			}
		}
	}
	
	sort(g.begin(), g.end());

	for (int i = 0; i < f; ++i)
		p[i] = i;
	
	for (int i = 0; i < g.size(); ++i) {
		int u = g[i].second.first;
		int v = g[i].second.second;
		int cost = g[i].first;
		if (ds_get(u) != ds_get(v)) {
			tcost += cost;
			ds_unite(u, v);
		}
	}

	cout << tcost;


	return 0;
}