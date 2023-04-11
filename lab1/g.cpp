#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n == 0) {
        return false;
    }
        if(n==1){
            return false;
        }
    for(int i = 2; i * i <=n; i++){
        if(n % i == 0) {
            return false;
        }
        
    

    }
    return true;
    
}
int main(){
    int n; 
    cin >> n;
    vector<int> a, b;
    a.push_back(0);
    for(int i = 0; i < 100000; i++){
        if(isPrime(i)){
            a.push_back(i);
        }
    }
    for(int i = 0; i < a.size(); i++){
        if(isPrime(i)){
            b.push_back(a[i]);
        }
    }
 
    cout << b[n-1];
}