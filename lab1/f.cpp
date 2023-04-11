#include <bits/stdc++.h> 
using namespace std; 

  bool isPrime(int numb)
  {
  int counter=0;
  for(int j=2; j<numb; j++){
    if(numb%j==0){
        counter=1;
          break;
    }
  }
  if(counter==0){
    return true;
  }
  else {
    return false;
  }

  
  }
int main(){ 
int n,num=1;
int count=0;
cin>>n;

while(true)
{
num++;
if(isPrime(num))
{
  count++;
}
if(count==n)
{
cout<<num;
break;
}
}
}