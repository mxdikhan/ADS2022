#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n, ans = 0; cin >> k >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    unordered_map<int,int> m;
    for(int i=0;i < n;i++){
        if(m.find(k-a[i])!=m.end()){
            ans = a[i];
            break;
        }else{
            m[a[i]]=i;
        }
    }
    cout << min(ans, k - ans) << ' ' << max(ans, k - ans);
}