#include <bits/stdc++.h>

using namespace std;

int main()
{
char b;
int n;
deque<int> d;
int sum;



    while(cin >> b){
        if(b=='!'){
            return 0;
        }
        else if(b=='+'){
            cin>>n;
            d.push_front(n);
        }
        else if(b=='-'){
            cin>>n;
            d.push_back(n);
        }
        else if(b=='*' ){
            if(d.empty()){
                cout<<"error"<<"\n";
            }
            else if(d.size() == 1){
                cout<< d.front()+d.back()<<"\n";
                d.pop_front();
            }
            else{
                cout<<d.front()+d.back()<<"\n";
                d.pop_front();
                d.pop_back();
            }
            
        }

    }
    return 0;
}