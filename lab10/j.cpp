#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;
vector<vector<int>> g;
vector<int> parent, visited, child;

void helper(int v, int vis[]){
    vis[v] = 1;
    for(int i : g[v]){
        if(not vis[i])
            helper(i, vis);
    }
}

int numOfComp(){
    int vis[n+1];
    for(int i = 0; i < n + 1; i++){
        vis[i] = 0;
    }
    int cnt = 0;
    for(int i = 1; i < n+1; i++){
        if(not vis[i]){
            helper(i, vis);
            cnt++;
        }
    }

    return cnt;
}

void dfs(int u){
    visited[u] = 1;
    int cnt = 0;
    for(int i = 0; i < g[u].size(); i++){
        if(not visited[g[u][i]]){
            parent[g[u][i]] = u;
            cnt++;
            child[u] = cnt;
            dfs(g[u][i]);
        }
    }
}

int main(){
    while(1){
    cin >> n >> m;
    int u, v;
    int h;
    int root = INT_MAX;
    g.assign(n+1, vector<int>());
    visited.assign(n+1, 0);
    parent.assign(n+1, 0);
    child.assign(n+1, 0);
    while(m --){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n+1; i++){
        visited[i] = 0;
        parent[i] = 0;
        child[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        if(not visited[i])dfs(i);
    }

    int bigFam = 0;
    for(int i = 1; i <= n; i++){
        if(parent[i] and child[parent[i]] < child[i])bigFam++;
    }

    cout << numOfComp() + bigFam;

    return 0;
    return 0;
    }

}