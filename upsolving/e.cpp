#include <bits/stdc++.h>
using namespace std;

class Stack{
    stack <int> duplicate;
    stack <int> st;

public:
    void add(int n){
        st.push(n);
        if(st.size() == 1){
            duplicate.push(n);
            return;
        }
        if(n > duplicate.top()){
            duplicate.push(n);
        }
        else{
            duplicate.push(duplicate.top());
        }
    }
    void getcur(){
        if(!st.empty()){
            cout << st.top() << "\n";
        }
        else{
            cout << "error\n";
        }
    }
    void getmax(){
        if(!duplicate.empty()){
            cout << duplicate.top() << "\n";
        }
        else{
            cout << "error\n";
        }
    }
    void del(){
        st.pop();
        duplicate.pop();
    }
};

int main(){
    int n, k;
    cin >> n;
    string s;
    Stack st;
    while(n--){
        cin >> s;
        if(s == "add"){
            cin >> k;
            st.add(k);
        }
        if(s == "delete"){
            st.del();
        }
        if(s == "getmax"){
            st.getmax();
        }
        if(s == "getcur"){
            st.getcur();
        }
    }
}