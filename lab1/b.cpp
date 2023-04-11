#include <bits/stdc++.h>
using namespace std;

int main()
{

int n;
cin>>n;
int a[n];
stack<int> st;
for (int i = 0; i < n; i++) {
    cin >> a[i]; 
  }  

for(int i = 0; i < n; i++) {
   if(!st.empty()){
    while(!st.empty() && st.top() > a[i])    {
     st.pop();
    }
    }

    if(st.empty()){
        cout<<"-1";

    }

    else{
        cout<<st.top();
    }

    cout<<" ";
    st.push(a[i]);
   
}

return 0;
}