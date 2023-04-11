#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m, cnt = 0, div = 2;
    cin >> n;
    while(n > 1){
        if(n % div == 0){
            if(div != m){
                cnt++;
            }
            m = div;
            n /= div;
        }
        else{
            div++;
        }
    }
    cout << cnt;
}