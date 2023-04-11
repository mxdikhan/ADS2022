#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;
vector<int> topsortVector;
vector<int> colors;

bool detectCycle(int v){
    colors[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(colors[u] == 1){
            return 1;
        }
        if(colors[u] == 0){
            if(detectCycle(u)){
                return 1;
            }
        }
    }
    colors[v] = 2;
    return 0;
}

void topsort(int v){
    visited[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(visited[u] == false){
            topsort(u);
        }
    }
    topsortVector.push_back(v);
}

int main(){
    int m, n;
    cin >> m >> n;
    colors.resize(m);
    g.resize(m);
    visited.resize(m);
    while(n--){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    bool hasCycle = false;
    for(int i = 0; i < m; i++){
        if(detectCycle(i) == true){
            hasCycle = true;
            break;
        }
    }
    if(hasCycle == false){
        cout << "Possible"<< '\n';
        for(int i = 0; i < m; i++){
            if(visited[i] == false){
                topsort(i);
            }
        }
        for(int i = topsortVector.size() - 1; i >= 0; i--){
            cout << topsortVector[i] + 1 << " ";
        }
    }
    else{
        cout<<"Impossible";
    }
    return 0;
}