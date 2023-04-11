#include <bits/stdc++.h>

using namespace std;
const int N = 5001;
vector<int> g[N];
int color[N];
bool ok = false;
void addEdge(int x, int y){
    g[x].push_back(y);
    g[y].push_back(x);
}
void bfs(int v){
    vector<int> visited(N, 0);
    vector<int> dist(N, 0);
    queue<int> q;
    q.push(v);
    dist[v] = 0;
    visited[v] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(color[u] == 1){
            cout << dist[u] << '\n';
            return;
        }

        for(int h : g[u]){
            if(!visited[h]){
                visited[h] = 1;
                dist[h] = dist[u] + 1;
                q.push(h);
            }
        }
    }
 
cout << -1 << '\n';

}

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int x,y;cin >> x >> y;
        addEdge(x,y);
    }

    for(int i = 0; i < q; i++){
        int x,y;cin >> x >> y;
        if(x == 1){
            color[y] = 1;
            ok = true;
        }
        else{
               if(!ok){
                    cout << -1 << '\n';
               }else{
                    bfs(y);
               }
        }
    }


    return 0;

}