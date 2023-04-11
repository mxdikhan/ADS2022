#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;
bool bith;
int a, b;

void dfs(int v){
    if(v == b){
        bith = true;
        return;
    }
    visited[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(visited[to] == false){
            dfs(to);
        }
    }
}

int main(){
    int n, m;
    cin >> m >> n;
    g.resize(m);
    visited.resize(m);
    while(n--){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> a >> b;
    a--;
    b--;
    dfs(a);
    if(bith == false){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}