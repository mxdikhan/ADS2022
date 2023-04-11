#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 1; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j++){
            string x, y, z;
            x = s.substr(0, i);
            y = s.substr(i, j - i);
            z = s.substr(j, s.size() - j + 1);
            if(x == y){
                cnt++;
            }
        }
    }
    cout << cnt;
}