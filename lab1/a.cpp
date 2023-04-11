#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a; 
    cin >> a;
    while(a--){
        int n; 
        cin >> n;
        deque<int> d;
        for(int i = n; i > 0; i--){
            d.push_back(i);
            for(int j = 0; j <= i; j++){
                int b = d.back();
                d.pop_back();
                d.push_front(b);
            }
        }
        while(!d.empty()){
            cout << d.front() << ' ';
            d.pop_front();
        }
        cout << '\n';
    }
}