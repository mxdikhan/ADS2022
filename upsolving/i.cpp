#include <bits/stdc++.h>
using namespace std;

void ans(long long n){
    string s = "";
    stack <char> st;
    while(n > 0){
        s += (n % 2 + '0');
        n /= 2;
    }
    for(int i = 0; i < s.size(); i++){
        if(!st.empty() && st.top() == '0' && s[i] == '1'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    long long n;
    cin >> n;
    while(n--){
        long long num;
        cin >> num;
        ans(num);
    }
}