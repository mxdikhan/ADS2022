#include <bits/stdc++.h>

using namespace std;

int main(){
 int a,b;cin >> a >> b;
 vector<int> v;
 while(a != b){
  v.push_back(b);
  if(a > b){
   b++;
  }
  else if(b & 1){
   b++;
  }
  else{
   b/=2;
  }
 }
 cout << v.size() << '\n';
 for(int i = v.size()-1; i >= 0; i--){
  cout << v[i] << " ";
 }

}