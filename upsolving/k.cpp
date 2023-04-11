#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> d;
    bool reversed=true;
    int n;
    cin>>n;
    int command;
    int x;
    for(int i=0;i<n;i++){
        cin>>command;
        if(command==1){
            cin>>x;
            if(reversed){
                d.push_back(x);
            }else{
                d.push_front(x);
            }
        }else{
            if(reversed) reversed=false;
            else reversed=true;
        }
    }
    if(reversed){
        for(int i=0;i<d.size();i++){
            cout<<d[i]<<" ";
        }
    }else{
        for(int i=d.size()-1;i>=0;i--){
            cout<<d[i]<<" ";
        }
    }
}