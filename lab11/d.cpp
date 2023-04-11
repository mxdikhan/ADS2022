#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > x;
vector<bool> visited;
vector<int> p, mine;
int ans = 0;
const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	x.resize(n);
	for (int i = 0; i < n; i++) {
		x[i].resize(n);
	}
	visited.resize(n);
	p.assign(n, -1);
	mine.assign(n, INF);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x[i][j];
		}
	}
	mine[0] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && (v == -1 || mine[j] < mine[v])) {
				v = j;
			}
		}

		visited[v] = true;
		if (p[v] != -1) {
			ans += x[v][p[v]];
		}
		for (int j = 0; j < n; j++) {
			if (x[v][j] < mine[j]) {
				mine[j] = x[v][j];
				p[j] = v;
			}
		}
	}
	cout << ans;
	return 0;
}