#include<bits/stdc++.h>
using namespace std;

queue <int> q;
int pong(int k){
    q.push(k);
    while(q.front() < k - 3000){
        q.pop();
    }
    return q.size();
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        cout << pong(num)<<" ";
    }
}