#include <bits/stdc++.h>
using namespace std;
int main(){
deque <int> Boris;
deque <int> Nursik;
int cnt=0;

for(int i=0;i<5;i++){
    int a;
    cin >> a;
    Boris.push_back(a);
}

for(int j=0;j<5;j++){
    int b; 
    cin >> b; 
    Nursik.push_back(b);
}

while(!Boris.empty() && !Nursik.empty() && cnt!=1000000){
        
    if(Boris.front()==0 && Nursik.front()==9){
        Boris.push_back(Boris.front());
        Boris.push_back(Nursik.front());
           cnt++;

    }
    else if(Nursik.front()==0 && Boris.front()==9){
        Nursik.push_back(Boris.front());
        Nursik.push_back(Nursik.front());
        cnt++;

    }
    else if(Boris.front() > Nursik.front()){
    
        Boris.push_back(Boris.front());
        Boris.push_back(Nursik.front());
        cnt++;

    }
    else if(Nursik.front()>Boris.front()){
        Nursik.push_back(Boris.front());
        Nursik.push_back(Nursik.front());
        cnt++;
    }
    Boris.pop_front();
    Nursik.pop_front();
    }
 if(Boris.empty()) {
    cout <<"Nursik" << " "<<cnt;
 }
else if(Nursik.empty()) {
cout <<"Boris"<< " " << cnt;
}
else{
     cout <<"blin nichya";

}
}
